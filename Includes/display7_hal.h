/* ***************************************************************** */
/* File name:        display7_hal.h                                  */
/* File description: Header file containing the function/methods     */
/*                   prototypes of display7_hal.c                    */
/* Author name:      Paulo e Marcus                                 */
/* Creation date:    30mar2016                                       */
/* Revision date:    30mar2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_DISPLAY7_HAL_H_
#define SOURCES_DISPLAY7_HAL_H_

/* ************************************************ */
/* Method name:        display7_init                */
/* Method description: inicializa o display de 7 segmentos
/* Input params:       void							*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7_init(void);

/* *********************************************
* Method name:        display7_clearDisplay
* Method description: liga display
* Input params:       numero do display
* Outpu params:       n/a
************************************************/
void display_valor(int numero);

/* *********************************************
* Method name:        display7_clearDisplay
* Method description: liga display
* Input params:       numero do display
* Outpu params:       n/a
************************************************/
void display_desliga(int display);


/* *********************************************
* Method name:        display7_setValue
* Method description: coloca numero nos displays
* Input params:       numero para colocar
* Outpu params:       n/a
************************************************/
void display_liga(int valor);

#endif /* SOURCES_DISPLAY7_HAL_H_ */
