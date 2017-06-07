/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */


/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT        PORTD                                   /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT        PTD                                     /* peripheral gpio base pointer */

#define BUZZER_PIN                  0U                                      /* buzzer pin */
#define BUZZER_DIR                  kGpioDigitalOutput
#define BUZZER_ALT                  0x01u
/*                 END OF BUZZER definitions             */


/*                 LED and SWITCH Definitions                    */
#define LS_PORT_BASE_PNT            PORTA                                   /* peripheral port base pointer */
#define LS_GPIO_BASE_PNT            PTA                                     /* peripheral gpio base pointer */

/* THIS PIN CONFLICTS WITH PTA1 USED AS UART0_RX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS1_PIN                     1U                                      /* led/switch #1 pin */
#define LS1_DIR_OUTPUT              (GPIO_OUTPUT << LS1_PIN)
#define LS1_DIR_INPUT               (GPIO_OUTPUT << LS1_PIN)
#define LS1_ALT                     0x01u                                   /* GPIO alternative */

/* THIS PIN CONFLICTS WITH PTA2 USED AS UART0_TX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS2_PIN                     2U                                      /* led/switch #2 pin */
#define LS2_DIR_OUTPUT              (GPIO_OUTPUT << LS2_PIN)
#define LS2_DIR_INPUT               (GPIO_OUTPUT << LS2_PIN)
#define LS2_ALT                     LS1_ALT

#define LS3_PIN                     4U                                      /* led/switch #3 pin */
#define LS3_DIR_OUTPUT              (GPIO_OUTPUT << LS3_PIN)
#define LS3_DIR_INPUT               (GPIO_OUTPUT << LS3_PIN)
#define LS3_ALT                     LS1_ALT

#define LS4_PIN                     5U                                      /* led/switch #4 pin */
#define LS4_DIR_OUTPUT              (GPIO_OUTPUT << LS4_PIN)
#define LS4_DIR_INPUT               (GPIO_OUTPUT << LS4_PIN)
#define LS4_ALT                     LS1_ALT

/*                 END OF LED and SWITCH definitions             */



/*                 Display 7 segments Definitions                    */
#define DISPLAY7_PORT_BASE_PNT		PORTC                                   /* peripheral port base pointer */
#define DISPLAY7_GPIO_BASE_PNT		PTC                                     /* peripheral gpio base pointer */

#define DISPLAY7_PIN(X)         	X                                      /* led/switch #1 pin */
#define DISPLAY7_DIR(X)             (GPIO_OUTPUT << (X))
#define DISPLAY7_ALT             	0x01u
/*                 END OF LED and SWITCH definitions             */
                /* led/switch #1 pin */
#define LCD_DIR(X)             (GPIO_OUTPUT << (X))

/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT           PORTC                                   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

#define LCD_RS_PIN                  8U                                      /* register selector */
#define LCD_RS_DIR                  kGpioDigitalOutput
#define LCD_RS_ALT                  kPortMuxAsGpio

#define LCD_ENABLE_PIN              9U                                      /* enable pin */
#define LCD_ENABLE_DIR              kGpioDigitalOutput
#define LCD_ENABLE_ALT              kPortMuxAsGpio

#define LCD_RS_HIGH                 1U
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0U
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1U
#define LCD_DISABLED                0U

#define LCD_DATA_DIR                kGpioDigitalOutput                      /* LCD data pins */
#define LCD_DATA_ALT                kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0U
#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB3_PIN            3U
#define LCD_DATA_DB4_PIN            4U
#define LCD_DATA_DB5_PIN            5U
#define LCD_DATA_DB6_PIN            6U
#define LCD_DATA_DB7_PIN            7U
/*                 END OF LCD definitions                 */

#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
