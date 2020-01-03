EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ESP32 LoRa Water Level Meter"
Date "2020-01-03"
Rev ""
Comp "Holger Fleischmann"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 4200 2000 2    50   ~ 0
SPI_SS
Wire Wire Line
	3700 2000 4200 2000
Wire Wire Line
	3700 2100 4200 2100
Wire Wire Line
	3700 2200 4200 2200
Wire Wire Line
	3700 2300 4200 2300
Text Label 4200 2100 2    50   ~ 0
SPI_SCK
Text Label 4200 2200 2    50   ~ 0
SPI_MOSI
Text Label 4200 2300 2    50   ~ 0
SPI_MISO
Wire Wire Line
	1800 1800 1250 1800
Wire Wire Line
	1800 1700 1250 1700
Text Label 1250 1800 0    50   ~ 0
LORA_DIO0
Text Label 1250 1700 0    50   ~ 0
LORA_DIO1
Text GLabel 4000 2900 2    50   Input ~ 0
Vin
Wire Wire Line
	3700 2900 4000 2900
Wire Wire Line
	4000 3000 4000 3050
Wire Wire Line
	3700 3000 4000 3000
Wire Wire Line
	1800 2000 1250 2000
Wire Wire Line
	1800 2100 1250 2100
Text Label 1250 2000 0    50   ~ 0
OUT_PERI
Text Label 1250 2100 0    50   ~ 0
OUT_PUMP
Wire Wire Line
	3700 2600 4200 2600
Wire Wire Line
	3700 2500 4200 2500
Text Label 4200 2600 2    50   ~ 0
I2C_SDA
Text Label 4200 2500 2    50   ~ 0
I2C_SCL
Wire Wire Line
	5600 3800 6000 3800
Wire Wire Line
	6350 4500 6750 4500
Text Label 6350 4500 0    50   ~ 0
OUT_PERI
Wire Wire Line
	8100 3900 8100 3800
Connection ~ 8100 3800
Wire Wire Line
	6000 4500 6000 3800
Connection ~ 6000 3800
Wire Wire Line
	6000 3800 8100 3800
Text GLabel 9850 4300 2    50   Output ~ 0
Vperi
Text GLabel 9850 3800 2    50   Output ~ 0
Vin
Wire Wire Line
	7850 4650 7850 4700
Wire Wire Line
	7850 4350 7850 4300
Wire Wire Line
	7850 4300 8100 4300
Connection ~ 8100 4300
Wire Wire Line
	8100 4300 8350 4300
Wire Wire Line
	8350 4500 8350 4300
Connection ~ 8350 4300
Wire Wire Line
	8350 4300 8450 4300
Wire Wire Line
	7850 4700 8150 4700
Connection ~ 7850 4700
Wire Wire Line
	7850 4700 7850 4750
Text Label 8150 4700 2    50   ~ 0
Vbat
Wire Wire Line
	7850 5050 7850 5150
Wire Wire Line
	7850 5150 8350 5150
Wire Wire Line
	8350 4800 8350 5150
Wire Wire Line
	7850 5150 7350 5150
Wire Wire Line
	5600 3900 5600 5150
Connection ~ 7850 5150
Connection ~ 6000 5150
Wire Wire Line
	6000 5150 5600 5150
Wire Wire Line
	6000 4800 6000 5150
Wire Wire Line
	7350 4700 7350 5150
Connection ~ 7350 5150
Wire Wire Line
	7350 5150 6000 5150
Wire Wire Line
	8750 5150 9100 5150
Wire Wire Line
	8750 4600 8750 5150
Wire Wire Line
	8350 5150 8750 5150
Connection ~ 8350 5150
Connection ~ 8750 5150
Wire Wire Line
	9100 4800 9100 5150
Wire Wire Line
	9050 4300 9100 4300
Wire Wire Line
	9100 4500 9100 4300
Connection ~ 9100 4300
Wire Wire Line
	7350 4300 7350 4100
Wire Wire Line
	7350 4100 7500 4100
Wire Wire Line
	9100 4300 9650 4300
Wire Wire Line
	9650 4450 9650 4300
Connection ~ 9650 4300
Wire Wire Line
	9650 4300 9850 4300
Wire Wire Line
	9650 5050 9650 5150
Wire Wire Line
	9650 5150 9100 5150
Connection ~ 9100 5150
Wire Wire Line
	8100 3800 9850 3800
Wire Wire Line
	1200 4300 1700 4300
Text Label 1200 4300 0    50   ~ 0
OUT_PUMP
Wire Wire Line
	2000 4300 2100 4300
