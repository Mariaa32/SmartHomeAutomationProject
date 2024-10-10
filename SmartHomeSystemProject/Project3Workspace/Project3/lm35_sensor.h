/*
 * lm35_sensor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


uint8 LM35_getTemperature(void);



#endif /* LM35_SENSOR_H_ */
