/*
 * buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */

#include "buzzer.h"
#include <avr/io.h>

void Buzzer_init(void) {
    DDRD |= (1 << PD3); // Set PD3 as output
    Buzzer_off();
}

void Buzzer_on(void) {
    PORTD |= (1 << PD3); // Turn buzzer on
}

void Buzzer_off(void) {
    PORTD &= ~(1 << PD3); // Turn buzzer off
}
