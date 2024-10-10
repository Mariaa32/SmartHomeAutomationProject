/*
 * led.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */


#include "led.h"
#include <avr/io.h>

void LEDS_init(void) {
    DDRB |= (1 << PB5) | (1 << PB6) | (1 << PB7); // Set LEDs pins as output
    PORTB &= ~((1 << PB5) | (1 << PB6) | (1 << PB7)); // Turn off all LEDs
}

void LED_on(LED_ID id) {
    PORTB |= (1 << (PB5 + id));
}

void LED_off(LED_ID id) {
    PORTB &= ~(1 << (PB5 + id));
}
