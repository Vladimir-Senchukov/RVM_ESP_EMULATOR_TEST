#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "command_handler.h"
#include "comunication.h"


void app_main(void) {
    communication_task_init();
}

