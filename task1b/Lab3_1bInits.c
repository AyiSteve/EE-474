/**
 * EE/CSE 474: Lab3 drivers starter code
 */

#include "Lab3_1bInits.h"
#include "lab3.h"
// STEP 0a: Include your header file here
// YOUR CUSTOM HEADER FILE HERE

int PLL_Init(enum frequency freq) {
    // Do NOT modify this function.
    MOSCCTL &= ~(0x4);                      // Power up MOSC
    MOSCCTL &= ~(0x8);                      // Enable MOSC
    while ((RIS & 0x100) == 0) {};          // Wait for MOSC to be ready
    RSCLKCFG |= (0x3 << 20);                // Select MOSC as system clock source
    RSCLKCFG |= (0x3 << 24);                // Select MOSC as PLL clock source

    PLLFREQ0 |= 0x60;                       // Set MINT field
    PLLFREQ1 |= 0x4;                        // Set N field

    MEMTIM0 &= ~((0xF << 22) | (0xF << 6));     // Reset FBCHT and EBCHT
    MEMTIM0 &= ~((0xF << 16) | (0xF << 0));     // Reset EWS and FWS
    MEMTIM0 &= ~((0x1 << 21) | (0x1 << 5));     // Reset FBCE and EBCE

    RSCLKCFG &= ~(0x1 << 28);                   // Temporarilly bypass PLL

    switch (freq) {
        case 120:
            MEMTIM0 |= (0x6 << 22) | (0x6 << 6);    // Set FBCHT and EBCHT
            MEMTIM0 |= (0x5 << 16) | (0x5 << 0);    // Set EWS and FWS
            RSCLKCFG |= 0x3;                        // Set PSYSDIV to use 120 MHZ clock
            RSCLKCFG &= ~0x3FC;                     // Update PSYSDIV field
            break;
        case 60:
            MEMTIM0 |= (0x3 << 22) | (0x3 << 6);    // Set FBCHT and EBCHT
            MEMTIM0 |= (0x2 << 16) | (0x2 << 0);    // Set EWS and FWS
            RSCLKCFG |= 0x7;                        // Set PSYSDIV to use 60 MHZ clock
            RSCLKCFG &= ~0x3F8;                     // Update PSYSDIV field
            break;
        case 12:
            MEMTIM0 |= (0x1 << 21) | (0x1 << 5);    // Set FBCE and EBCE
            RSCLKCFG |= 0x27;                       // Set PSYSDIV to use 12 MHZ clock
            RSCLKCFG &= ~0x3D8;                     // Update PSYSDIV field
            break;
        default:
            return -1;
    }

    RSCLKCFG |= (0x1 << 30);                // Enable new PLL settings
    PLLFREQ0 |= (0x1 << 23);                // Power up PLL
    while ((PLLSTAT & 0x1) == 0) {};        // Wait for PLL to lock and stabilize

    RSCLKCFG |= (0x1u << 31) | (0x1 << 28);  // Use PLL and update Memory Timing Register
    return 1;
}


void ADCReadTemp_Init(void) {
 // STEP 2: Initialize ADC0 SS3.
  // 2.1: Enable the ADC0 clock
  RCGCADC |= 0x1;
  // 2.2: Delay for RCGCADC (Refer to page 1073)
 volatile int delay = 0; delay++; delay++;
  // 2.3: Power up the PLL (if not already)
  PLLFREQ0 |= 0x00800000; // we did this for you
  // 2.4: Wait for the PLL to lock
  while (PLLSTAT != 0x1); // we did this for you
  // 2.5: Configure ADCCC to use the clock source defined by ALTCLKCFG
  ADCCC |= 0x1;
  
  // 2.11: Disable sample sequencer 3 (SS3)
  ADC0ACTSS &= ~(1 << 3);
   
  // 2.12: Select timer as the trigger for SS3
  ADC0EMUX &= ~(0xF << 12);
   ADC0EMUX |= (0x5 << 12);   

  // 2.13: Select the analog input channel for SS3 (Hint: Table 15-1) to range 16 and above
  ADC0SSMUX3 = 0;
  // 2.14: Configure ADCSSCTL3 register to read from temperature
  ADC0SSCTL3 = 0xE;
  // 2.15: Set the SS3 interrupt mask
  ADC0IM |= (1 << 3);
  // 2.16: Set the corresponding bit for ADC0 SS3 in NVIC
  NVIC_EN0_R |= (1 << 17);
  // 2.17: Enable ADC0 SS3
  ADC0ACTSS |= (1 << 3);
}



void Switch_Init(void) {
    volatile unsigned short delay = 0;
    // Enable clocks for Port J 
    RCGCGPIO |= 0x0100;   // Port J
    delay++;
    delay++;

    // Make SW1 (PJ0) and SW2 (PJ1) as inputs
    GPIODIR_J &= ~0x03;   
    GPIODEN_J |= 0x03;    
    GPIOPUR_J |= 0x03;  
}

    
void TimerADCTriger_Init(void) {
  // STEP 3: Initialize Timer0A to trigger ADC0 at 1 HZ.
  // Hint: Refer to section 13.3.7 of the datasheet
  RCGCTIMER |= 0x1;           
  volatile int delay = 0; delay++; delay++;

  GPTMCTL_0 &= ~0x1;          
  GPTMCFG_0 = 0x0;            
  GPTMTAMR_0 = 0x2;           
  GPTMTAMR_0 |= (1 << 4);     // Enable ADC trigger

  GPTMTAILR_0 = 60000000;     // 1 Hz assuming 60 MHz clock
  GPTMADCEV_0 |= 0x1;         // ADC event trigger on timeout
  
  GPTMCTL_0 |= (1 << 5); 
  GPTMICR_0 = 0x1;            
  GPTMCTL_0 |= 0x1;           
}

// NEXT STEP: Go to Lab3_Task1a.c and finish implementing ADC0SS3_Handler
