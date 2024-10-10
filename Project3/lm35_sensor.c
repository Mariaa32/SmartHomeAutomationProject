/*
 * temperature_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */



#include <util/delay.h>
#include "lm35_sensor.h"
#include "adc.h"


uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	ADC_readChannel(SENSOR_CHANNEL_ID);
	_delay_ms(5);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)g_adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

