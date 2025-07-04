#ifndef RS_485_H
#define RS_485_H
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#define RS_485_UART_NUM UART_NUM_1

extern QueueHandle_t rs_485_rx_queue;

typedef enum{
    RS_485_OK = 0,
    RS_485_ERROR = 1
}rs_485_status_t;

rs_485_status_t rs_485_init(void);
rs_485_status_t rs_485_set_rx_mode(void);
rs_485_status_t rs_485_set_tx_mode(void);

#endif