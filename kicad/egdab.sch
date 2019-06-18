EESchema Schematic File Version 4
LIBS:egdab-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U?
U 1 1 5D0758F5
P 1600 2400
F 0 "U?" H 1600 811 50  0000 C CNN
F 1 "ATmega328P-AU" H 1600 720 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 1600 2400 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 1600 2400 50  0001 C CNN
	1    1600 2400
	1    0    0    -1  
$EndComp
Text GLabel 5300 3400 0    50   Input ~ 0
touch
$Comp
L Device:Microphone MK?
U 1 1 5D07D20C
P 5100 3650
F 0 "MK?" H 5230 3696 50  0000 L CNN
F 1 "Microphone" H 5230 3605 50  0000 L CNN
F 2 "" V 5100 3750 50  0001 C CNN
F 3 "~" V 5100 3750 50  0001 C CNN
	1    5100 3650
	0    1    1    0   
$EndComp
$Comp
L Display_Character:HDSP-A151 U?
U 1 1 5D994D6A
P 6900 -1200
F 0 "U?" H 6900 -533 50  0000 C CNN
F 1 "HDSP-A151" H 6900 -624 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 6900 -1750 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 6400 -650 50  0001 C CNN
	1    6900 -1200
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Temperature:LM35-D U?
U 1 1 5D06FEF8
P 8750 3800
F 0 "U?" H 8421 3846 50  0000 R CNN
F 1 "LM35-D" H 8421 3755 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8750 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm35.pdf" H 8750 3800 50  0001 C CNN
	1    8750 3800
	-1   0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT?
U 1 1 5D073589
P 2100 6500
F 0 "BT?" H 2218 6596 50  0000 L CNN
F 1 "Battery_Cell" H 2218 6505 50  0000 L CNN
F 2 "" V 2100 6560 50  0001 C CNN
F 3 "~" V 2100 6560 50  0001 C CNN
	1    2100 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 -900 6600 -900
Wire Wire Line
	6600 -1000 5950 -1000
Wire Wire Line
	6000 -1100 6600 -1100
Wire Wire Line
	6600 -1200 6050 -1200
Wire Wire Line
	6100 -1300 6600 -1300
Wire Wire Line
	6600 -1400 6150 -1400
Wire Wire Line
	6200 -1500 6600 -1500
Wire Wire Line
	6200 -4650 6200 -1500
Wire Wire Line
	6150 -4550 6150 -1400
Wire Wire Line
	6100 -4450 6100 -1300
Wire Wire Line
	6050 -4350 6050 -1200
Wire Wire Line
	6000 -4250 6000 -1100
Wire Wire Line
	5950 -4150 5950 -1000
Wire Wire Line
	5900 -4050 5900 -900
Wire Wire Line
	5850 -800 6600 -800
Wire Wire Line
	7700 -900 8400 -900
Wire Wire Line
	8400 -1000 7750 -1000
Wire Wire Line
	7800 -1100 8400 -1100
Wire Wire Line
	8400 -1200 7850 -1200
Wire Wire Line
	7900 -1300 8400 -1300
Wire Wire Line
	8400 -1400 7950 -1400
Wire Wire Line
	8000 -1500 8400 -1500
Wire Wire Line
	8000 -4650 8000 -1500
Wire Wire Line
	7950 -4550 7950 -1400
Wire Wire Line
	7900 -4450 7900 -1300
Wire Wire Line
	7850 -4350 7850 -1200
Wire Wire Line
	7800 -4250 7800 -1100
Wire Wire Line
	7750 -4150 7750 -1000
Wire Wire Line
	7700 -4050 7700 -900
Wire Wire Line
	7650 -800 8400 -800
$Comp
L Display_Character:HDSP-A151 U?
U 1 1 5D2A584C
P 8700 -1200
F 0 "U?" H 8700 -533 50  0000 C CNN
F 1 "HDSP-A151" H 8700 -624 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 8700 -1750 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 8200 -650 50  0001 C CNN
	1    8700 -1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 -4550 7950 -4550
