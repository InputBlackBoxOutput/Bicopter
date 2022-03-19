EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
L Device:R_Small_US R?
U 1 1 623F7798
P 4800 2975
AR Path="/6233C83C/623F7798" Ref="R?"  Part="1" 
AR Path="/623EC3BB/623F7798" Ref="R13"  Part="1" 
F 0 "R13" H 4868 3021 50  0000 L CNN
F 1 "10k" H 4868 2930 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 4800 2975 50  0001 C CNN
F 3 "~" H 4800 2975 50  0001 C CNN
	1    4800 2975
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 623F779E
P 5100 2975
AR Path="/6233C83C/623F779E" Ref="R?"  Part="1" 
AR Path="/623EC3BB/623F779E" Ref="R15"  Part="1" 
F 0 "R15" H 5168 3021 50  0000 L CNN
F 1 "10k" H 5168 2930 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 5100 2975 50  0001 C CNN
F 3 "~" H 5100 2975 50  0001 C CNN
	1    5100 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3075 4800 3275
Connection ~ 4800 3275
Wire Wire Line
	5100 3075 5100 3375
Connection ~ 5100 3375
Wire Wire Line
	4550 3275 4800 3275
Wire Wire Line
	4550 3375 5100 3375
Text Label 4550 3275 0    50   ~ 0
SDA
Text Label 4550 3375 0    50   ~ 0
SCL
Connection ~ 5150 3875
Wire Wire Line
	5150 3875 5150 4075
Wire Wire Line
	5150 3775 5150 3875
$Comp
L power:GND #PWR?
U 1 1 623F77B3
P 6000 4575
AR Path="/6233C83C/623F77B3" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F77B3" Ref="#PWR038"  Part="1" 
F 0 "#PWR038" H 6000 4325 50  0001 C CNN
F 1 "GND" H 6005 4402 50  0000 C CNN
F 2 "" H 6000 4575 50  0001 C CNN
F 3 "" H 6000 4575 50  0001 C CNN
	1    6000 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2725 6000 2725
Wire Wire Line
	6000 2625 6000 2725
Connection ~ 6000 2725
Wire Wire Line
	6000 2725 6100 2725
Wire Wire Line
	6000 4575 6000 4275
$Comp
L Device:C_Small C?
U 1 1 623F77C0
P 7450 4025
AR Path="/6233C83C/623F77C0" Ref="C?"  Part="1" 
AR Path="/623EC3BB/623F77C0" Ref="C4"  Part="1" 
F 0 "C4" H 7542 4071 50  0000 L CNN
F 1 "2.2nF" H 7542 3980 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7450 4025 50  0001 C CNN
F 3 "~" H 7450 4025 50  0001 C CNN
	1    7450 4025
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 623F77C6
P 6950 4025
AR Path="/6233C83C/623F77C6" Ref="C?"  Part="1" 
AR Path="/623EC3BB/623F77C6" Ref="C3"  Part="1" 
F 0 "C3" H 7042 4071 50  0000 L CNN
F 1 "0.1uF" H 7042 3980 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 6950 4025 50  0001 C CNN
F 3 "~" H 6950 4025 50  0001 C CNN
	1    6950 4025
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3875 6950 3875
Wire Wire Line
	6950 3875 6950 3925
Wire Wire Line
	6700 3775 7450 3775
Wire Wire Line
	7450 3775 7450 3925
Wire Wire Line
	6950 4125 6950 4275
Wire Wire Line
	6950 4275 7200 4275
Wire Wire Line
	7450 4275 7450 4125
Wire Wire Line
	7200 4275 7200 4375
Connection ~ 7200 4275
Wire Wire Line
	7200 4275 7450 4275
