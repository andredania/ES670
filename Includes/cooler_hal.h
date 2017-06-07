/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling COOLER from the         */
/*                   peripheral board                                */
/* ***************************************************************** */

#ifndef SOURCES_COOLER_HAL_H_
#define SOURCES_COOLER_HAL_H_

/* ************************************************ */
/* Method name:        cooler_init                  */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_init(void);


/* ************************************************ */
/* Method name:        cooler_off                   */
/* Method description: turn off the cooler          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_off(void);


/* ************************************************ */
/* Method name:        cooler_on                    */
/* Method description: Set the cooler               */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_on(void);



#endif /* SOURCES_BUZZER_HAL_H_ */
