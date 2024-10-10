/*
 * motor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
typedef enum {
    CW, A_CW, Stop
} DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
