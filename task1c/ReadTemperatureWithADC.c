

#include "lab3.h"
#include "../SSD2119/SSD2119_Touch.h"

#include "../SSD2119/SSD2119_Display.h"
#include "../SSD2119/tm4c1294ncpdt.h"
#include "Lab3_1bInits.h"

#include <stdint.h>
#include <stdarg.h>

volatile float tempC = 0.00f;
volatile float tempF = 0.00f;
volatile int Y = 0;
volatile int X = 0;
int main(void) {
  
  //Initalize Everything 
  enum frequency freq = PRESET1;
  PLL_Init(freq);       // Set system clock frequency to 120 MHz
  ADCReadTemp_Init();     // Initialize to read from the Temperature
  Switch_Init(); //Initalize the switch for input
  TimerADCTriger_Init(); // Initialize Timer0A to trigger ADC0
    LCD_Init();
    Touch_Init();
    
       LCD_DrawFilledCircle(70, 180, 30, Color4[3]);
LCD_SetCursor(55,180);
LCD_Printf("120MHz");

LCD_DrawFilledCircle(280, 180, 30, Color4[3]);
LCD_SetCursor(265,180);
LCD_Printf("12MHz");


    while (1) {
      X = (int)Touch_ReadX();
      Y = (int)Touch_ReadY();

        // Check switches to change frequency
      //If sw1 is on press..... clock frequency will send to 120
        if ((GPIODATA_J & 0x01) == 0 || (Y > 700  && Y<1000) && (X > 900  && X<1300)) {
          freq = PRESET1;
            PLL_Init(freq); // 120 MHz
        } 
              //If sw2 is on press..... clock frequency will send to 12
         else if ((GPIODATA_J & 0x02) == 0 || (Y > 700  && Y < 1000) && (X > 1950 && X<2050)) {
            freq = PRESET3;
            PLL_Init(freq); // 12 MHz
        }
            //Otherwise print temperature
        LCD_SetCursor(0, 0);
       LCD_Printf("The current temperature is %f C, %f F.\n", tempC, tempF);
       LCD_Printf("The current clock frequency is %d MHz.\n", freq);

       printf("X: %d\n",X);
       printf("Y: %d",Y);

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
