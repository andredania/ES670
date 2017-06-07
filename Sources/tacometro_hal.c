/* ***************************************************************** */
/* File name:        tacometro_hal.c                                 */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related TACOMETRO from the peripheral board     */
/* ***************************************************************** */

#include <MKL25Z4.h>
#include "es670_peripheral_board.h"
#include "tacometro_hal.h"

/* *************************************************** */
/* Method name:        tacometro_init                  */
/* Method description: Initialize the TACOMETRO device */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */

void tacometro_init(void){

SIM_SCGC5 |= SIM_SCGC5_PORTE(1); //ungate port clock
SIM_SCGC6 |= SIM_SCGC6_TPM0(1); //ungate timer clock

PORTE_PCR29 = PORT_PCR_MUX(4); //set pin as timer

TPM0_SC |= TPM_SC_PS(0); //Seleção do PS
TPM0_SC |= TPM_SC_CMOD(2); //Seleção do modo do contador: contador incrementa com o rising edge do clock externo

SIM_SOPT2 |= SIM_SOPT2_TPMSRC(2); //TPM clock source selection: (OSCERCLK) clock a partir da oscilação de um módulo on-chip
SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(6); //seleciona o clock de saída (OSCERCLK)



SIM_SOPT4 |= SIM_SOPT4_TPM0CLKSEL(0); // Habilita o clock to timer
}


int tacometro_cnt(void){
	return TPM0_CNT;
}
