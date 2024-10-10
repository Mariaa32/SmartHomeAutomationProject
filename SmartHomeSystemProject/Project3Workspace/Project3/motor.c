/*
 * motor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */


#include "motor.h"
#include <avr/io.h>
#include "pwm.h"
void DcMotor_Init(void) {
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB3); // Motor control pins
    PORTB &= ~((1 << PB0) | (1 << PB1) ); // Motor stopped
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
    switch (state) {
        case CW:
            PORTB &= (1 << PB0);
            PORTB &= ~(1 << PB1);
            break;
        case A_CW:
            PORTB |= (1 << PB1);
            PORTB &= ~(1 << PB0);
            break;
        case Stop:
        default:
            PORTB &= ~((1 << PB0) | (1 << PB1));
            break;
    }
    PWM_Timer0_Start(speed);
}
