![](https://github.com/grillbaer/esp32-lora-water-level-meter/workflows/build/badge.svg)
  
# Water Level Meter

Automated measurement of a well's water level with LoRa transmission, based on ESP32.

## Measurement Setup

A tube is fixed in the fountain with its end below the lowest expected water level. 
A pump blows air into the tube until it bubbles out of the lower end.
Then, the air pressure in the tube will be proportional to the forced-out water column height. 
The pump must be strong enough for the highest expected water level.

The idea for this principle is taken from this [discussion thread](https://www.mikrocontroller.net/topic/229838).

<img src="doc/measurement-setup.png">

A one-way valve may be used in the tube to avoid intrusion of dirt and to shorten the required pumping duration to prolong battery life. Then, its placement must ensure that there is no permanent pressure at the sensor which could cause damage over time and also prevents measuring the zero pressure. The pressure loss caused by this valve must be compensated in the calcuation, too.

Pump, valve and pressure sensor can be taken from a cheap blood pressure monitor. An ADS1115 16 bit ADC is used to measure the small sensor voltage of some millivolts. An ESP32 µC controls the measurement procedure and transmits the result.

## Measurement Procedure

1. Ensure that the water level in the tube had time to relax while the pump was off and the valve open.
2. Read the zero level pressure.
3. Close valve, start pump and measure repeatedly until the pressure stops increasing. This means that the tube is now completely filled with air... or the pump was not strong enough:-)
4. The result level above the lower end of the tube is the difference between these two pressures, converted into water column height. Depending on the length and diameter of the tube, it may need some minor offset correction to compensate for the pressure loss of the flowing air.
5. Stop pump, open valve.

## LoRaWAN / TTN

LoRa module: HopeRF RFM95W, SX1276 compatible, and helix antenna for 868 MHz

Front / Back horizontally flipped over:

<img src="doc/lora-rf95w-front.jpg" width=300> <img src="doc/lora-rf95w-back.jpg" width=300>

Library: [ttn-esp32](https://github.com/manuelbl/ttn-esp32) is really easy to use and should have fewer timing problems on ESP32 than Arduino LMIC, since it is based on ESP-IDF/FreeRTOS tasks. Although it needs ESP-IDF, it can still be used together with the Arduino libs because these are also based on ESP-IDF. A `lib_compat_mode = off` in `platform.ini` enables usage with framework `arduino`.

## Hardware

### First working prototype

<img src="doc/breadboard-prototype-1.jpg" width=600>

### Power Consumption

Current of measurement cycle, LoRa TTN join and transmission:

* Pump and value active: ~ 0.6 s &ndash; 2 s depending on water level
* LoRa transmission active: ~ 0.1 s
* Full active phase without TTN join (only necessary once): ~ 7 s 

<img src="doc/prototype-current.png" width=600>

## TODO

* Schematic
* PCB
* Details on used blood pressure monitor components
* Power management for maximum battery life
  * Select other ESP board without OLED and peripheral components?
    => see [esp32-power-consumption-test](https://github.com/grillbaer/esp32-power-consumption-test)
  * Go to light sleep or even deep sleep between measurements (can DevAddr and FrameCounter be held in NVS?)
  * The sensor is already on a separate power strand to decouple its voltage from the noisy µC
  * Power off the LoRa module? Is its voltage supply from ESP board sufficient?
  * Battery life estimation
    => see [battery-consumption.ods](doc/battery-consumption.ods)
* Images of components, installation, ...
