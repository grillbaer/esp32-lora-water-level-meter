#include "config.h"
#include "credentials.h"
#include "lora.h"

#include "freertos/FreeRTOS.h"
#include "esp_event.h"
#include "nvs_flash.h"

#include "TheThingsNetwork.h"

static TheThingsNetwork ttn;

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

    // The below line can be commented after the first run as the data is saved in NVS
    ttn.provision(devEui, appEui, appKey);
    //ttn.startProvisioningTask();
}

static bool joined = false;

void sendMeasurement(double levelMeters)
{
    if (!joined)
    {
        Serial.println("Joining...");
        if (ttn.join())
        {
            Serial.println("Joined.");
            joined = true;
        }
        else
        {
            Serial.println("Join failed.");
            ttn.reset();
            joined = false;
        }
    }

    Serial.printf("LoRa transmitting %.3lf...\n", levelMeters);

    const int16_t millimeters = (int16_t)(levelMeters * 1000 + 0.5);
    uint8_t payload[2];
    payload[0] = millimeters >> 8;
    payload[1] = millimeters & 0xff;

    TTNResponseCode res = ttn.transmitMessage(payload, 2);
    Serial.println(res == kTTNSuccessfulTransmission ? "LoRa transmitted." : " LoRa transmission failed.");
}
