#include "command_handler.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "rvm_protocol_types.h"
#include "json_command_dto_for_tests.h"
#include "comunication.h"



command_handler_status_t command_handler(int cmd){
    
    switch (cmd)
    {
    case CMD_OPEN_DIAPHRAGM:
    
        ESP_LOGI("command_handler", "start command: CMD_CLOSE_DIAPHRAGM");
        vTaskDelay(CONFIG_CMD_OPEN_DIAPHRAGM_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_OPEN_DIAPHRAGM_JSON_DTO, portMAX_DELAY);
        break;

    case CMD_CLOSE_DIAPHRAGM:
        ESP_LOGI("command_handler", "start command: CMD_CLOSE_DIAPHRAGM");
        vTaskDelay(CONFIG_CMD_CLOSE_DIAPHRAGM_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_CLOSE_DIAPHRAGM_JSON_DTO, portMAX_DELAY);
        break;

    case CMD_LED_GREEN:
        ESP_LOGI("command_handler", "start command: CMD_LED_GREEN");
        vTaskDelay(CONFIG_CMD_LED_GREEN_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_LED_GREEN_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_LED_RED:
        ESP_LOGI("command_handler", "start command: CMD_LED_RED");
        vTaskDelay(CONFIG_CMD_LED_RED_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_LED_RED_JSON_DTO, portMAX_DELAY);
        break;

    case CMD_GET_BOTTLE_STATUS:
        ESP_LOGI("command_handler", "start command: CMD_GET_BOTTLE_STATUS");
        vTaskDelay(CONFIG_CMD_GET_BOTTLE_STATUS_COMMAND_NOT_READY_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_GET_BOTTLE_STATUS_JSON_DTO, portMAX_DELAY);
        break;
        
    case CMD_GET_BARCODE:
        ESP_LOGI("command_handler", "start command: CMD_GET_BARCODE");
        vTaskDelay(CONFIG_CMD_GET_BARCODE_COMMAND_NOT_READY_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_GET_BARCODE_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_SHAFTS_ON:
        ESP_LOGI("command_handler", "start command: CMD_SHAFTS_ON");
        vTaskDelay(CONFIG_CMD_SHAFTS_ON_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_SHAFTS_ON_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_SHAFTS_OFF:
        ESP_LOGI("command_handler", "start command: CMD_SHAFTS_OFF");
        vTaskDelay(CONFIG_CMD_SHAFTS_OFF_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_SHAFTS_OFF_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_OPEN_SHAFTS:
        ESP_LOGI("command_handler", "start command: CMD_OPEN_SHAFTS");
        vTaskDelay(CONFIG_CMD_OPEN_SHAFTS_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_OPEN_SHAFTS_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_CLOSE_SHAFTS:
        ESP_LOGI("command_handler", "start command: CMD_CLOSE_SHAFTS");
        vTaskDelay(CONFIG_CMD_CLOSE_SHAFTS_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_CLOSE_SHAFTS_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_IS_BOTTLE_FALL:
        ESP_LOGI("command_handler", "start command: CMD_IS_BOTTLE_FALL");
        vTaskDelay(CONFIG_CMD_IS_BOTTLE_FALL_COMMAND_NOT_READY_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_IS_BOTTLE_FALL_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_ON_SHREDER:
        ESP_LOGI("command_handler", "start command: CMD_ON_SHREDER");
        vTaskDelay(CONFIG_CMD_ON_SHREDER_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_ON_SHREDER_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_OFF_SHREDER:
        ESP_LOGI("command_handler", "start command: CMD_OFF_SHREDER");
        vTaskDelay(CONFIG_CMD_OFF_SHREDER_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_OFF_SHREDER_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_GET_COMMAND_STATUS:
        ESP_LOGI("command_handler", "start command: CMD_GET_COMMAND_STATUS");
        vTaskDelay(CONFIG_CMD_GET_COMMAND_STATUS_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_GET_COMMAND_STATUS_JSON_DTO, portMAX_DELAY);

        break;
    case CMD_GET_ALERT_DATA:
        ESP_LOGI("command_handler", "start command: CMD_GET_ALERT_DATA");
        vTaskDelay(CONFIG_CMD_GET_ALERT_DATA_COMMAND_ANSWER_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_GET_ALERT_DATA_JSON_DTO, portMAX_DELAY);
        break;
    case CMD_IS_HAND_NOT_IN:
        ESP_LOGI("command_handler", "start command: CMD_IS_HAND_NOT_IN");
        vTaskDelay(CONFIG_CMD_IS_HAND_IN_COMMAND_NOT_READY_TIMEOUT / portTICK_PERIOD_MS);
        xQueueSend(tx_json_dto_queue, &CMD_IS_HAND_NOT_IN_JSON_DTO, portMAX_DELAY);

        break;
    default:
        ESP_LOGE("command_hendler", "Unknown command: %d", cmd);
        break;
    }

    return COMMAND_HANDLER_OK;
}
