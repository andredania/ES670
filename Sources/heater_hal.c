#include "es670_peripheral_board.h"
#include "fsl_tpm_hal.h"
#include "heater_hal.h"

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */
void heater_initTPM1AsPWM(void)
{
	/* un-gate port clock*/
	SIM_SCGC6 |= SIM_SCGC6_TPM1(1); //Enable clock for TPM1

	TPM1_SC |= TPM_SC_CPWMS(0);   //up counting mode
	TPM1_SC |= TPM_SC_CMOD(1);   //LPTPM Counter increments on every LPTPM counter clock
	TPM1_SC |= TPM_SC_PS(0);   //Prescale 1:1

	
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR12 |= PORT_PCR_MUX(3);
	
	TPM1_C0SC |= TPM_CnSC_MSA(0) | TPM_CnSC_MSB(1) | TPM_CnSC_ELSA(0) | TPM_CnSC_ELSB(1) | TPM_CnSC_CHIE(1); //modo de PWM Edge Aligned

	TPM1_CNT = 0;
	TPM1_MOD = 100;
	TPM1_C0V = 100; //PWM 100%


}

/* ************************************************ */
/* Method name:        heater_init                  */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */


int heater_setDutyCycle(int iValue){
	if(50 >= iValue && 0 <= iValue){
		TPM1_C0V = iValue;
		return 1;
	}
	return 0;
}

