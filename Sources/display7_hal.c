/* ***************************************************************** */
/* File name:        display7_hal.c                                  */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related display7 from the peripheral board      */
/* Author name:      pherig mgazzone                                 */
/* Creation date:    28mar2016                                       */
/* Revision date:    28mar2016                                       */
/* ***************************************************************** */

#include "display7_hal.h"
#include "es670_peripheral_board.h"

/* system includes */
#include <MKL25Z4.h>
#include <util.h>


/* ************************************************ */
/* Method name:        display7_init                */
/* Method description: inicializa o display de 7 segmentos
/* Input params:       void							*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7_init(void){

	/* un-gate port clock */
	SIM_SCGC5 |= SIM_SCGC5_PORTC(0x01);

	/* set alternate function to gpio */
	PORTC_PCR0 = PORT_PCR_MUX(0x01);
	PORTC_PCR1 = PORT_PCR_MUX(0x01);
	PORTC_PCR2 = PORT_PCR_MUX(0x01);
	PORTC_PCR3 = PORT_PCR_MUX(0x01);
	PORTC_PCR4 = PORT_PCR_MUX(0x01);
	PORTC_PCR5 = PORT_PCR_MUX(0x01);
	PORTC_PCR6 = PORT_PCR_MUX(0x01);
	PORTC_PCR7 = PORT_PCR_MUX(0x01);

	PORTC_PCR13 = PORT_PCR_MUX(0x01);
	PORTC_PCR12 = PORT_PCR_MUX(0x01);
	PORTC_PCR11 = PORT_PCR_MUX(0x01);
	PORTC_PCR10 = PORT_PCR_MUX(0x01);

	/* Set pins as GPOs */
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(0));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(1));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(2));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(3));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(4));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(5));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(6));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(7));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(10));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(11));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(12));
	GPIOC_PDDR |= GPIO_PDDR_PDD(DISPLAY7_DIR(13));

}




/* *********************************************
* Method name:        display7_clearDisplay
* Method description: liga display
* Input params:       numero do display
* Outpu params:       n/a
************************************************/
void display_liga(int display){
	int num = display + 9;
	GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << num);
}


/* *********************************************
* Method name:        display7_clearDisplay
* Method description: desliga display
* Input params:       numero do display
* Outpu params:       n/a
************************************************/
void display_desliga(int display){
	int num = display + 9;
	GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << num);
}


/* *********************************************					*/
/* Method name:        display_valor								*/
/* Method description: Define o valor que sera colocado no display	*/
/* Input params:       numero para colocar							*/
/* Outpu params:       n/a											*/
/* **********************************************					*/
void display_valor(int valor){

	switch(valor){
		case 0: //Escreve 0 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 1: //Escreve 1 no display
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 5);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 2: //Escreve 2 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 3: //Escreve 3 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 4: //Escreve 4 no display
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 5: //Escreve 5 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 6: //Escreve 6 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 7: //Escreve 7 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 5);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 8: //Escreve 8 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 9: //Escreve 9 no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'A': //Escreve A no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'B': //Escreve B no display
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'C': //Escreve C no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'D': //Escreve D no display
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'E': //Escreve E no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		case 'F': //Escreve F no display
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 1);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 2);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PCOR |= GPIO_PCOR_PTCO(0x01U << 7);
		break;
		default: //limpa todos os segmentos
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 0);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 1);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 2);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 3);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 4);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 5);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 6);
			GPIOC_PSOR |= GPIO_PSOR_PTSO(0x01U << 7);
		break;

	}
}
