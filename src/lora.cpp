#include "config.h"
#include "credentials.h"
#include "lora.h"

#include "freertos/FreeRTOS.h"
#include "esp_event.h"
#include "nvs_flash.h"

#include "TheThingsNetwork.h"
#include "TTNSession.h"

static TheThingsNetwork ttn;

// The session must persist over deep sleep,
// it is required to avoid unnecessary joins
static RTC_DATA_ATTR TTNSession session;

void setupLora(void)
{
    esp_err_t err;
    // Initialize the GPIO ISR handler service
    err = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
    ESP_ERROR_CHECK(err);

    // Initialize the NVS (non-volatile storage) for saving and restoring the keys
    err = nvs_flash_init();
    ESP_ERROR_CHECK(err);

    // Initialize SPI bus to which the LoRa module is attached
    spi_bus_config_t spi_bus_config;
    spi_bus_config.miso_io_num = TTN_PIN_SPI_MISO;
    spi_bus_config.mosi_io_num = TTN_PIN_SPI_MOSI;
    spi_bus_config.sclk_io_num = TTN_PIN_SPI_SCLK;
    spi_bus_config.quadwp_io_num = -1;
    spi_bus_config.quadhd_io_num = -1;
    spi_bus_config.max_transfer_sz = 0;
    spi_bus_config.intr_flags = 0;
    err = spi_bus_initialize(TTN_SPI_HOST, &spi_bus_config, TTN_SPI_DMA_CHAN);
    ESP_ERROR_CHECK(err);

    // Configure the SX127x pins
    ttn.configurePins(TTN_SPI_HOST, TTN_PIN_NSS, TTN_PIN_RXTX, TTN_PIN_RST, TTN_PIN_DIO0, TTN_PIN_DIO1);

    if (!ttn.isProvisioned())
    {
        ttn.provision(devEui, appEui, appKey);
        //ttn.startProvisioningTask();
    }

    if (session.isValid())
    {
        Serial.println("Restoring TTN session:");
        session.print();
        session.writeToLMIC();
    }
    else
    {
        Serial.println("No valid TTN session found:");
        session.print();
    }
}

void sendMeasurement(double levelMeters, double batteryVoltage)
{
    if (!session.isValid())
    {
        Serial.println("Joining...");
        if (ttn.join())
        {
            Serial.println("Joined.");
            Serial.println("Storing TTN session:");
            session.readFromLMIC();
            session.print();
        }
        else
        {
            Serial.println("Join failed.");
            ttn.reset();
        }
    }

    Serial.printf("LoRa transmitting level=%.3lfm, battery=%.3lfV...\n", levelMeters, batteryVoltage);

    const int16_t level_mm = (int16_t)(levelMeters * 1000 + 0.5);
    const int16_t battery_mV = (int16_t)(batteryVoltage * 1000 + 0.5);
    uint8_t payload[4];
    payload[0] = level_mm >> 8;
    payload[1] = level_mm & 0xff;
    payload[2] = battery_mV >> 8;
    payload[3] = battery_mV & 0xff;

    TTNResponseCode res = ttn.transmitMessage(payload, sizeof(payload));
    Serial.println(res == kTTNSuccessfulTransmission ? "LoRa transmitted." : " LoRa transmission failed.");
    session.readSeqnoFromLMIC();
}