Wire Wire Line
	6100 -4450 7900 -4450
Wire Wire Line
	6050 -4350 7850 -4350
Wire Wire Line
	6000 -4250 7800 -4250
Wire Wire Line
	5950 -4150 7750 -4150
Wire Wire Line
	5900 -4050 7700 -4050
Wire Wire Line
	5850 -3850 7650 -3850
$Comp
L power:+5V #PWR?
U 1 1 5D3B0597
P -2800 -5350
F 0 "#PWR?" H -2800 -5500 50  0001 C CNN
F 1 "+5V" H -2785 -5177 50  0000 C CNN
F 2 "" H -2800 -5350 50  0001 C CNN
F 3 "" H -2800 -5350 50  0001 C CNN
	1    -2800 -5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	-2800 -5350 -2800 -4850
$Comp
L power:GND #PWR?
U 1 1 5D3C038A
P -2800 -1900
F 0 "#PWR?" H -2800 -2150 50  0001 C CNN
F 1 "GND" H -2795 -2073 50  0000 C CNN
F 2 "" H -2800 -1900 50  0001 C CNN
F 3 "" H -2800 -1900 50  0001 C CNN
	1    -2800 -1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 -800 7200 -800
Wire Wire Line
	9200 -800 9000 -800
Wire Wire Line
	9000 -900 9200 -900
Wire Wire Line
	9200 -900 9200 -800
Wire Wire Line
	7200 -900 7400 -900
Wire Wire Line
	7400 -900 7400 -800
Connection ~ 5900 -4050
Connection ~ 5950 -4150
Connection ~ 6000 -4250
Connection ~ 6050 -4350
Connection ~ 6100 -4450
Connection ~ 6150 -4550
Connection ~ 6200 -4650
Wire Wire Line
	6200 -4650 8000 -4650
Wire Wire Line
	-950 -3650 9200 -3650
Connection ~ 9200 -900
Wire Wire Line
	-950 -3550 7400 -3550
Connection ~ 7400 -900
Text Notes 5750 2400 0    138  ~ 0
TODO\n\n- power conditioning capacitors\n- MAX7221 data connection\n- DAC data connection\n- header: spi, programmer, i2c?, dac, sensor
$Comp
L Device:R_POT RV?
U 1 1 5DD97FA9
P 5050 2850
F 0 "RV?" H 4981 2896 50  0000 R CNN
F 1 "R_POT" H 4981 2805 50  0000 R CNN
F 2 "" H 5050 2850 50  0001 C CNN
F 3 "~" H 5050 2850 50  0001 C CNN
	1    5050 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5DD98C3C
P 5050 4700
F 0 "RV?" H 4981 4746 50  0000 R CNN
F 1 "R_POT" H 4981 4655 50  0000 R CNN
F 2 "" H 5050 4700 50  0001 C CNN
F 3 "~" H 5050 4700 50  0001 C CNN
	1    5050 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5DDB2299
P 8500 4700
F 0 "RV?" H 8431 4746 50  0000 R CNN
F 1 "R_POT" H 8431 4655 50  0000 R CNN
F 2 "" H 8500 4700 50  0001 C CNN
F 3 "~" H 8500 4700 50  0001 C CNN
	1    8500 4700
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5DDB229F
P 8500 2950
F 0 "RV?" H 8431 2996 50  0000 R CNN
F 1 "R_POT" H 8431 2905 50  0000 R CNN
F 2 "" H 8500 2950 50  0001 C CNN
F 3 "~" H 8500 2950 50  0001 C CNN
	1    8500 2950
	-1   0    0    -1  
$EndComp
$Comp
L 74HC4316:74HC4316 U?
U 1 1 5DE2BF70
P 6850 3650
F 0 "U?" H 6850 4365 50  0000 C CNN
F 1 "74HC4316" H 6850 4274 50  0000 C CNN
F 2 "MODULE" H 6850 3650 50  0001 C CNN
F 3 "" H 6850 3650 50  0001 C CNN
	1    6850 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3800 8350 3800
Wire Wire Line
	5300 3400 6100 3400
