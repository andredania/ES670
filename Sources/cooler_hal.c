/* ***************************************************************** */
/* File name:        cooler_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related cooler from the peripheral board        */
/* ***************************************************************** */

#include "cooler_hal.h"
#include "es670_peripheral_board.h"
#include <MKL25Z4.h>


/* ************************************************ */
/* Method name:        cooler_init                  */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_init(void)
{
    SIM_SCGC5 |= SIM_SCGC5_PORTA(0x01); //ungate port clock
    PORTA_PCR0 = PORT_PCR_MUX(0x01); //set pin as gpio
    GPIOA_PDDR = GPIO_PDDR_PDD(0x01 << 13); //set pin as digital output
}

/* ************************************************ */
/* Method name:        cooler_off                   */
/* Method description: Turn the cooler off          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_off(void)
{
    GPIOA_PCOR = GPIO_PCOR_PTCO(0x01 << 13);
}

/* ************************************************ */
/* Method name:        cooler_on                    */
/* Method description: Turn the cooler o            */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_on(void)
{
    GPIOA_PSOR = GPIO_PSOR_PTSO(0x01 << 13);
}
