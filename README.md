# PadPal

> Author: Tyler Reeves, AKA T-Rex ([@tylercreeves](https://github.com/tylercreeves))

![alt text](https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal%20(front).jpg)

**An untralight electric sleeping pad inflator solution**

The PadPal is a bare bones, simple electric sleeping pad inflation device. The goal of this project is to make a sleeping pad inflator that us UL folks would not shun away in flavor of sore jaw muscles, empty lungs, and light heads.


## Design

The PadPal is designed to leverage consumer grade 3D printing technology and consumer accessible PCB manufactures like JLCPCB. It is composed of 5 parts.

>**Part:** 3D printed fan duct housing

**Qty:** 1

>**Part:** 3D printed sleeping pad valve adapter

**Qty:** 1

>**Part:** 6x15mm coreless DC motor with .8mm shaft and micro JST connector

**Qty:** 1

>**Part:** 31mm 4 blade propeller with .8mm press fit shaft hole.

**Qty:** 1

>**Part:** PadPal V3 PCB with SMD

**Qty:** 1

**TYLER, ADD PICTURE OF PARTS HERE**


## 3D Printed Hardware

There are 2 user printed parts that compose the PadPals general body. Bellow are printing suggestions for each part.

>**Part:** PadPal_Duct_V3

**Material:** Polycarbonate

**Settings:** Use custom support structures to support the motor housing and bridges for the PCB housing

>**Part:** PadPal_ThermarestWingLock_V3

**Material:** TPU

**Settings:** print with skinny end facing up, add a 2mm brim, no supports

## Code (Finite State Machine)

The PadPal utalizes an Attiny13ASU microcontroller that can be programmed to controlle the DC motor. I have programmed the MC with a finite state machine that works as follows. When you plug in the device, it waits 2 seconds before starting. After 2 seconds pass, it ramps up the fan to a specified speed. Once at specified speed it maintains that speed for a specified time. Once the specified time has ellapse, it will turn off the fan and enter sleep mode to avoid accidentally draining a forgetful hikers bacttery bank. To restart the PadPal, the user must unplug it and plug it in again.

**Bellow is an FSM Diagram to assist in understanding the code so one can modify it.**

**TYLER --> DONT FORGET TO ADD FSM DIAGRAM**

## Programming the PCB

To program the PadPal PCB you will need to make an "Arduino as ISP". For this I used an Arduino Uno board and purchased a perferate "hat" board to solder up programmer with pogopins. First you will need to download the Arduino IDE if you havent done so. Next you need to flash the "Arduino as ISP" example sketch into the Arduino You will use to program your PadPal. Now you need to download the MicroCore liberary into your Arduino IDE so you can program the PadPal. Please watch this video of an unrelated project on how to do so.

**TYLER ADD LINK TO VIDEO!**

## Arduino as ISP Programmer Pin-Out

**Tyler add schematic for Arduino as ISP Pinout Plus Picture of your setup**