Wire Wire Line
	6100 3500 5450 3500
Wire Wire Line
	5450 3500 5450 3650
Wire Wire Line
	5450 3650 5300 3650
Wire Wire Line
	5200 4700 5600 4700
Wire Wire Line
	5600 3600 6100 3600
Wire Wire Line
	5450 2850 5450 3300
Wire Wire Line
	5450 3300 6100 3300
Wire Wire Line
	5200 2850 5450 2850
Wire Wire Line
	5600 3600 5600 4700
Wire Wire Line
	8350 4700 8250 4700
Wire Wire Line
	8250 4700 8250 3900
Wire Wire Line
	8250 3900 7600 3900
Wire Wire Line
	7600 3700 8250 3700
Wire Wire Line
	8250 3700 8250 2950
Wire Wire Line
	8250 2950 8350 2950
$Comp
L Connector_Generic:Conn_02x10_Counter_Clockwise J?
U 1 1 5E13991C
P 5200 6450
F 0 "J?" H 5250 7067 50  0000 C CNN
F 1 "Conn_02x10_Counter_Clockwise" H 5250 6976 50  0000 C CNN
F 2 "" H 5200 6450 50  0001 C CNN
F 3 "~" H 5200 6450 50  0001 C CNN
	1    5200 6450
	1    0    0    -1  
$EndComp
Text GLabel 6350 4650 0    50   Input ~ 0
MULT_E
Text GLabel 6350 4850 0    50   Input ~ 0
MULT_1
Text GLabel 6350 5050 0    50   Input ~ 0
MULT_2
Text GLabel 6350 5250 0    50   Input ~ 0
MULT_3
Text GLabel 6350 5450 0    50   Input ~ 0
MULT_4
Text GLabel 3750 2950 2    50   Input ~ 0
MULT_E
Text GLabel 2800 2100 2    50   Input ~ 0
MULT_1
Text GLabel 2800 2200 2    50   Input ~ 0
MULT_2
Text GLabel 2800 2300 2    50   Input ~ 0
MULT_3
Text GLabel 2800 2400 2    50   Input ~ 0
MULT_4
Wire Wire Line
	2800 2100 2200 2100
Wire Wire Line
	2200 2200 2800 2200
Wire Wire Line
	2800 2300 2200 2300
Wire Wire Line
	2200 2400 2800 2400
$Comp
L Interface_Expansion:AS1115-BSST U?
U 1 1 5D451D3E
P -2800 -3650
F 0 "U?" H -2800 -2269 50  0000 C CNN
F 1 "AS1115-BSST" H -2800 -2360 50  0000 C CNN
F 2 "Package_SO:QSOP-24_3.9x8.7mm_P0.635mm" H -2800 -3650 50  0001 C CNN
F 3 "https://ams.com/documents/20143/36005/AS1115_DS000206_1-00.pdf/3d3e6d35-b184-1329-adf9-2d769eb2404f" H -2800 -3650 50  0001 C CNN
	1    -2800 -3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	-2800 -2450 -2800 -1900
Connection ~ 5850 -3850
Wire Wire Line
	5850 -3850 5850 -800
Wire Wire Line
	7650 -3850 7650 -800
Wire Wire Line
	7400 -3550 7400 -900
Wire Wire Line
	9200 -3650 9200 -900
$Comp
L Device:LED_RGB D?
U 1 1 5E6D21EF
P 4300 -1050
F 0 "D?" V 4346 -1380 50  0000 R CNN
F 1 "LED_RGB" V 4255 -1380 50  0000 R CNN
F 2 "" H 4300 -1100 50  0001 C CNN
F 3 "~" H 4300 -1100 50  0001 C CNN
	1    4300 -1050
	1    0    0    1   
$EndComp
$Comp
L Device:LED_RGB D?
U 1 1 5E7108CE
P 3900 -1050
F 0 "D?" V 3946 -1380 50  0000 R CNN
F 1 "LED_RGB" V 3855 -1380 50  0000 R CNN
F 2 "" H 3900 -1100 50  0001 C CNN
F 3 "~" H 3900 -1100 50  0001 C CNN
	1    3900 -1050
	1    0    0    1   
