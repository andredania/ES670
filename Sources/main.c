/* ***************************************************************** */
/* File name:        es670.c                                         */
/* File description: File dedicated to the ES670 prototype projects  */
/*                   involving the FRDM-KL25Z board together with is */
/*                   daughter board containing more peripherals      */
/*                                                                   */
/*                   Processor MKL25Z128VLK4 characteristics         */
/*                   48 MHz ARM Cortex-M0+ core                      */
/*                   128 KB program flash memory                     */
/*                   16 KB SRAM                                      */
/*                   Voltage range: 1.71 to 3.6 V                    */
/*                                                                   */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    09mai2017                                       */
/* ***************************************************************** */

/* our includes */
#include "es670_peripheral_board.h"
#include "buzzer_hal.h"
#include "ledswi_hal.h"
//#include "ledrgb_hal.h"
#include "lcd_hal.h"
#include "mcg_hal.h"
#include "tc_hal.h"
#include "debugUart.h"
#include "util.h"
#include "fsl_debug_console.h"
#include "tacometro_hal.h"
#include "cooler_hal.h"
#include "timer_counter.h"
#include "stdio.h"


/* defines */
#define CYCLIC_EXECUTIVE_PERIOD         1000 * 1000 /* 1000000 micro seconds */

/* globals */
volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
char aux[20];


/* ************************************************ */
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: cyclic executive interrupt   */
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */
    uiFlagNextPeriod = 1;
}


/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{

	/* Inicializa o clock */
	mcg_clockInit();

	/* Inicializa o lcd */
	lcd_initLcd();

	/* Inicializa o cooler */
	cooler_init();

	/* Turn the cooler ON */
	cooler_on();

	/* Inicializa o tacometro */
	tacometro_init();

    /* configure cyclic executive interruption */
    tc_installLptmr0(CYCLIC_EXECUTIVE_PERIOD, main_cyclicExecuteIsr);

    timer_initTPM1AsPWM();
    timer_coolerfan_init();
    timer_DutyCycle_value(25);

	for(;;){
		lcd_setCursor(1,0);
		sprintf(aux,"VELOCIDADE: %d rps",TPM0_CNT/7);
		lcd_writeString(aux);
		TPM0_CNT = 0;

		while(!uiFlagNextPeriod);
       			uiFlagNextPeriod = 0;
	}
	    /* Never leave main */
	    return 0;
}