Wire Wire Line
	2100 4300 2100 4400
Connection ~ 2100 4300
Text GLabel 2300 3750 0    50   Input ~ 0
Vin
Wire Wire Line
	2300 3750 2400 3750
Connection ~ 2400 3750
Wire Wire Line
	2400 3750 2850 3750
Connection ~ 2850 3750
Wire Wire Line
	2850 3750 3300 3750
Wire Wire Line
	2100 4700 2100 4750
Wire Wire Line
	2400 4100 2400 4050
Wire Wire Line
	2400 4050 2850 4050
Wire Wire Line
	3300 4050 3300 3850
Connection ~ 2400 4050
Connection ~ 2850 4050
Wire Wire Line
	2850 4050 3300 4050
Wire Wire Line
	2100 4750 2400 4750
Wire Wire Line
	2400 4750 2400 4500
Wire Wire Line
	2400 4750 2400 4800
Connection ~ 2400 4750
Wire Wire Line
	4000 5550 4500 5550
Wire Wire Line
	4000 5650 4500 5650
Text Label 4500 5550 2    50   ~ 0
I2C_SCL
Text Label 4500 5650 2    50   ~ 0
I2C_SDA
Wire Wire Line
	3350 5450 3200 5450
Wire Wire Line
	3200 5450 3200 5500
Wire Wire Line
	1350 7250 1350 7150
Wire Wire Line
	1050 7150 1350 7150
Connection ~ 1350 7150
Wire Wire Line
	1350 7150 1350 7050
Wire Wire Line
	1650 6050 1650 5950
Wire Wire Line
	1650 5950 2350 5950
Wire Wire Line
	1650 7050 1650 7150
Wire Wire Line
	1650 7150 2350 7150
Wire Wire Line
	2350 6400 2350 5950
Connection ~ 2350 5950
Wire Wire Line
	2350 6700 2350 7150
Connection ~ 2350 7150
Wire Wire Line
	2350 5950 3350 5950
Wire Wire Line
	2700 7150 2700 6050
Wire Wire Line
	2700 6050 3350 6050
Wire Wire Line
	2350 7150 2700 7150
Wire Wire Line
	1950 5750 1950 6050
Wire Wire Line
	1800 5750 1950 5750
Wire Wire Line
	1500 5750 1350 5750
Connection ~ 1350 5750
Wire Wire Line
	1350 5750 1050 5750
Wire Wire Line
	1350 5750 1350 6050
Wire Wire Line
	1050 5750 1050 7150
Text GLabel 1850 5350 0    50   Input ~ 0
Vperi
Wire Wire Line
	1850 5350 1950 5350
Wire Wire Line
	1950 5750 1950 5350
Connection ~ 1950 5750
Connection ~ 1950 5350
Wire Wire Line
	1950 5350 3350 5350
Wire Wire Line
	3350 6150 2950 6150
Text Label 2950 6150 0    50   ~ 0
Vbat
Connection ~ 7150 1400
Wire Wire Line
	7150 1000 7150 1400
Connection ~ 6850 1400
Wire Wire Line
	6850 1000 6850 1400
Connection ~ 6850 1000
Wire Wire Line
	6700 1000 6850 1000
Wire Wire Line
	7650 2000 7650 1850
Wire Wire Line
	7350 2000 7650 2000
Wire Wire Line
	7150 1400 7150 1500
Wire Wire Line
	6850 1800 6850 1400
Wire Wire Line
	6950 2900 6950 3000
Text GLabel 6700 1000 0    50   Input ~ 0
Vperi
NoConn ~ 6350 2500
Text Label 5900 2300 0    50   ~ 0
SPI_SS
Text Label 5900 2200 0    50   ~ 0
SPI_MISO
Text Label 5900 2100 0    50   ~ 0
SPI_MOSI
Text Label 5900 2000 0    50   ~ 0
SPI_SCK
Text Label 7800 2700 2    50   ~ 0
LORA_DIO0
Text Label 7800 2600 2    50   ~ 0
LORA_DIO1
Wire Wire Line
	7350 2600 7800 2600
Wire Wire Line
	7350 2700 7800 2700
Wire Wire Line
	6350 2300 5900 2300
Wire Wire Line
	6350 2200 5900 2200
Wire Wire Line
	6350 2100 5900 2100
Wire Wire Line
	6350 2000 5900 2000
NoConn ~ 3350 6250
NoConn ~ 4000 5750
NoConn ~ 4000 5850
Wire Wire Line
	6750 2900 6750 3000
