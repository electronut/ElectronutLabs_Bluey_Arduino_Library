/**
 * bluey_wire.h
 *
 * Arduino include file using Wire library to establish I2C communication with sensors.
 *
 * Electronut Labs
 * electronut.in
*/

#ifndef _BLUEY_WIRE_H_
#define _BLUEY_WIRE_H_

#include "Arduino.h"
#include "Wire.h"

/**
 * Reads num bytes starting from address register on device in to _buff array
 */
void readRegister(uint8_t dev_addr, uint8_t reg_addr, uint8_t num_bytes, uint8_t data_buff[]);

/**
 * Writes num bytes starting from address register on device
 */
void writeRegister(uint8_t dev_addr, uint8_t reg_addr, uint8_t *val);

#endif /* _BLUEY_WIRE_H_ */
