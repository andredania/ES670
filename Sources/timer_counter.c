#include "es670_peripheral_board.h"
#include "fsl_tpm_hal.h"

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */
void timer_initTPM1AsPWM(void)
{
	/* un-gate port clock*/
	SIM_SCGC6 |= SIM_SCGC6_TPM1(1); //Enable clock for TPM1

	TPM1_SC |= TPM_SC_CPWMS(0);   //up counting mode
	TPM1_SC |= TPM_SC_CMOD(1);   //LPTPM Counter increments on every LPTPM counter clock
	TPM1_SC |= TPM_SC_PS(0);   //Prescale 1:1

	TPM1_C1SC |=  TPM_CnSC_MSA(0) | TPM_CnSC_MSB(1) | TPM_CnSC_ELSA(0) | TPM_CnSC_ELSB(1)|  TPM_CnSC_CHIE(1);

	TPM1_CNT = 0;
	TPM1_MOD = 2000;
//	TPM1_C1V = 15; //PWM 100%
//	TPM1_C1V = ??; //PWM 75%
//	TPM1_C1V = ??; //PWM 50%
//	TPM1_C1V = ??; //PWM 25%
//	TPM1_C1V = ??; //PWM 0%


}

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR13 |= PORT_PCR_MUX(3);

}

int timer_DutyCycle_value(int DutyCycle){
	if(100.1 >= DutyCycle && -0.1 <= DutyCycle){
			TPM1_C1V = (int)(20*DutyCycle);
			return 1;
		}
		return 0;
}
