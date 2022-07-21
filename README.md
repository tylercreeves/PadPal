# PadPal

> Author: Tyler Reeves, AKA T-Rex ([@tylercreeves](https://github.com/tylercreeves))

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal%20(front).jpg" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal%20(front).jpg" width="500" height="666.67" />

**An untralight electric sleeping pad inflator solution**

The PadPal is a bare bones, simple electric sleeping pad inflation device. The goal of this project is to make a sleeping pad inflator that us UL folks would not shun away in flavor of sore jaw muscles, empty lungs, and light heads.

Below is a breakdown of the project as well as how you can make your own. 

If making your own seems like a hassel, you can also purchase them from me for $44.00 shipped to the lower 48 states (contact me for shipping rates elsewhere) by reaching out to me via reddit u/tylercreeves


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

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal%20(components).jpg" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal%20(components).jpg" width="500" height="666.67" />


## 3D Printed Hardware

There are 2 user printed parts that compose the PadPals general body. Bellow are printing suggestions for each part.

>**Part:** PadPal_Duct_V3

**Material:** Polycarbonate

**Settings:** Use custom support structures to support the motor housing, bridges for the PCB housing, and chamerfered bridges from motor housing to inner fan duct. Here is a picture of the areas I added custom support enforcers. A brim may help prevent the Polycarbonate from warping.

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Custom_Supports.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Custom_Supports.JPG" width="500" height="576" />
<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Fan_Duct_Sliced.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Fan_Duct_Sliced.JPG" width="500" height="500" />

>**Part:** PadPal_ThermarestWingLock_V3

**Material:** TPU

**Settings:** print with skinny end facing up, add a 2mm brim, no supports

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Winglock_Adapter_Sliced.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Winglock_Adapter_Sliced.JPG" width="500" height="576" />

## Code (Finite State Machine)

The PadPal utalizes an Attiny13ASU microcontroller that can be programmed to controlle the DC motor. I have programmed the MC with a finite state machine that works as follows. When you plug in the device, it waits 2 seconds before starting. After 2 seconds pass, it ramps up the fan to a specified speed. Once at specified speed it maintains that speed for a specified time. Once the specified time has ellapse, it will turn off the fan and enter sleep mode to avoid accidentally draining a forgetful hikers bacttery bank. To restart the PadPal, the user must unplug it and plug it in again.

## Making/Buying the Custom PCB

To get a custom motor controller PCB for this project, you have two options. One is to download the EDA GERBER files, BOM file, and source a manufactureur for the PCB as well as all the components. This board used SMD components and requires some decent skills in SMD soldering to pull off. It you go this route, there usually are minimum order quantities required for the PCB and components, so you may end up with a few extra boards.

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal_PCB.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal_PCB.JPG" width="600" height="600" />

To save some of you the time and complexity of making and programming the boards yourself, you can contact me via reddit at u/tylercreeves where I sell the assembled and programmed boards for $12.18 shipped to the lower 48 states (contact me for special shipping rates elsewhere).

## Programming the PCB

Assuming you have gone the route of making your own boards, here is how to program the PadPal PCB. You will need to make an "Arduino as ISP". For this I used an Arduino Uno board and purchased a perferate "hat" board to solder up programmer with pogopins. Here are picture of the Arduino uno, custom "hat", and the two together.

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Hat%26Arduino.jpg" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Hat%26Arduino.jpg" width="666.67" height="500" /> 
<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Ardiuno_as_ISP.jpg" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Ardiuno_as_ISP.jpg" width="500" height="666.67" />

First you will need to download the Arduino IDE if you havent done so. Next you need to flash the "Arduino as ISP" example sketch into the Arduino You will use to program your PadPal. Now you need to download the MicroCore liberary into your Arduino IDE so you can program the PadPal. Please watch [this video](https://www.youtube.com/watch?v=G2nVVtmKgWI&list=LL&index=113) of an unrelated project on how to do so by Electronics BD.

## Arduino as ISP Programmer Pin-Out

Here is a picture of my setup and Pin-Out of the headers on my custom motor control boards. You might have to do some clever mix and matching between my picture and the linked video untill I put up a complete pin-out for the arduino-ISP programmer I made.

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Header_PinOut.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Header_PinOut.JPG" width="1100" height="500" />
<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/20220712_123211.jpg" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/20220712_123211.jpg" width="500" height="666.67" />

**Bellow is an FSM Diagram to assist in understanding the code so one can modify it.**

Review the FSM diagram along side the included code to get a sense of what is going on in the code. 

<img src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal_FSM_Diagram.JPG" data-canonical-src="https://github.com/tylercreeves/PadPal/blob/main/Pictures/Pad-Pal_FSM_Diagram.JPG" />

## Assembly/Finishing

After you purchase a board, or finish making, soldering, and programming your own, you are ready for assembly! I'm not even going to tell you how, its pretty simple once all the parts are infront of you your ready. I'd suggest do the motor first, followed by the fan blade, then plugin the motor to the PCB and insert the PCB to its housing. Its a tight fit so you may need to get glever with some soft contact tools to push it in all the way.