Wire Wire Line
	6750 3000 6850 3000
Connection ~ 6950 3000
Wire Wire Line
	6950 3000 6950 3100
Wire Wire Line
	6850 2900 6850 3000
Connection ~ 6850 3000
Wire Wire Line
	6850 3000 6950 3000
NoConn ~ 3700 1100
NoConn ~ 3700 1200
NoConn ~ 3700 1300
NoConn ~ 3700 1400
NoConn ~ 3700 1500
NoConn ~ 3700 1600
NoConn ~ 3700 1700
NoConn ~ 3700 1800
NoConn ~ 3700 1900
NoConn ~ 3700 2400
NoConn ~ 3700 2700
NoConn ~ 3700 2800
NoConn ~ 1800 3000
NoConn ~ 1800 2900
NoConn ~ 1800 2800
NoConn ~ 1800 2700
NoConn ~ 1800 2600
NoConn ~ 1800 2500
NoConn ~ 1800 2400
NoConn ~ 1800 2200
NoConn ~ 1800 1900
NoConn ~ 1800 1600
NoConn ~ 1800 1500
NoConn ~ 1800 1400
NoConn ~ 1800 1300
NoConn ~ 1800 1200
NoConn ~ 1800 1100
NoConn ~ 7350 2200
NoConn ~ 7350 2300
NoConn ~ 7350 2400
NoConn ~ 7350 2500
$Comp
L RF_Module:RFM95W-868S2 U1
U 1 1 5E0F2C8C
P 6850 2300
F 0 "U1" H 6700 2900 50  0000 C CNN
F 1 "RFM95W-868S2" H 6450 2800 50  0000 C CNN
F 2 "" H 3550 3950 50  0001 C CNN
F 3 "https://www.hoperf.com/data/upload/portal/20181127/5bfcbea20e9ef.pdf" H 3550 3950 50  0001 C CNN
	1    6850 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5E10138B
P 6950 3100
F 0 "#PWR02" H 6950 2850 50  0001 C CNN
F 1 "GND" H 6955 2927 50  0000 C CNN
F 2 "" H 6950 3100 50  0001 C CNN
F 3 "" H 6950 3100 50  0001 C CNN
	1    6950 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E1020DF
P 7000 1400
F 0 "C2" V 6748 1400 50  0000 C CNN
F 1 "100n" V 6839 1400 50  0000 C CNN
F 2 "" H 7038 1250 50  0001 C CNN
F 3 "~" H 7000 1400 50  0001 C CNN
	1    7000 1400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E10311C
P 7150 1500
F 0 "#PWR01" H 7150 1250 50  0001 C CNN
F 1 "GND" H 7155 1327 50  0000 C CNN
F 2 "" H 7150 1500 50  0001 C CNN
F 3 "" H 7150 1500 50  0001 C CNN
	1    7150 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:Antenna AE1
U 1 1 5E10A9E2
P 7650 1650
F 0 "AE1" H 7730 1639 50  0000 L CNN
F 1 "Antenna" H 7730 1548 50  0000 L CNN
F 2 "" H 7650 1650 50  0001 C CNN
F 3 "~" H 7650 1650 50  0001 C CNN
	1    7650 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5E10C303
P 7000 1000
F 0 "C1" V 7255 1000 50  0000 C CNN
F 1 "47µ" V 7164 1000 50  0000 C CNN
F 2 "" H 7038 850 50  0001 C CNN
F 3 "~" H 7000 1000 50  0001 C CNN
	1    7000 1000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C8
U 1 1 5E1FA4C7
P 1650 5750
F 0 "C8" V 1398 5750 50  0000 C CNN
F 1 "1µ" V 1489 5750 50  0000 C CNN
F 2 "" H 1688 5600 50  0001 C CNN
F 3 "~" H 1650 5750 50  0001 C CNN
	1    1650 5750
	0    1    1    0   
$EndComp
$Comp
L Device:C C9
U 1 1 5E1E909D
P 2350 6550
F 0 "C9" H 2465 6596 50  0000 L CNN
F 1 "1µ" H 2465 6505 50  0000 L CNN
F 2 "" H 2388 6400 50  0001 C CNN
F 3 "~" H 2350 6550 50  0001 C CNN
	1    2350 6550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E1DEB11
P 1350 7250
F 0 "#PWR08" H 1350 7000 50  0001 C CNN
F 1 "GND" H 1355 7077 50  0000 C CNN
F 2 "" H 1350 7250 50  0001 C CNN
F 3 "" H 1350 7250 50  0001 C CNN
	1    1350 7250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5E1D9E52