$EndComp
$Comp
L Device:LED_RGB D?
U 1 1 5E72EAEB
P 5100 -1050
F 0 "D?" V 5146 -1380 50  0000 R CNN
F 1 "LED_RGB" V 5055 -1380 50  0000 R CNN
F 2 "" H 5100 -1100 50  0001 C CNN
F 3 "~" H 5100 -1100 50  0001 C CNN
	1    5100 -1050
	1    0    0    1   
$EndComp
$Comp
L Device:LED_RGB D?
U 1 1 5E789449
P 4700 -1050
F 0 "D?" V 4746 -1380 50  0000 R CNN
F 1 "LED_RGB" V 4655 -1380 50  0000 R CNN
F 2 "" H 4700 -1100 50  0001 C CNN
F 3 "~" H 4700 -1100 50  0001 C CNN
	1    4700 -1050
	1    0    0    1   
$EndComp
$Comp
L Device:LED_RGB D?
U 1 1 5E7D3281
P 4300 -2100
F 0 "D?" V 4346 -2430 50  0000 R CNN
F 1 "LED_RGB" V 4255 -2430 50  0000 R CNN
F 2 "" H 4300 -2150 50  0001 C CNN
F 3 "~" H 4300 -2150 50  0001 C CNN
	1    4300 -2100
	1    0    0    1   
$EndComp
$Comp
L Device:LED_RGB D?
U 1 1 5E7D3287
P 3900 -2100
F 0 "D?" V 3946 -2430 50  0000 R CNN
F 1 "LED_RGB" V 3855 -2430 50  0000 R CNN
F 2 "" H 3900 -2150 50  0001 C CNN
F 3 "~" H 3900 -2150 50  0001 C CNN
	1    3900 -2100
	1    0    0    1   
$EndComp
Wire Wire Line
	5450 -850 5300 -850
Wire Wire Line
	5300 -1050 5450 -1050
Connection ~ 5450 -1050
Wire Wire Line
	5450 -1050 5450 -850
Wire Wire Line
	5300 -1250 5450 -1250
Connection ~ 5450 -1250
Wire Wire Line
	5450 -1250 5450 -1050
Wire Wire Line
	4500 -1900 5450 -1900
Connection ~ 5450 -1900
Wire Wire Line
	5450 -1900 5450 -1250
Wire Wire Line
	4500 -2100 5450 -2100
Connection ~ 5450 -2100
Wire Wire Line
	5450 -2100 5450 -1900
Wire Wire Line
	4500 -2300 5450 -2300
Wire Wire Line
	5450 -2300 5450 -2100
Wire Wire Line
	3700 -2300 3500 -2300
Wire Wire Line
	3500 -2300 3500 -3450
Wire Wire Line
	3500 -3450 -950 -3450
Wire Wire Line
	3700 -2100 3400 -2100
Wire Wire Line
	3400 -2100 3400 -3350
Wire Wire Line
	3400 -3350 -950 -3350
Wire Wire Line
	-950 -3250 3300 -3250
Wire Wire Line
	3300 -3250 3300 -1900
Wire Wire Line
	3300 -1900 3700 -1900
Wire Wire Line
	-950 -3150 3200 -3150
Wire Wire Line
	3200 -3150 3200 -1250
Wire Wire Line
	3200 -1250 3700 -1250
Wire Wire Line
	-950 -3050 3100 -3050
Wire Wire Line
	3100 -3050 3100 -1050
Wire Wire Line
	3100 -1050 3700 -1050
Wire Wire Line
	3700 -850 3000 -850
Wire Wire Line
	3000 -850 3000 -2950
Wire Wire Line
	3000 -2950 -950 -2950
$Comp
L Device:D D?
U 1 1 5EBFF0F7
P 3700 -3200
F 0 "D?" V 3746 -3279 50  0000 R CNN
F 1 "D" V 3655 -3279 50  0000 R CNN
F 2 "" H 3700 -3200 50  0001 C CNN
F 3 "~" H 3700 -3200 50  0001 C CNN
	1    3700 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5EC00CC0
