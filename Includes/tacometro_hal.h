/* ***************************************************************** */
/* File name:        tacometro_hal.h                                 */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling TACOMETRO from the      */
/*                   peripheral board                                */
/* ***************************************************************** */

#ifndef SOURCES_TACOMETRO_HAL_H_
#define SOURCES_TACOMETRO_HAL_H_

/* *************************************************** */
/* Method name:        tacometro_init                  */
/* Method description: Initialize the tacometro device */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */

void tacometro_init(void);

/* ************************************************ */
/* Method name:        tacometro_cnt                */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

int tacometro_cnt(void);

#endif