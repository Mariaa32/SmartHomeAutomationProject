/*
 * flame_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */


#include "flame_sensor.h"

#include <avr/io.h>

void FlameSensor_init(void) {
    DDRD &= ~(1 << PD2); // Set PD2 as input
}

uint8 FlameSensor_getValue(void) {
	// Return the state of the flame sensor (1 if flame is detected, 0 otherwise)
	    return (PIND & (1 << PD2)) ? 1 : 0;
}
