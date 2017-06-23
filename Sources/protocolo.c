/* ***************************************************************** */
/* File name:        protocol.c                                      */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related to protocol                             */
/* Author name:      mGuimar pDania                                 */
/* Creation date:    06apr2016                                       */
/* Revision date:    06apr2016                                       */
/* ***************************************************************** */

#include "protocolo.h"
#include "fsl_debug_console.h"
#include "ledswi_hal.h"
#include "buzzer_hal.h"
#include "timer_cooler.h"

#define CHAR_JOKER '&'

/*
 * Method name:        initProtocol
 *
 * Method description: Inicializa o protocolo
 *
 * Input params:       n/a
 * Output params:      n/a
 *
 */
void initProtocolo(void){
	current_state = waiting_state;
	next_state = current_state;
	led_set = false;
	led_states[0] = false;
	led_states[1] = false;
	led_states[2] = false;
	led_states[3] = false;
	return;
}


/*
 * Method name:        updateProtocol
 *
 * Method description: Input to the protocol
 *
 * Input params:       cMsg - Protocolo recebe o caracter
 * Output params:      n/a
 *
 */
void GetMsg_Protocolo(char cMsg){
	current_state = next_state;
	int num;
	if(CHAR_JOKER == cMsg){
		next_state = waiting_state;
		return;
	}
	switch(current_state){
		case  waiting_state:
			switch((int) cMsg){
				case 'L':
					next_state = led_action_state;
					break;
				case 'S':
					next_state = switch_num_state;
					break;
				case 'B':
					next_state = buzzer_state;
					buzzer_count_digits = 0;
					buzzer_milliseconds = 0;
					break;
				case 'C':
					next_state = cooler_state;
					cooler_count_digits = 0;
					cooler_duty = 0;
					break;
				default:
					Answer_Procotolo(err_answer);
					break;
			}
			break;
		case  led_action_state:
			switch((int) cMsg){
				case 'C':
					led_set = false;
					next_state = led_num_state;
					break;
				case 'S':
					led_set = true;
					next_state = led_num_state;
					break;
				default:
					Answer_Procotolo(err_answer);
					next_state = waiting_state;
					break;
			}
			break;
		case  led_num_state:
			next_state = waiting_state;
			 num =(int) cMsg - '0';
			if(num <=4 && num >= 1){
				Answer_Procotolo(ack_answer);
				led_states[num-1] = led_set;
				ledState_Protocolo();
			}else{
				Answer_Procotolo(err_answer);
			}
		break;
		case  switch_num_state:
			num =(int) cMsg - '0';
			next_state = waiting_state;
			if(num <=4 && num >= 1){
				Answer_Procotolo(ack_answer);
				ledswi_initLedSwitch(0,4);
				if(!(int) ledswi_getSwitchStatus(num)){
					PRINTF("O");
				}else{
					PRINTF("C");
				}
				ledswi_initLedSwitch(4,0);
				ledState_Protocolo();
			}else{
				Answer_Procotolo(err_answer);
			}
		break;
		case  buzzer_state:
			num =(int) cMsg - '0';
			if(num <=9 && num >= 0){
				buzzer_milliseconds = buzzer_milliseconds * 10 + num;
				buzzer_count_digits++;
				if(buzzer_count_digits == 4){
					Answer_Procotolo(ack_answer);
					next_state = waiting_state;
					buzzer_setBuzzer(buzzer_milliseconds);
				}
			}else{
				next_state = waiting_state;
				Answer_Procotolo(err_answer);
			}
		break;
		case  cooler_state:
			num =(int) cMsg - '0';
			if(num <=9 && num >= 0){
				cooler_duty = cooler_duty * 10 + num;
				cooler_count_digits++;
				if(cooler_count_digits == 3){
					if(timer_coolerfan_setDutyCycle(cooler_duty)){
						Answer_Procotolo(ack_answer);
					}else{
						Answer_Procotolo(err_answer);
					}
					next_state = waiting_state;
				}
			}else{
				next_state = waiting_state;
				Answer_Procotolo(err_answer);
			}
		break;
		default:
			next_state = waiting_state;
			Answer_Procotolo(err_answer);
			break;
	}
}

/*
 * Method name:        sendAnswer
 *
 * Method description: return ACK ou ERR
 *
 * Input params:       atVar - status da mensagem
 * Output params:      n/a
 *
 */
void Answer_Procotolo(answersType atVar){
	if(atVar == ack_answer){
		PRINTF("ACK");
	}else{
		PRINTF("ERR");
	}
}

/*
 * Method name:        updateLeds
 *
 * Method description:  Define o estado dos LED's
 *
 * Input params:       n/a
 * Output params:      n/a
 *
 */
void ledState_Protocolo(void){
	for(int i = 0;i<4;i++){
		if(led_states[i]){
			ledswi_setLed(i+1);
		}else{
			ledswi_clearLed(i+1);
		}

	}
}
