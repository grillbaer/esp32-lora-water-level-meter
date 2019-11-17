# esp32-lora-water-level-meter
Automated measurement of fountain water level with LoRa transmission based on ESP32

Measurement of a fountain's water level. Set-up:
* a tube with its end fixed in the fountain below the lowest expected water level
* pumping air into the tube until it bubbles out of its lower end
* the air pressure in the tube will then be proportional to the forced out water column height
* pump, valve and pressure sensor are taken from a cheap blood pressure monitor
* an ADS1115 analog-to-digital converter is used to measure the small sensor voltage

Measurement procedure:
* read the zero pressure while the tube is filled with water (pump off, valve open)
* start pump, measure repeatedly until pressure stops increasing - this means that the tube is now completely filled with air
* the finally measured level is the difference between these two preasures expressed as water column height (minus adjustment for the pressure loss in the tubing)
* stop pump, open valve

TODO
* LoRa transmission
* power management for battery operation
