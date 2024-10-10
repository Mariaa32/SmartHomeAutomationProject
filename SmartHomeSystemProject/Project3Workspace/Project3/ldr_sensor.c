/*
 * ldr_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */

#include "ldr_sensor.h"
#include "adc.h"
#include <util/delay.h>


uint16 LDR_getLightIntensity(void) {

    uint16 adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    float voltage = (adc_value * LDR_SENSOR_MAX_VOLT_VALUE) / 1023.0;

    uint16 light_intensity = (uint16)((voltage / LDR_SENSOR_MAX_VOLT_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY);

    return light_intensity;
}