$Comp
L power:GND #PWR?
U 1 1 623F77D6
P 4850 3925
AR Path="/6233C83C/623F77D6" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F77D6" Ref="#PWR034"  Part="1" 
F 0 "#PWR034" H 4850 3675 50  0001 C CNN
F 1 "GND" H 4855 3752 50  0000 C CNN
F 2 "" H 4850 3925 50  0001 C CNN
F 3 "" H 4850 3925 50  0001 C CNN
	1    4850 3925
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 623F77DC
P 7200 4375
AR Path="/6233C83C/623F77DC" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F77DC" Ref="#PWR040"  Part="1" 
F 0 "#PWR040" H 7200 4125 50  0001 C CNN
F 1 "GND" H 7205 4202 50  0000 C CNN
F 2 "" H 7200 4375 50  0001 C CNN
F 3 "" H 7200 4375 50  0001 C CNN
	1    7200 4375
	1    0    0    -1  
$EndComp
Text Label 7350 3275 2    50   ~ 0
INT
$Comp
L power:+3.3V #PWR?
U 1 1 623F77E3
P 4950 2675
AR Path="/6233C83C/623F77E3" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F77E3" Ref="#PWR035"  Part="1" 
F 0 "#PWR035" H 4950 2525 50  0001 C CNN
F 1 "+3.3V" H 4965 2848 50  0000 C CNN
F 2 "" H 4950 2675 50  0001 C CNN
F 3 "" H 4950 2675 50  0001 C CNN
	1    4950 2675
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2875 4800 2825
Wire Wire Line
	4800 2825 4950 2825
Wire Wire Line
	5100 2825 5100 2875
Wire Wire Line
	4950 2825 4950 2675
Connection ~ 4950 2825
Wire Wire Line
	4950 2825 5100 2825
Wire Wire Line
	6700 3475 6950 3475
Wire Wire Line
	6700 3575 6950 3575
Text Label 6950 3475 2    50   ~ 0
XDA
Text Label 6950 3575 2    50   ~ 0
XCL
Wire Wire Line
	4550 3475 4850 3475
Wire Wire Line
	4850 3475 4850 3625
Connection ~ 4850 3475
$Comp
L Device:R_Small_US R?
U 1 1 623F77FD
P 4850 3725
AR Path="/6233C83C/623F77FD" Ref="R?"  Part="1" 
AR Path="/623EC3BB/623F77FD" Ref="R14"  Part="1" 
F 0 "R14" H 4918 3771 50  0000 L CNN
F 1 "4.7k" H 4918 3680 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 4850 3725 50  0001 C CNN
F 3 "~" H 4850 3725 50  0001 C CNN
	1    4850 3725
	1    0    0    -1  
$EndComp
Text Label 4550 3475 0    50   ~ 0
AD0
$Comp
L Device:R_Small_US R?
U 1 1 623F7804
P 6950 3075
AR Path="/6233C83C/623F7804" Ref="R?"  Part="1" 
AR Path="/623EC3BB/623F7804" Ref="R16"  Part="1" 
F 0 "R16" H 7018 3121 50  0000 L CNN
F 1 "10k" H 7018 3030 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 6950 3075 50  0001 C CNN
F 3 "~" H 6950 3075 50  0001 C CNN
	1    6950 3075
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 623F780A
P 6950 2875
AR Path="/6233C83C/623F780A" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F780A" Ref="#PWR039"  Part="1" 
F 0 "#PWR039" H 6950 2725 50  0001 C CNN
F 1 "+3.3V" H 6965 3048 50  0000 C CNN
F 2 "" H 6950 2875 50  0001 C CNN
F 3 "" H 6950 2875 50  0001 C CNN
	1    6950 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3275 6950 3275
Wire Wire Line
	6950 3175 6950 3275
Connection ~ 6950 3275
Wire Wire Line
	6950 3275 7350 3275
Wire Wire Line
	6950 2875 6950 2975
$Comp
L power:GND #PWR?
U 1 1 623F7815
P 5150 4075
AR Path="/6233C83C/623F7815" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F7815" Ref="#PWR036"  Part="1" 
F 0 "#PWR036" H 5150 3825 50  0001 C CNN
F 1 "GND" H 5155 3902 50  0000 C CNN
F 2 "" H 5150 4075 50  0001 C CNN
F 3 "" H 5150 4075 50  0001 C CNN
	1    5150 4075
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 623F783D
P 6000 2625
AR Path="/6233C83C/623F783D" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/623F783D" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 6000 2475 50  0001 C CNN
F 1 "+3.3V" H 6015 2798 50  0000 C CNN
F 2 "" H 6000 2625 50  0001 C CNN
F 3 "" H 6000 2625 50  0001 C CNN
	1    6000 2625
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3825 4850 3925
Wire Wire Line
	3300 4400 3625 4400
