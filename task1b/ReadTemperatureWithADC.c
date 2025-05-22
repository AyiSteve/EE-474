

#include "lab3.h"

#include "../SSD2119/SSD2119_Display.h"
#include "../SSD2119/tm4c1294ncpdt.h"
#include "Lab3_1bInits.h"

#include <stdint.h>
#include <stdarg.h>

volatile float tempC = 0.00f;
volatile float tempF = 0.00f;
int main(void) {
  
  //Initalize Everything 
  enum frequency freq = PRESET1;
  PLL_Init(freq);       // Set system clock frequency to 120 MHz
  ADCReadTemp_Init();     // Initialize to read from the Temperature
  Switch_Init(); //Initalize the switch for input
  TimerADCTriger_Init(); // Initialize Timer0A to trigger ADC0
    LCD_Init();
    while (1) {

        // Check switches to change frequency
      //If sw1 is on press..... clock frequency will send to 120
        if ((GPIODATA_J & 0x01) == 0) {
          freq = PRESET1;
            PLL_Init(freq); // 120 MHz
        } 
              //If sw2 is on press..... clock frequency will send to 12
        else if ((GPIODATA_J & 0x02) == 0) {
            freq = PRESET3;
            PLL_Init(freq); // 12 MHz
        }
            //Otherwise print temperature
        LCD_SetCursor(0, 0);
       LCD_Printf("The current temperature is %f C, %f F.\n", tempC, tempF);
       LCD_Printf("The current clock frequency is %d MHz.", freq);

    }
}


void ADC0SS3_Handler(void) {

    uint32_t adc_val = ADC0SSFIFO3;
  //Calculate the temperature in  C and F
    float v_tsens = (adc_val * 3.3f) / 4095.0f;
    tempC = 75.0f * (2.7f - v_tsens) - 55.0f;
    tempF = tempC * 9.0f / 5.0f + 32.0f;
     ADC0ISC = 0x08; //Clear interrupt


}
