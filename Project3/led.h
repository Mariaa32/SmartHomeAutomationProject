/*
 * led.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */

#ifndef LED_H_
#define LED_H_
typedef enum {
    RED, GREEN, BLUE
} LED_ID;

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);


#endif /* LED_H_ */
