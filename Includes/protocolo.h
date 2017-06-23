/* ***************************************************************** */
/* File name:        protocol.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling messages                */
/* Author name:      Paulo e Marcus                                 */
/* Creation date:    06apr2016                                       */
/* Revision date:    06apr2016                                       */
/* ***************************************************************** */

#ifndef INCLUDES_PROTOCOL_HAL_H_
#define INCLUDES_PROTOCOL_HAL_H_


int led_set;
int led_states[4];

int buzzer_count_digits;
int buzzer_milliseconds;

int cooler_count_digits;
int cooler_duty;

typedef enum Answers {
	  err_answer         = 0,
	  ack_answer         = 1
} answersType;

/*State machine variables*/
typedef enum Statess {
	  waiting_state            = 0,
	  led_action_state         = 1,
	  led_num_state            = 2,
	  switch_num_state         = 3,
	  buzzer_state             = 4,
	  cooler_state             = 5
} States_Type;


States_Type current_state;
States_Type next_state;


/*
 * Method name:        initProtocol
 *
 * Method description: Inicializa o protocolo
 *
 * Input params:       n/a
 * Output params:      n/a
 *
 */
void initProtocolo(void);


/*
 * Method name:        updateProtocol
 *
 * Method description: Input to the protocol
 *
 * Input params:       cMsg - Protocolo recebe o caracter
 * Output params:      n/a
 *
 */
void GetMsg_Protocolo(char cMsg);

/*
 * Method name:        sendAnswer
 *
 * Method description: return ACK ou ERR
 *
 * Input params:       atVar - status da mensagem
 * Output params:      n/a
 *
 */
void Answer_Procotolo(answersType atVar);

/*
 * Method name:        updateLeds
 *
 * Method description:  Define o estado dos LED's
 *
 * Input params:       n/a
 * Output params:      n/a
 *
 */
void ledState_Protocolo(void);

/*
 * Method name:        setBuzzer
 *
 * Method description:  Aciona o buzzer
 *
 * Input params:       iMilli - Tempo que o buzzer ficará acionado
 * Output params:      n/a
 *
 */
void setBuzzer(int iMilli);


#endif /* INCLUDES_PROTOCOLO_HAL_H_ */
