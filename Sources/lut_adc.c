
/* ***************************************************************** */
/* File name:        lut_adc.c                                       */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for ADC  from the                    */
/*                   peripheral board                                */
/* Author name:      Paulo e Marcus                                  */
/* Creation date:    12jan2016                                       */
/* Revision date:    21jan2016                                       */
/* ***************************************************************** */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                   TABELA PARA USO DO SENSOR DE TEMPERATURA            *
 *                   modificado para o range 0 - 3v3                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "es670_peripheral_board.h"
#include <stdbool.h>
#include <MKL25Z4.h>
#define ADC_CONVERTION_DONE 1
#define ADC_CONVERTION_PROCESSING 0


const unsigned char tabela_temp[256] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,					//15
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,					//31
		1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6,					//47
		7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10, 10, 11, 11, 12, 12,			//63
		12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17,	//79
		17, 18, 18, 19, 19, 19, 19, 20, 20, 21, 21, 21, 21, 22, 22, 23,	//95
		23, 24, 24, 24, 24, 25, 25, 26, 26, 26, 26, 27, 27, 28, 28, 28,	//111
		28, 29, 29, 30, 30, 30, 30, 31, 31, 32, 32, 32, 32, 33, 33, 34,	//127
		34, 35, 35, 35, 35, 36, 36, 37, 37, 37, 37, 38, 38, 39, 39, 39,	//143
		39, 40, 40, 41, 41, 41, 41, 42, 42, 43, 43, 44, 44, 44, 44, 45,	//159
		45, 46, 46, 46, 46, 47, 47, 48, 48, 48, 48, 49, 49, 50, 50, 50,	//175
		50, 51, 51, 52, 52, 53, 53, 53, 53, 54, 54, 55, 55, 55, 55, 56,	//191
		56, 57, 57, 57, 57, 58, 58, 59, 59, 59, 59, 60, 60, 61, 61, 62,	//207
		62, 62, 62, 63, 63, 64, 64, 64, 64, 65, 65, 66, 66, 66, 66, 67,	//223
		67, 68, 68, 68, 68, 69, 69, 70, 70, 71, 71, 71, 71, 72, 72, 72,	//239
		73, 73, 73, 73, 74, 74, 75, 75, 75, 75, 76, 76, 77, 77, 77, 77	//255
};


/* ************************************************ */
/* Method name:        initADC                */
/* Method description:  Inicializa ADC           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void initAdc(void){

    SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);
	
	//Enable clock for ADC0
	SIM_SCGC6 |= SIM_SCGC6_ADC0(CGC_CLOCK_ENABLED); 

	// Configura função alternativa
    PORTE_PCR21 = PORT_PCR_MUX(0);

	//porta SE4a: Single-ended, canal 4, lado A
	//Configura canal 4
	ADC0_SC1A = ADC_SC1_ADCH(4);

	//Baseado no datasheet
	ADC0_CFG1 = 0;
	ADC0_CFG2 = 0;

}
/* ************************************************ */
/* Method name:        conversaoAdc                 */
/* Method description:  Conversao do valor           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
volatile int conversaoAdc(void){
	return ADC0_SC1A & 0x80;
}

/* ************************************************ */
/* Method name:        initConversao                 */
/* Method description:  Inicia conversao           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void initConversao(void){
	//Configura canal 4
	ADC0_SC1A = ADC_SC1_ADCH(4);
}

/* ************************************************ */
/* Method name:        valor                */
/* Method description: Retorna valor           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int valor(void){
	return ADC0_RA;
}

/* ************************************************ */
/* Method name:       consultaTabela               */
/* Method description: Compara valor na tabela de acordo com variavel "value"*/
/* Input params:      value                       */
/* Output params:      n/a                          */
/* ************************************************ */
int consultaTabela(int value){
	return tabela_temp[value];
}

/* ************************************************ */
/* Method name:       v              */
/* Method description: Executa conversao*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int valorAdc(void){
	initConversao();
	while(conversaoAdc());
	return valor();
}