P 3950 -3200
F 0 "D?" V 3996 -3279 50  0000 R CNN
F 1 "D" V 3905 -3279 50  0000 R CNN
F 2 "" H 3950 -3200 50  0001 C CNN
F 3 "~" H 3950 -3200 50  0001 C CNN
	1    3950 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5EC258C3
P 4200 -3200
F 0 "D?" V 4246 -3279 50  0000 R CNN
F 1 "D" V 4155 -3279 50  0000 R CNN
F 2 "" H 4200 -3200 50  0001 C CNN
F 3 "~" H 4200 -3200 50  0001 C CNN
	1    4200 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5EC4A3DB
P 4450 -3200
F 0 "D?" V 4496 -3279 50  0000 R CNN
F 1 "D" V 4405 -3279 50  0000 R CNN
F 2 "" H 4450 -3200 50  0001 C CNN
F 3 "~" H 4450 -3200 50  0001 C CNN
	1    4450 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5EC6F4F7
P 4700 -3200
F 0 "D?" V 4746 -3279 50  0000 R CNN
F 1 "D" V 4655 -3279 50  0000 R CNN
F 2 "" H 4700 -3200 50  0001 C CNN
F 3 "~" H 4700 -3200 50  0001 C CNN
	1    4700 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5ECB8BFC
P 4950 -3200
F 0 "D?" V 4996 -3279 50  0000 R CNN
F 1 "D" V 4905 -3279 50  0000 R CNN
F 2 "" H 4950 -3200 50  0001 C CNN
F 3 "~" H 4950 -3200 50  0001 C CNN
	1    4950 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5ECDD831
P 5200 -3200
F 0 "D?" V 5246 -3279 50  0000 R CNN
F 1 "D" V 5155 -3279 50  0000 R CNN
F 2 "" H 5200 -3200 50  0001 C CNN
F 3 "~" H 5200 -3200 50  0001 C CNN
	1    5200 -3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5ED0292A
P 5450 -3200
F 0 "D?" V 5496 -3279 50  0000 R CNN
F 1 "D" V 5405 -3279 50  0000 R CNN
F 2 "" H 5450 -3200 50  0001 C CNN
F 3 "~" H 5450 -3200 50  0001 C CNN
	1    5450 -3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	-950 -4550 1150 -4550
Wire Wire Line
	-950 -4150 750  -4150
Wire Wire Line
	-950 -4050 700  -4050
Wire Wire Line
	-950 -3850 650  -3850
Wire Wire Line
	-950 -4650 1200 -4650
Wire Wire Line
	3700 -3350 3700 -3850
Connection ~ 3700 -3850
Wire Wire Line
	3700 -3850 5850 -3850
Wire Wire Line
	3950 -3350 3950 -4050
Connection ~ 3950 -4050
Wire Wire Line
	3950 -4050 5900 -4050
Wire Wire Line
	4200 -3350 4200 -4150
Connection ~ 4200 -4150
Wire Wire Line
	4200 -4150 5950 -4150
Wire Wire Line
	4450 -3350 4450 -4250
Connection ~ 4450 -4250
Wire Wire Line
	4450 -4250 6000 -4250
Connection ~ 4700 -4350
Wire Wire Line
	4700 -4350 6050 -4350
Wire Wire Line
	4700 -4350 4700 -3350
Wire Wire Line
	4950 -3350 4950 -4450
Connection ~ 4950 -4450
Wire Wire Line
	4950 -4450 6100 -4450
Wire Wire Line
	5200 -3350 5200 -4550
Connection ~ 5200 -4550
Wire Wire Line
	5200 -4550 6150 -4550
Wire Wire Line
	5450 -3350 5450 -4650
Connection ~ 5450 -4650
Wire Wire Line
	5450 -4650 6200 -4650
Wire Wire Line
	3700 -3050 3700 -2900
Wire Wire Line
	5450 -2900 5450 -2300
