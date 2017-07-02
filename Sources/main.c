/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: main file of the project                        */
/* Author name:      mGuimar pDania                                 */
/* Creation date:    06apr2016                                       */
/* Revision date:    29jun2017                                       */
/* ***************************************************************** */

/* system includes */
#include "fsl_device_registers.h"
#include "buzzer_hal.h"
#include "ledswi_hal.h"
#include "lcd_hal.h"
#include "timer_counter.h"
#include "mcg_hal.h"
#include "tc_hal.h"
#include "stdio.h"
#include "display7_hal.h"
#include "util.h"
#include "fsl_debug_console.h"
#include "debugUart.h"
#include "protocolo.h"
#include "tacometro_hal.h"
#include "cooler_hal.h"
#include "lut_adc.h"
#include "heater_hal.h"
#include "controle.h"

/* defines */
#define CYCLIC_EXECUTIVE_PERIOD          200 * 1000 /* 1 second */
/* typedefs */


/* globals */
/* cyclic executive flag */
volatile unsigned int uiFlagNextPeriod = 0;

/* Char that receives bytes from the serial connection */
char uiReceiveBuff;

struct_PID_data controlePID;

double dreferencia = 50;

double dcoolerPWM = 0;

int iaux;

/* Methods */

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


void UART0_IRQHandler(void){
	GetMsg_Protocolo(GETCHAR());
}



/* ************************************************ */
/* Method name:        initBoard                    */
/* Method description: initialize peripherals       */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int initBoard(void){
}

int main(void)
{
    /*  inicializacoes */
	mcg_clockInit();
	tacometro_init();
	debugUart_init();
	lcd_initLcd();
	lcd_setCursor(0,0);
	timer_initTPM1AsPWM();
	timer_coolerfan_init();
	//initAdc();
	cooler_init();
	initSpeedController(&controlePID);


    /* configure cyclic executive interruption */
    tc_installLptmr0(CYCLIC_EXECUTIVE_PERIOD, main_cyclicExecuteIsr);

    timer_DutyCycle_value(100);

	//lab06heater_initTPM1AsPWM();

	//lab06heater_setDutyCycle(50);

    iaux=0;


    for (;;) {

    	/* Auxiliary variable to print sentences in the LCD display */
    	char cTemp[50];

    	double iRPS = ((double)(TPM0_CNT*1000*1000))/((double)(7*CYCLIC_EXECUTIVE_PERIOD));

    	/* Escreve o valor da variável no display lcd */
    	lcd_setCursor(0,0);
    	lcd_writeString(cTemp);

    	/* Reinicializa o contador do tacometro */
    	TPM0_CNT = 0;

		//int value;
		//value = valor();

    	dcoolerPWM += (int)PIDUpdate(&controlePID,iRPS,dreferencia);
    	timer_DutyCycle_value(dcoolerPWM);
		//Lab06PRINTF("Dado bruto:  %d\r\n",value);
		//Lab06PRINTF("Temperatura: %d°C\r\n\n",consultaTabela(value));

    	/* Coloca o valor da velocidade numa variável char * */
    	    	sprintf(cTemp,"RPS: %d ",(int)iRPS);


        /* WAIT FOR CYCLIC EXECUTIVE PERIOD */
        while(!uiFlagNextPeriod);
        uiFlagNextPeriod = 0;
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
