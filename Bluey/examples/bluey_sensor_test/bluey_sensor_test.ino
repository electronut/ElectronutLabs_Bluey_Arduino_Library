/**
 * Bluey: Example project to obtain sensor data and transmit data via BLE to smartphone using Nordc UART Service
 *
 * author: Electronut Labs
 * website: www.electronut.in
 *
 * reference: serial example from BLEPeripheral library by Sandeep Mistry
 */

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <BLEPeripheral.h>

#include "BLESerial.h"
#include "HDC1010.h"
#include "APDS9301.h"
#include "SparkFunLSM6DS3.h"


// define pins (varies per shield/board)
#define BLE_REQ   10
#define BLE_RDY   2
#define BLE_RST   9

// create ble serial instance, see pinouts above
BLESerial BLESerial(BLE_REQ, BLE_RDY, BLE_RST);

LSM6DS3 myIMU(I2C_MODE, 0x6A); //Default constructor defines I2C address as 0x6B. Bluey uses 0x6A.

volatile float lux;
volatile float temp;
volatile float humid;
volatile float accX, accY, accZ;
volatile float gyroX, gyroY, gyroZ;

uint8_t rx_data = 0;
bool packet_LTH = false;
bool packet_ACC = false;
bool packet_GYR = false;

/**
 * @brief function to read sensor data and store them in variables for BLE operations
 */
void read_sensor_data(void)
{
  lux = getlux();
  temp = HDC1010_get_temp();
  humid = HDC1010_get_humid();

  accX = myIMU.readFloatAccelX();
  accY = myIMU.readFloatAccelY();
  accZ = myIMU.readFloatAccelZ();

  gyroX = myIMU.readFloatGyroX();
  gyroY = myIMU.readFloatGyroY();
  gyroZ = myIMU.readFloatGyroZ();
}

void setup()
{
  Wire.begin();

  // custom services and characteristics can be added as well
  BLESerial.setLocalName("Bluey");

  BLESerial.begin();

  HDC1010_init(TEMP_OR_HUMID);
  APDS9301_init();
  myIMU.begin();
}

void loop()
{
  BLESerial.poll();

  read_sensor_data();

  rx_data = BLESerial.read();

  switch(rx_data) {
    case 49:  // character 1
      packet_LTH = true;
      packet_ACC = false;
      packet_GYR = false;
      break;

     case 50: // character 2
      packet_LTH = false;
      packet_ACC = true;
      packet_GYR = false;
      break;

     case 51: // character 3
      packet_LTH = false;
      packet_ACC = false;
      packet_GYR = true;
      break;

     default:
      break;
  }

  if(packet_LTH){
    BLESerial.print(lux, 1);
    BLESerial.print(" lx ");
    BLESerial.print(temp, 1);
    BLESerial.print(" C ");
    BLESerial.print(humid, 1);
    BLESerial.println(" %");
  }
  else if(packet_ACC){
    BLESerial.print("X:");
    BLESerial.print(accX, 1);
    BLESerial.print(" Y:");
    BLESerial.print(accY, 1);
    BLESerial.print(" Z:");
    BLESerial.println(accZ, 1);
  }
  else if(packet_GYR){
    BLESerial.print("X:");
    BLESerial.print(gyroX, 1);
    BLESerial.print(" Y:");
    BLESerial.print(gyroY, 1);
    BLESerial.print(" Z:");
    BLESerial.println(gyroZ, 1);

  }
  else{
    BLESerial.println("Request data");
  }
  delay(1000);
}