Connection ~ 5450 -2300
Wire Wire Line
	5450 -3050 5450 -2900
Connection ~ 5450 -2900
Wire Wire Line
	5200 -3050 5200 -2900
Connection ~ 5200 -2900
Wire Wire Line
	5200 -2900 5450 -2900
Wire Wire Line
	4950 -3050 4950 -2900
Connection ~ 4950 -2900
Wire Wire Line
	4950 -2900 5200 -2900
Wire Wire Line
	4700 -3050 4700 -2900
Wire Wire Line
	3700 -2900 3950 -2900
Connection ~ 4700 -2900
Wire Wire Line
	4700 -2900 4950 -2900
Wire Wire Line
	4450 -3050 4450 -2900
Connection ~ 4450 -2900
Wire Wire Line
	4450 -2900 4700 -2900
Wire Wire Line
	4200 -3050 4200 -2900
Connection ~ 4200 -2900
Wire Wire Line
	4200 -2900 4450 -2900
Wire Wire Line
	3950 -3050 3950 -2900
Connection ~ 3950 -2900
Wire Wire Line
	3950 -2900 4200 -2900
$Comp
L Switch:SW_Push SW?
U 1 1 5F0FCC18
P 2100 -1000
F 0 "SW?" H 2100 -715 50  0000 C CNN
F 1 "SW_Push" H 2100 -806 50  0000 C CNN
F 2 "" H 2100 -800 50  0001 C CNN
F 3 "~" H 2100 -800 50  0001 C CNN
	1    2100 -1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x12 SW?
U 1 1 5F0FCC24
P 100 -1500
F 0 "SW?" H 100 -633 50  0000 C CNN
F 1 "SW_DIP_x12" H 100 -724 50  0000 C CNN
F 2 "" H 100 -1500 50  0001 C CNN
F 3 "~" H 100 -1500 50  0001 C CNN
	1    100  -1500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F0FCC30
P 2100 -2350
F 0 "SW?" H 2100 -2065 50  0000 C CNN
F 1 "SW_Push" H 2100 -2156 50  0000 C CNN
F 2 "" H 2100 -2150 50  0001 C CNN
F 3 "~" H 2100 -2150 50  0001 C CNN
	1    2100 -2350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F0FCC2A
P 2100 -1900
F 0 "SW?" H 2100 -1615 50  0000 C CNN
F 1 "SW_Push" H 2100 -1706 50  0000 C CNN
F 2 "" H 2100 -1700 50  0001 C CNN
F 3 "~" H 2100 -1700 50  0001 C CNN
	1    2100 -1900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F0FCC1E
P 2100 -1450
F 0 "SW?" H 2100 -1165 50  0000 C CNN
F 1 "SW_Push" H 2100 -1256 50  0000 C CNN
F 2 "" H 2100 -1250 50  0001 C CNN
F 3 "~" H 2100 -1250 50  0001 C CNN
	1    2100 -1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	-950 -2650 -600 -2650
Wire Wire Line
	-600 -1000 -200 -1000
Wire Wire Line
	-200 -1100 -600 -1100
Connection ~ -600 -1100
Wire Wire Line
	-600 -1100 -600 -1000
Wire Wire Line
	-200 -1200 -600 -1200
Connection ~ -600 -1200
Wire Wire Line
	-600 -1200 -600 -1100
Wire Wire Line
	-200 -1300 -600 -1300
Connection ~ -600 -1300
Wire Wire Line
	-600 -1300 -600 -1200
Wire Wire Line
	-200 -1400 -600 -1400
Connection ~ -600 -1400
Wire Wire Line
	-600 -1400 -600 -1300
Wire Wire Line
	-200 -1500 -600 -1500
Wire Wire Line
	-600 -2650 -600 -1700
Connection ~ -600 -1500
Wire Wire Line
	-600 -1500 -600 -1400
Wire Wire Line
	-200 -1600 -600 -1600
Connection ~ -600 -1600
Wire Wire Line
	-600 -1600 -600 -1500
Wire Wire Line
	-200 -1700 -600 -1700
