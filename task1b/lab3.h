//Steven Gong
//2308228

//We define lots of stuff here, contain everything that we need for the project
#ifndef __HEADER1_H__
#define __HEADER1_H__

#include <stdint.h>

// Clock gating
#define RCGCGPIO      (*((volatile uint32_t *)0x400FE608))

// Port F Only for our LED in the board 
#define GPIODIR_F     (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F     (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F    (*((volatile uint32_t *)0x4005D3FC))

// Port N  Only for our LED in the board
#define GPIODIR_N     (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N     (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N    (*((volatile uint32_t *)0x400643FC))

// Port J for the switches on board
#define GPIODIR_J     (*((volatile uint32_t *)0x40060400))
#define GPIODEN_J     (*((volatile uint32_t *)0x4006051C))
#define GPIODATA_J    (*((volatile uint32_t *)0x400603FC))
#define GPIOPUR_J     (*((volatile uint32_t *)0x40060510))

//Define port L  
#define GPIOLOCK_L     (*((volatile unsigned long *)0x40062520))
#define GPIOCR_L       (*((volatile unsigned long *)0x40062524))
#define GPIOAMSEL_L    (*((volatile unsigned long *)0x40062528))
#define GPIODIR_L      (*((volatile unsigned long *)0x40062400))
#define GPIOAFSEL_L    (*((volatile unsigned long *)0x40062420))
#define GPIODEN_L      (*((volatile unsigned long *)0x4006251C))
#define GPIODATA_L     (*((volatile unsigned long *)0x400623FC))

//TImer 0
#define RCGCTIMER (*((volatile unsigned long *)0x400FE604 ))
#define GPTMCTL_0 (*((volatile unsigned long *)0x4003000C ))
#define GPTMCFG_0 (*((volatile unsigned long *)0x40030000 ))
#define GPTMTAMR_0 (*((volatile unsigned long *)0x40030004 ))
#define GPTMIMR_0 (*((volatile unsigned long *)0x40030018 ))
#define GPTMTAILR_0 (*((volatile unsigned long *)0x40030028 ))
#define GPTMRIS_0       (*((volatile uint32_t *)0x4003001C))
#define GPTMICR_0       (*((volatile uint32_t *)0x40030024))
#define GPTMADCEV_0     (*((volatile uint32_t *)0x40030070))

// Timer 1
#define GPTMCTL_1     (*((volatile unsigned long *)0x4003100C))
#define GPTMCFG_1     (*((volatile unsigned long *)0x40031000))
#define GPTMTAMR_1    (*((volatile unsigned long *)0x40031004))
#define GPTMIMR_1     (*((volatile unsigned long *)0x40031018))
#define GPTMTAILR_1   (*((volatile unsigned long *)0x40031028))
#define GPTMRIS_1     (*((volatile uint32_t *)0x4003101C))
#define GPTMICR_1     (*((volatile uint32_t *)0x40031024))
#define NVIC_EN0_R     (*((volatile uint32_t *)0xE000E100))

//Interrupt for Port J
#define GPIO_PORTJ_IS_R    (*((volatile unsigned long *)0x40060404)) 
#define GPIO_PORTJ_IBE_R   (*((volatile unsigned long *)0x40060408)) 
#define GPIO_PORTJ_IEV_R   (*((volatile unsigned long *)0x4006040C)) 
#define GPIO_PORTJ_IM_R    (*((volatile unsigned long *)0x40060410))
#define GPIO_PORTJ_RIS_R   (*((volatile unsigned long *)0x40060414)) 
#define GPIO_PORTJ_MIS_R   (*((volatile unsigned long *)0x40060418)) 
#define GPIO_PORTJ_ICR_R   (*((volatile unsigned long *)0x4006041C)) 
#define NVIC_EN1_R   (*((volatile uint32_t *)0xE000E104))
#define NVIC_EN2_R              (*((volatile uint32_t *)0xE000E108))

