/*
 * pwm.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */


#include "pwm.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle) {
    // Set OC0 (PB3) as output pin
    DDRB |= (1 << PB3);

    TCCR0 = (1 << WGM00) | (1 << WGM01);   // Fast PWM Mode (WGM00, WGM01)
    TCCR0 |= (1 << COM01);                 // Non-inverting mode (COM01)

    // Set F_CPU/1024
    TCCR0 |= (1 << CS00) | (1 << CS02);

    // Set the duty cycle (OCR0 sets the PWM pulse width)
    OCR0 = (duty_cycle * 255) / 100;  // Map 0-100% to 0-255 for the 8-bit timer
}