Connection ~ -600 -1700
Wire Wire Line
	-600 -1700 -600 -1600
Wire Wire Line
	-200 -1800 -500 -1800
Wire Wire Line
	-500 -1800 -500 -1900
Wire Wire Line
	-200 -1900 -500 -1900
Connection ~ -500 -1900
Wire Wire Line
	-500 -1900 -500 -2000
Wire Wire Line
	-200 -2000 -500 -2000
Connection ~ -500 -2000
Wire Wire Line
	-500 -2000 -500 -2100
Wire Wire Line
	-200 -2100 -500 -2100
Connection ~ -500 -2100
Wire Wire Line
	-500 -2100 -500 -2750
Wire Wire Line
	1600 -2750 1600 -2350
Wire Wire Line
	1600 -1000 1900 -1000
Wire Wire Line
	-950 -2750 -500 -2750
Wire Wire Line
	1600 -1450 1900 -1450
Connection ~ 1600 -1450
Wire Wire Line
	1600 -1450 1600 -1000
Wire Wire Line
	1900 -1900 1600 -1900
Connection ~ 1600 -1900
Wire Wire Line
	1600 -1900 1600 -1450
Wire Wire Line
	1900 -2350 1600 -2350
Connection ~ 1600 -2350
Wire Wire Line
	1600 -2350 1600 -1900
Connection ~ -500 -2750
Wire Wire Line
	-500 -2750 1600 -2750
Wire Wire Line
	400  -2100 650  -2100
Wire Wire Line
	650  -2100 650  -3850
Connection ~ 650  -3850
Wire Wire Line
	650  -3850 850  -3850
Wire Wire Line
	400  -2000 700  -2000
Wire Wire Line
	700  -2000 700  -4050
Connection ~ 700  -4050
Wire Wire Line
	700  -4050 900  -4050
Wire Wire Line
	400  -1900 750  -1900
Wire Wire Line
	400  -1800 800  -1800
Wire Wire Line
	2300 -2350 2450 -2350
Wire Wire Line
	750  -1900 750  -4150
Connection ~ 750  -4150
Wire Wire Line
	750  -4150 950  -4150
Wire Wire Line
	800  -1800 800  -4250
Wire Wire Line
	-950 -4250 800  -4250
Connection ~ 800  -4250
Wire Wire Line
	800  -4250 1000 -4250
Wire Wire Line
	-950 -4450 1100 -4450
Wire Wire Line
	2450 -2350 2450 -4350
Connection ~ 2450 -4350
Wire Wire Line
	2450 -4350 4700 -4350
Wire Wire Line
	2300 -1900 2500 -1900
Wire Wire Line
	2500 -1900 2500 -4450
Connection ~ 2500 -4450
Wire Wire Line
	2500 -4450 4950 -4450
Wire Wire Line
	2550 -4550 2550 -1450
Wire Wire Line
	2550 -1450 2300 -1450
Connection ~ 2550 -4550
Wire Wire Line
	2550 -4550 5200 -4550
Wire Wire Line
	2300 -1000 2600 -1000
Wire Wire Line
	2600 -1000 2600 -4650
Connection ~ 2600 -4650
Wire Wire Line
	2600 -4650 5450 -4650
Wire Wire Line
	400  -1700 850  -1700
Wire Wire Line
	850  -1700 850  -3850
Connection ~ 850  -3850
Wire Wire Line
	850  -3850 3700 -3850
Wire Wire Line
	400  -1600 900  -1600
Wire Wire Line
	900  -1600 900  -4050
Connection ~ 900  -4050
Wire Wire Line
	900  -4050 3950 -4050
Wire Wire Line
	400  -1500 950  -1500
Wire Wire Line
	950  -1500 950  -4150
Connection ~ 950  -4150
Wire Wire Line
	950  -4150 4200 -4150
Wire Wire Line
	-950 -4350 1050 -4350
Wire Wire Line
	400  -1400 1000 -1400
Wire Wire Line
	1000 -1400 1000 -4250
