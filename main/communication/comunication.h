#ifndef COMUNICATION_H
#define COMUNICATION_H
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t tx_json_dto_queue;

typedef enum {
    COMMUNICATION_OK = 0,
    COMMUNICATION_ERROR = 1
}communication_status_t;

void communication_task_init();

#endif 