P 3200 5500
F 0 "#PWR07" H 3200 5250 50  0001 C CNN
F 1 "GND" H 3205 5327 50  0000 C CNN
F 2 "" H 3200 5500 50  0001 C CNN
F 3 "" H 3200 5500 50  0001 C CNN
	1    3200 5500
	1    0    0    -1  
$EndComp
$Comp
L dev-boards:Pressure_R_Bridge U6
U 1 1 5E1D5EBB
P 1650 5700
F 0 "U6" H 2150 5200 50  0000 L CNN
F 1 "Pressure Bridge 4x5k" H 1250 4850 50  0000 L CNN
F 2 "" V 2300 4850 50  0001 C CNN
F 3 "" V 2300 4850 50  0001 C CNN
	1    1650 5700
	1    0    0    -1  
$EndComp
$Comp
L dev-boards:ADS1115_ADC_Module U5
U 1 1 5E1906B9
P 3350 5200
F 0 "U5" H 3675 5315 50  0000 C CNN
F 1 "ADS1115_ADC_Module" H 3675 5224 50  0000 C CNN
F 2 "" H 3650 5350 50  0001 C CNN
F 3 "" H 3650 5350 50  0001 C CNN
	1    3350 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5E174229
P 2850 3900
F 0 "C4" H 2965 3946 50  0000 L CNN
F 1 "100n" H 2965 3855 50  0000 L CNN
F 2 "" H 2888 3750 50  0001 C CNN
F 3 "~" H 2850 3900 50  0001 C CNN
	1    2850 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:D D2
U 1 1 5E1731A7
P 2400 3900
F 0 "D2" V 2354 3979 50  0000 L CNN
F 1 "SR106" V 2445 3979 50  0000 L CNN
F 2 "" H 2400 3900 50  0001 C CNN
F 3 "~" H 2400 3900 50  0001 C CNN
	1    2400 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5E16F083
P 2400 4800
F 0 "#PWR05" H 2400 4550 50  0001 C CNN
F 1 "GND" H 2405 4627 50  0000 C CNN
F 2 "" H 2400 4800 50  0001 C CNN
F 3 "" H 2400 4800 50  0001 C CNN
	1    2400 4800
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC337 Q3
U 1 1 5E16E72A
P 2300 4300
F 0 "Q3" H 2490 4346 50  0000 L CNN
F 1 "BC337-40" H 2490 4255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2500 4225 50  0001 L CIN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bc337.pdf" H 2300 4300 50  0001 L CNN
	1    2300 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5E16C697
P 2100 4550
F 0 "R6" H 2170 4596 50  0000 L CNN
F 1 "47k" H 2170 4505 50  0000 L CNN
F 2 "" V 2030 4550 50  0001 C CNN
F 3 "~" H 2100 4550 50  0001 C CNN
	1    2100 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E16BF06
P 1850 4300
F 0 "R3" V 1643 4300 50  0000 C CNN
F 1 "1k" V 1734 4300 50  0000 C CNN
F 2 "" V 1780 4300 50  0001 C CNN
F 3 "~" H 1850 4300 50  0001 C CNN
	1    1850 4300
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E168A3D
P 3500 3750
F 0 "J2" H 3472 3724 50  0000 R CNN
F 1 "Pump+Valve" H 3472 3633 50  0000 R CNN
F 2 "" H 3500 3750 50  0001 C CNN
F 3 "~" H 3500 3750 50  0001 C CNN
	1    3500 3750
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5E164226
P 9650 4600
F 0 "R7" H 9720 4646 50  0000 L CNN
F 1 "330" H 9720 4555 50  0000 L CNN
F 2 "" V 9580 4600 50  0001 C CNN
F 3 "~" H 9650 4600 50  0001 C CNN
	1    9650 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5E162DA3
P 9650 4900
F 0 "D3" V 9689 4783 50  0000 R CNN
F 1 "LED" V 9598 4783 50  0000 R CNN
F 2 "" H 9650 4900 50  0001 C CNN
F 3 "~" H 9650 4900 50  0001 C CNN
	1    9650 4900
	0    -1   -1   0   
$EndComp
$Comp
L Regulator_Linear:MCP1700-3302E_TO92 U4
U 1 1 5E12F21A
P 8750 4300
F 0 "U4" H 8850 4050 50  0000 C CNN
F 1 "MCP1700-3302E" H 8900 4150 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8750 4100 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001826D.pdf" H 8750 4300 50  0001 C CNN
	1    8750 4300
	1    0    0    1   