Connection ~ 1000 -4250
Wire Wire Line
	1000 -4250 4450 -4250
Wire Wire Line
	1050 -4350 1050 -1300
Wire Wire Line
	1050 -1300 400  -1300
Connection ~ 1050 -4350
Wire Wire Line
	1050 -4350 2450 -4350
Wire Wire Line
	400  -1200 1100 -1200
Wire Wire Line
	1100 -1200 1100 -4450
Connection ~ 1100 -4450
Wire Wire Line
	1100 -4450 2500 -4450
Wire Wire Line
	1150 -4550 1150 -1100
Wire Wire Line
	1150 -1100 400  -1100
Connection ~ 1150 -4550
Wire Wire Line
	1150 -4550 2550 -4550
Wire Wire Line
	400  -1000 1200 -1000
Wire Wire Line
	1200 -1000 1200 -4650
Connection ~ 1200 -4650
Wire Wire Line
	1200 -4650 2600 -4650
Text GLabel -3750 -4250 0    50   Input ~ 0
AS1115_ISET
Text GLabel -3750 -4050 0    50   Input ~ 0
AS1115_SCL
Text GLabel -3750 -3950 0    50   Input ~ 0
AS1115_SDA
Text GLabel -3750 -3750 0    50   Input ~ 0
AS1115_IRQ
Wire Wire Line
	-3750 -4250 -3400 -4250
Wire Wire Line
	-3400 -4050 -3750 -4050
Wire Wire Line
	-3750 -3950 -3400 -3950
Wire Wire Line
	-3400 -3750 -3750 -3750
$Comp
L Device:D D?
U 1 1 5FD64919
P -650 -5450
F 0 "D?" V -604 -5529 50  0000 R CNN
F 1 "D" V -695 -5529 50  0000 R CNN
F 2 "" H -650 -5450 50  0001 C CNN
F 3 "~" H -650 -5450 50  0001 C CNN
	1    -650 -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD6491F
P -400 -5450
F 0 "D?" V -354 -5529 50  0000 R CNN
F 1 "D" V -445 -5529 50  0000 R CNN
F 2 "" H -400 -5450 50  0001 C CNN
F 3 "~" H -400 -5450 50  0001 C CNN
	1    -400 -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD64925
P -150 -5450
F 0 "D?" V -104 -5529 50  0000 R CNN
F 1 "D" V -195 -5529 50  0000 R CNN
F 2 "" H -150 -5450 50  0001 C CNN
F 3 "~" H -150 -5450 50  0001 C CNN
	1    -150 -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD6492B
P 100 -5450
F 0 "D?" V 146 -5529 50  0000 R CNN
F 1 "D" V 55  -5529 50  0000 R CNN
F 2 "" H 100 -5450 50  0001 C CNN
F 3 "~" H 100 -5450 50  0001 C CNN
	1    100  -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD64931
P 350 -5450
F 0 "D?" V 396 -5529 50  0000 R CNN
F 1 "D" V 305 -5529 50  0000 R CNN
F 2 "" H 350 -5450 50  0001 C CNN
F 3 "~" H 350 -5450 50  0001 C CNN
	1    350  -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD64937
P 600 -5450
F 0 "D?" V 646 -5529 50  0000 R CNN
F 1 "D" V 555 -5529 50  0000 R CNN
F 2 "" H 600 -5450 50  0001 C CNN
F 3 "~" H 600 -5450 50  0001 C CNN
	1    600  -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD6493D
P 850 -5450
F 0 "D?" V 896 -5529 50  0000 R CNN
F 1 "D" V 805 -5529 50  0000 R CNN
F 2 "" H 850 -5450 50  0001 C CNN
F 3 "~" H 850 -5450 50  0001 C CNN
	1    850  -5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 5FD64943
P 1100 -5450
F 0 "D?" V 1146 -5529 50  0000 R CNN
F 1 "D" V 1055 -5529 50  0000 R CNN
F 2 "" H 1100 -5450 50  0001 C CNN
F 3 "~" H 1100 -5450 50  0001 C CNN
	1    1100 -5450
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
