# PadPal

> Author: Tyler Reeves, AKA T-Rex ([@btylercreeves](https://github.com/tylercreeves))

**An untralight electric sleeping pad inflator solution**

The PadPal is a bare bones, simple electric sleeping pad inflation device. The goal of this project is to make a sleeping pad inflator that us UL folks would not shun away in flavor of sore jaw muscles, empty lungs, and light heads.


## Design

The PadPal is designed to leverage consumer grade 3D printing technology and consumer accessible PCB manufactures like JLCPCB. It is composed of 5 parts.

`Part:* 3D printed fan duct housing

`Qty:* 1

`Part:* 3D printed sleeping pad valve adapter

`Qty:* 1

`Part:* 6x15mm coreless DC motor with .8mm shaft and micro JST connector

`Qty:* 1

`Part:* 31mm 4 blade propeller with .8mm press fit shaft hole.

`Qt1:* 1

`Part:* PadPal V3 PCB with SMD

`Qty:* 1


## Unit Testing

When creating unit tests for the factory you can generate mock user input similar to the way it was created in the unit testing lab. Make sure to test that all combinations of operators are being parsed correctly and that it can generate trees with various numbers of operators and operands. You should also test that your factory correctly returns a `nullptr` when invalid input is provided.

## Submission

To receive credit for this lab you must show an example program to your TA that demonstrates the full functionality of this pattern, including any interactions with other patterns. You must also show your TA the tests that you have created for validating that your classes are functioning correctly.