Wire Wire Line
	3300 4525 3625 4525
Text HLabel 3300 4400 0    50   Input ~ 0
SDA
Text HLabel 3300 4525 0    50   Input ~ 0
SCL
Text Label 3625 4400 2    50   ~ 0
SDA
Text Label 3625 4525 2    50   ~ 0
SCL
Wire Wire Line
	5300 3875 5150 3875
Wire Wire Line
	5300 3775 5150 3775
Wire Wire Line
	4850 3475 5300 3475
Wire Wire Line
	5100 3375 5300 3375
Wire Wire Line
	4800 3275 5300 3275
Wire Wire Line
	6100 2725 6100 2875
Wire Wire Line
	5900 2875 5900 2725
$Comp
L Sensor_Motion:MPU-6050 U?
U 1 1 623F77EF
P 6000 3575
AR Path="/6233C83C/623F77EF" Ref="U?"  Part="1" 
AR Path="/623EC3BB/623F77EF" Ref="U4"  Part="1" 
F 0 "U4" H 6000 2786 50  0000 C CNN
F 1 "MPU-6050" H 6000 2695 50  0000 C CNN
F 2 "Sensor_Motion:InvenSense_QFN-24_4x4mm_P0.5mm" H 6000 2775 50  0001 C CNN
F 3 "https://store.invensense.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf" H 6000 3425 50  0001 C CNN
	1    6000 3575
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J6
U 1 1 624929F5
P 3100 3600
F 0 "J6" H 3018 2975 50  0000 C CNN
F 1 "Conn_01x08" H 3018 3066 50  0000 C CNN
F 2 "Board:MPU6050_Breakout" H 3100 3600 50  0001 C CNN
F 3 "~" H 3100 3600 50  0001 C CNN
	1    3100 3600
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 624969A6
P 3750 3150
AR Path="/6233C83C/624969A6" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/624969A6" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 3750 3000 50  0001 C CNN
F 1 "+3.3V" H 3765 3323 50  0000 C CNN
F 2 "" H 3750 3150 50  0001 C CNN
F 3 "" H 3750 3150 50  0001 C CNN
	1    3750 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3150 3750 3200
Wire Wire Line
	3300 3400 3600 3400
$Comp
L power:GND #PWR?
U 1 1 6249A79C
P 3750 3350
AR Path="/6233C83C/6249A79C" Ref="#PWR?"  Part="1" 
AR Path="/623EC3BB/6249A79C" Ref="#PWR033"  Part="1" 
F 0 "#PWR033" H 3750 3100 50  0001 C CNN
F 1 "GND" H 3755 3177 50  0000 C CNN
F 2 "" H 3750 3350 50  0001 C CNN
F 3 "" H 3750 3350 50  0001 C CNN
	1    3750 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3350 3750 3300
Wire Wire Line
	3300 3200 3750 3200
Wire Wire Line
	3300 3300 3750 3300
Text Label 3600 3400 2    50   ~ 0
SCL
Wire Wire Line
	3300 3500 3600 3500
Text Label 3600 3500 2    50   ~ 0
SDA
Wire Wire Line
	3300 3600 3600 3600
Text Label 3600 3600 2    50   ~ 0
XDA
Wire Wire Line
	3300 3700 3600 3700
Text Label 3600 3700 2    50   ~ 0
XCL
Wire Wire Line
	3300 3800 3600 3800
Text Label 3600 3800 2    50   ~ 0
AD0
Wire Wire Line
	3300 3900 3600 3900
Text Label 3600 3900 2    50   ~ 0
INT
$EndSCHEMATC
