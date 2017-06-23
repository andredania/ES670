#ifndef INCLUDES_LTU_ADC_HAL_H_
#define INCLUDES_LTU_ADC_HAL_H_

/* ************************************************ */
/* Method name:        initAdc                */
/* Method description:  Inicializa ADC           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void initAdc(void);

/* ************************************************ */
/* Method name:        conversaoAdc                 */
/* Method description:  Conversao do valor           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
volatile int conversaoAdc(void);

/* ************************************************ */
/* Method name:        init_conversao                 */
/* Method description:  Inicia conversao           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void init_conversao(void);

/* ************************************************ */
/* Method name:        valor                */
/* Method description: Retorna valor           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int valor(void);

/* ************************************************ */
/* Method name:       consultaTabela               */
/* Method description: Compara valor na tabela de acordo com variavel "value"*/
/* Input params:      value                       */
/* Output params:      n/a                          */
/* ************************************************ */
int consultaTabela(int value);
/* ************************************************ */
/* Method name:      valorAdc              */
/* Method description: Executa conversao*/
/* Input params:        n/a                         */
/* Output params:      n/a                          */
/* ************************************************ */
int valorAdc(void);

#endif
