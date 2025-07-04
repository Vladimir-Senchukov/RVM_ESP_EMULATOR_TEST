#include "esp_log.h"
#include "comunication.h"
#include "rs_485_driver.h"
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "command_json_parser.h"
#include "rvm_protocol_types.h"
#include "cJSON.h"
#include <inttypes.h>
#include <string.h>
#include "command_handler.h"

static json_dto_t rx_json_command_dto;

static json_dto_t tx_json_command_dto;

QueueHandle_t tx_json_dto_queue;

static void communication_rs485_rx_task(void *arg)
{
    uart_event_t uart_event;
    rs_485_init();
    ESP_LOGI("communication_rs485_rx_task", "RX task init");

    while (1)
    {
        rs_485_set_rx_mode();
        ESP_LOGI("communication_rs485_rx_task", "RX task Before Reciev");
        xQueueReceive(rs_485_rx_queue, (void *)&uart_event, portMAX_DELAY);

        if (uart_event.type == UART_DATA)
        {
            ESP_LOGI("/////////", "///////////////////////");
            uint8_t data[1024];
            uint32_t lenght = uart_read_bytes(RS_485_UART_NUM, data, sizeof(data), 0);
            data[lenght] = '\0';
            ESP_LOGI("communication_rs485_rx_task", "Reciev string JSON: %s", (char *)data);

            parse_string_to_json_struct(&rx_json_command_dto, (char *)data);

                command_handler(rx_json_command_dto.COMMAND);
            
        }
    }
}

void communication_rs485_tx_task(void *arg)
{

    tx_json_dto_queue = xQueueCreate(1, sizeof(json_dto_t));
    ESP_LOGI("communication_rs485_tx_task", "TX task init");

    while (1)
    {
        xQueueReceive(tx_json_dto_queue, &tx_json_command_dto, portMAX_DELAY);
        rs_485_set_tx_mode();

        ESP_LOGI("communication_rs485_tx_task", "recieved answer from command %d", tx_json_command_dto.COMMAND);

        char *json_string_pointer = NULL;

        parse_json_struct_to_string(&tx_json_command_dto, &json_string_pointer);
        uart_write_bytes(RS_485_UART_NUM, json_string_pointer, strlen(json_string_pointer));
        vTaskDelay(300/portTICK_PERIOD_MS);
        ESP_LOGI("communication_rs485_tx_task", "Transmited to RS485 %s", json_string_pointer);

        free(json_string_pointer); // Обов’язково звільняємо пам’ять
        json_string_pointer = NULL;

        rs_485_set_rx_mode();
        ESP_LOGI("communication_rs485_tx_task", "END");

    }
}

void communication_task_init()
{
    xTaskCreate(communication_rs485_rx_task, "communication_rs485_rx_task", 2048 * 5, NULL, 1, NULL);
    xTaskCreate(communication_rs485_tx_task, "communication_rs485_tx_task", 2048 * 5, NULL, 1, NULL);
}