//Interrupt for Port L
#define GPIO_PORTL_IS_R    (*((volatile unsigned long *)0x40062404)) 
#define GPIO_PORTL_IBE_R   (*((volatile unsigned long *)0x40062408)) 
#define GPIO_PORTL_IEV_R   (*((volatile unsigned long *)0x4006240C))
#define GPIO_PORTL_IM_R    (*((volatile unsigned long *)0x40062410)) 
#define GPIO_PORTL_RIS_R   (*((volatile unsigned long *)0x40062414))
#define GPIO_PORTL_MIS_R   (*((volatile unsigned long *)0x40062418))
#define GPIO_PORTL_ICR_R   (*((volatile unsigned long *)0x4006241C)) 

// ******************** CLOCK CONTROL REGISTERS ********************** //
#define MOSCCTL                 (*(volatile uint32_t *) 0x400FE07C)
#define RIS                     (*(volatile uint32_t *) 0x400FE050)
#define RSCLKCFG                (*(volatile uint32_t *) 0x400FE0B0)
#define PLLFREQ0                (*(volatile uint32_t *) 0x400FE160)
#define PLLFREQ1                (*(volatile uint32_t *) 0x400FE164)
#define PLLSTAT                 (*(volatile uint32_t *) 0x400FE168)
#define MEMTIM0                 (*(volatile uint32_t *) 0x400FE0C0)

//Port E
#define GPIOAFSEL_E     (*((volatile uint32_t *)0x4005C420))
#define GPIODEN_E       (*((volatile uint32_t *)0x4005C51C))
#define GPIOAMSEL_E     (*((volatile uint32_t *)0x4005C528))

//ADC
#define RCGCADC         (*((volatile uint32_t *)0x400FE638))
#define ADC0ACTSS      (*((volatile uint32_t *)0x40038000))
#define ADC0EMUX       (*((volatile uint32_t *)0x40038014))
#define ADC0SSMUX3     (*((volatile uint32_t *)0x400380A0))
#define ADC0SSCTL3     (*((volatile uint32_t *)0x400380A4))
#define ADC0IM         (*((volatile uint32_t *)0x40038008))
#define ADC0ISC      (*((volatile uint32_t *)0x4003800C))
#define ADC0SSFIFO3  (*((volatile uint32_t *)0x400380A8))
#define ADCCC           (*((volatile uint32_t *)0x40038FC8))

//UART0
#define RCGCUART      (*((volatile uint32_t *)0x400FE618))
#define RCGCGPIO       (*((volatile uint32_t *)0x400FE608))
#define PRGPIO         (*((volatile uint32_t *)0x400FEA08))
#define GPIOAFSEL_A      (*((volatile uint32_t *)0x40058420))
#define GPIOPCTL_A       (*((volatile uint32_t *)0x4005852C))
#define GPIODEN_A        (*((volatile uint32_t *)0x4005851C))
#define GPIOAMSEL_A      (*((volatile uint32_t *)0x40058528))
#define UART0CTL             (*((volatile uint32_t *)0x4000C030))
#define UART0IBRD            (*((volatile uint32_t *)0x4000C024))
#define UART0FBRD            (*((volatile uint32_t *)0x4000C028))
#define UART0LCRH            (*((volatile uint32_t *)0x4000C02C))
#define UART0DR              (*((volatile uint32_t *)0x4000C000))
#define UART0FR              (*((volatile uint32_t *)0x4000C018))
#define UART0CC              (*((volatile uint32_t *)0x4000CFC8))


#define GPIOAFSEL_K    (*((volatile uint32_t *)0x40061420))
#define GPIOPCTL_K     (*((volatile uint32_t *)0x4006152C))
#define GPIODEN_K      (*((volatile uint32_t *)0x4006151C))
#define GPIOAMSEL_K    (*((volatile uint32_t *)0x40061528))

#define UART4CTL       (*((volatile uint32_t *)0x40010030))
#define UART4IBRD      (*((volatile uint32_t *)0x40010024))
#define UART4FBRD      (*((volatile uint32_t *)0x40010028))
#define UART4LCRH      (*((volatile uint32_t *)0x4001002C))
#define UART4IM        (*((volatile uint32_t *)0x40010038))
#define UART4MIS       (*((volatile uint32_t *)0x40010040))
#define UART4DR        (*((volatile uint32_t *)0x40010000))
#define UART4ICR       (*((volatile uint32_t *)0x40010044))
#define UART4FR         (*((volatile uint32_t *)0x40010018))




#endif // __HEADER1_H__
