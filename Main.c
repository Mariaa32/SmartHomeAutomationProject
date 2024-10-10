
#include <util/delay.h>
#include "adc.h"
#include "lcd.h"
#include "led.h"
#include "motor.h"
#include "gpio.h"
#include "ldr_sensor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "buzzer.h"
#include "std_types.h"
#include "common_macros.h"

// Variables for sensor readings
uint16 temperature = 0;
uint16 light_intensity = 0;
uint8 fire_detected = 0;
uint8 fan_state=0;
// Function to display the system status on the LCD
void LCD_DisplayStatus(uint8 fan_state, uint16 temperature, uint16 light_intensity) {
    // Clear the LCD screen
  // LCD_clearScreen();

    // First row: Display "FAN is ON" or "FAN is OFF" based on fan state
    LCD_displayString("FAN is ");
    if (fan_state==1) {
        LCD_displayString("ON");
    } else {
        LCD_displayString("OFF");
    }

    // Move to the second row
    LCD_moveCursor(1, 0);  // Go to second row, first column

    // Second row: Display temperature and light intensity
    LCD_displayString("Temp=");
    LCD_intgerToString(temperature);  // Display temperature in Celsius
    LCD_displayString("C LDR=");
    LCD_intgerToString(light_intensity);  // Display light intensity in percentage
    LCD_displayString("%");
    _delay_ms(1000);
}

int main(void) {
    // Initialization
    ADC_init();
    LCD_init();
    LEDS_init();
    DcMotor_Init();
    FlameSensor_init();
    Buzzer_init();
    // Main loop
    while (1) {
        // Read sensors
        temperature = LM35_getTemperature();
        light_intensity = LDR_getLightIntensity();
        fire_detected = FlameSensor_getValue();

        // Update fan speed based on temperature
        if (temperature >= 40) {
            DcMotor_Rotate(CW, 100); // Full speed
            fan_state=1;
        } else if (temperature >= 35 && temperature < 40) {
            DcMotor_Rotate(CW, 75);
            fan_state=1;
        } else if (temperature >= 30 && temperature < 35) {
            DcMotor_Rotate(CW, 50);
            fan_state=1;
        } else if (temperature >= 25 && temperature < 30) {
            DcMotor_Rotate(CW, 25);
            fan_state=1;
        } else if (temperature < 25){
            DcMotor_Rotate(Stop, 0);// Fan off
            fan_state=0;
        }

        // Control LEDs based on light intensity
        if (light_intensity < 15) {
            LED_on(RED);
            LED_on(GREEN);
            LED_on(BLUE);
        } else if (light_intensity < 50) {
            LED_on(RED);
            LED_on(GREEN);
            LED_off(BLUE);
        } else if (light_intensity < 70) {
            LED_on(RED);
            LED_off(GREEN);
            LED_off(BLUE);
        } else {
            LED_off(RED);
            LED_off(GREEN);
            LED_off(BLUE);
        }

        // Fire detection
        if (fire_detected==1) {
            Buzzer_on();
            LCD_displayString("Critical alert!");
            _delay_ms(10000);
            LCD_clearScreen();
        } else {
            Buzzer_off();
            LCD_DisplayStatus(fan_state,temperature,light_intensity);
        }
    }

}
