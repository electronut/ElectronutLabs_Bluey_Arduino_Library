# ElectronutLabs_Bluey_Arduino_Library

![](images/bluey1.2-sm.jpg)

![](images/arduino-ide.png)

[Bluey][1] is a BLE (Bluetooth Low Energy) development board with Temperature, Humidity, Ambient Light and Accelerometer sensors. Bluey uses the Nordic nRF52832 BLE SoC (System on a Chip) which has an ARM Cortex-M4F CPU and a 2.4 GHz radio that supports BLE and other proprietary wireless protocols. It also supports NFC, and in fact the board comes with a built-in NFC PCB antenna.

This library enables you to use Bluey for with the Arduino platform.

## Examples

Bluey directory contains examples demonstrating the board's usage and functionalities. 

**bluey_sensor_test** example demonstrates the use of Nordic UART service to transmit temperature, humidity, ambient light, accelerometer and gyroscope readings from Bluey to nRF Connect mobile application on your smartphone.


## Usage

**Copy *Bluey* to Documents/Arduino/libraries directory.**

* Set the device in bootloader mode. To trigger bootloader, press and hold button1 **(SW3)** , press the Reset button **(RST)** and then release button1. More details on bootloader can be found at main Bluey [repository](https://github.com/electronut/ElectronutLabs-bluey)

* Go to: Tools > Boards. Select **Electronut labs Bluey**.

* Go to: Tools > Softdevice. Select **S132**.

* Ensure Low Frequency Clock is set to **Crystal Oscillator** under Tools menu.

* Select appropriate COM Port assigned to Bluey.

* Click on **Upload** under Sketch menu or use **Ctrl + U** combination to upload code to Bluey.

* Once the code is uploaded, perform a manual reset by pressing **RST** button once.

[1]: http://electronut.in/portfolio/bluey/