$EndComp
$Comp
L Device:R R8
U 1 1 5E140D20
P 7850 4900
F 0 "R8" H 7920 4946 50  0000 L CNN
F 1 "6.8k" H 7920 4855 50  0000 L CNN
F 2 "" V 7780 4900 50  0001 C CNN
F 3 "~" H 7850 4900 50  0001 C CNN
	1    7850 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5E140282
P 7850 4500
F 0 "R5" H 7920 4546 50  0000 L CNN
F 1 "33k" H 7920 4455 50  0000 L CNN
F 2 "" V 7780 4500 50  0001 C CNN
F 3 "~" H 7850 4500 50  0001 C CNN
	1    7850 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5E135FBF
P 8350 4650
F 0 "C6" H 8465 4696 50  0000 L CNN
F 1 "1µ" H 8465 4605 50  0000 L CNN
F 2 "" H 8388 4500 50  0001 C CNN
F 3 "~" H 8350 4650 50  0001 C CNN
	1    8350 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C7
U 1 1 5E1369AC
P 9100 4650
F 0 "C7" H 9218 4696 50  0000 L CNN
F 1 "100µ" H 9218 4605 50  0000 L CNN
F 2 "" H 9138 4500 50  0001 C CNN
F 3 "~" H 9100 4650 50  0001 C CNN
	1    9100 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5E138CF0
P 6000 5150
F 0 "#PWR06" H 6000 4900 50  0001 C CNN
F 1 "GND" H 6005 4977 50  0000 C CNN
F 2 "" H 6000 5150 50  0001 C CNN
F 3 "" H 6000 5150 50  0001 C CNN
	1    6000 5150
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC557 Q2
U 1 1 5E128BF6
P 8000 4100
F 0 "Q2" H 8191 4054 50  0000 L CNN
F 1 "BC557C" H 8191 4145 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8200 4025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC557.pdf" H 8000 4100 50  0001 L CNN
	1    8000 4100
	1    0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5E1279C6
P 7650 4100
F 0 "R2" V 7443 4100 50  0000 C CNN
F 1 "1.5k" V 7534 4100 50  0000 C CNN
F 2 "" V 7580 4100 50  0001 C CNN
F 3 "~" H 7650 4100 50  0001 C CNN
	1    7650 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E124407
P 6900 4500
F 0 "R4" V 6693 4500 50  0000 C CNN
F 1 "10k" V 6784 4500 50  0000 C CNN
F 2 "" V 6830 4500 50  0001 C CNN
F 3 "~" H 6900 4500 50  0001 C CNN
	1    6900 4500
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:BC547 Q4
U 1 1 5E122F12
P 7250 4500
F 0 "Q4" H 7441 4546 50  0000 L CNN
F 1 "BC547C" H 7441 4455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7450 4425 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 7250 4500 50  0001 L CNN
	1    7250 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C5
U 1 1 5E122046
P 6000 4650
F 0 "C5" H 6118 4696 50  0000 L CNN
F 1 "470µ" H 6118 4605 50  0000 L CNN
F 2 "" H 6038 4500 50  0001 C CNN
F 3 "~" H 6000 4650 50  0001 C CNN
	1    6000 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 5E121814
P 5400 3800
F 0 "J3" H 5508 3981 50  0000 C CNN
F 1 "Vin/GND" H 5508 3890 50  0000 C CNN
F 2 "" H 5400 3800 50  0001 C CNN
F 3 "~" H 5400 3800 50  0001 C CNN
	1    5400 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5E106613
P 4000 3050
F 0 "#PWR03" H 4000 2800 50  0001 C CNN
F 1 "GND" H 4005 2877 50  0000 C CNN
F 2 "" H 4000 3050 50  0001 C CNN
F 3 "" H 4000 3050 50  0001 C CNN
	1    4000 3050
	1    0    0    -1  
$EndComp
$Comp
L dev-boards:EzSBC_ESP32-01 U2
U 1 1 5E0FBCE2
P 2750 2050
F 0 "U2" H 2350 3200 50  0000 C CNN
F 1 "EzSBC_ESP32-01" H 2900 3200 50  0000 C CNN
F 2 "" H 2750 2950 50  0001 C CNN
F 3 "http://www.ezsbc.com/index.php/productattachments/index/download?id=30" H 2750 3173 50  0001 C CNN
	1    2750 2050
	1    0    0    -1  
$EndComp
$EndSCHEMATC