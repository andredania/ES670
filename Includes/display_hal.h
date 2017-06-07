/* ***************************************************************** 	*/
/* File name:        display_hal.h                           	     	*/
/* File description: Header file containing the function/methods     	*/
/*                   prototypes of display_hal.c                    	*/
/* Author name:      Andre Marcus                                 		*/
/* Creation date:    25mar2016                                       	*/
/* Revision date:    25mar2016                                       	*/
/* ***************************************************************** 	*/

#ifndef DISPLAY_HAL_H_
#define DISPLAY_HAL_H_

/* ************************************************ 		*/
/* Method name:        display_init                 		*/
/* Method description: Inicializa o modulo de display  		*/
/* Input params:       n/a									*/
/* Output params:      n/a                          		*/
/* ************************************************ 		*/
void display_init(void);

/* *********************************************					*/
/* Method name:        display_valor								*/
/* Method description: Define o valor que sera colocado no display	*/
/* Input params:       numero para colocar							*/
/* Outpu params:       n/a											*/
/* **********************************************					*/
void display_valor(int valor);

/* ************************************************ 		*/
/* Method name:        display_liga                 		*/
/* Method description: Habilita o display           		*/
/* Input params:       numero do display que sera ligado	*/
/* Output params:      n/a                          		*/
/* ************************************************ 		*/
void display_liga(int display);

/* ************************************************ 		*/
/* Method name:        display_desliga                 		*/
/* Method description: Desabilita o display           		*/
/* Input params:       numero do display que sera desligado	*/
/* Output params:      n/a                          		*/
/* ************************************************ 		*/
void display_desliga(int display);

#endif
