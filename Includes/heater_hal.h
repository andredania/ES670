
#ifndef INCLUDES_HEATER_H_
#define INCLUDES_HEATER_H_


/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */
void heater_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        heater_init                  */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void heater_init(void);

/* ************************************************ */
/* Method name:        heater_init                  */
/* Method description: Initialize the heater device */
/* Input params:       iDutyCycle - valor do duty cycle em % do heater*/
/* Output params:      n/a                          */
/* ************************************************ */

int heater_setDutyCycle(int iDutyCycle);

#endif
