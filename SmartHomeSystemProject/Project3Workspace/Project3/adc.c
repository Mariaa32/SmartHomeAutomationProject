/*
 * ADC.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Dell
 */


#include "adc.h"
#include "std_types.h"
#include <avr/io.h>
#include "common_macros.h"
// Define the global variable to store the ADC result
uint16 g_adcResult = 0;
void ADC_init(void) {
    ADMUX = (1 << REFS0) | (1 << REFS1); // Internal 2.56V reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, prescaler 128
}

uint16 ADC_readChannel(uint8 channel_num) {
    channel_num &= 0x07; // Keep the channel within range
    ADMUX = (ADMUX & 0xF8) | channel_num;
    ADCSRA |= (1 << ADSC); // Start conversion
    while (!(ADCSRA & (1 << ADIF))); // Wait for conversion to finish
    ADCSRA |= (1 << ADIF); // Clear interrupt flag
    // Store the result in the global variable
        g_adcResult = ADC;

        // Return the ADC result
        return g_adcResult;
}

