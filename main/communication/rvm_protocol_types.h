#ifndef RVM_PROTOCOL_TYPES_H
#define RVM_PROTOCOL_TYPES_H
#include <stdint.h>

extern const uint32_t ESP_MOTOR_ADDRESS;
extern const uint32_t ESP_MOTOR_PERIPH_ADDRESS;

typedef enum {
    CMD_OPEN_DIAPHRAGM = 1,  // Открыть диафрагму
    CMD_CLOSE_DIAPHRAGM = 2, // Закрыть диафрагму

    CMD_LED_GREEN = 3, // Включить зеленый светодиод
    CMD_LED_RED = 4,  // Включить красный светодиод

    CMD_GET_BOTTLE_STATUS = 5, // Получить статус бутылки

    CMD_GET_BARCODE = 6, // Получить штрих-код

    CMD_SHAFTS_ON = 7,  // Запустить валы(shafts)
    CMD_SHAFTS_OFF = 8, // Остановить валы

    CMD_OPEN_SHAFTS = 9, // Раздвинуть валы
    CMD_CLOSE_SHAFTS = 10, // Сдвинуть валы

    CMD_IS_BOTTLE_FALL = 11,// Чи впала пляшка

    CMD_ON_SHREDER = 12, // Включить шредер
    CMD_OFF_SHREDER = 13, // Выключить шредер

    CMD_GET_COMMAND_STATUS = 14, // Запит статусу по виконанню команд при цій команді в полі data треба вказати номер команди і тоді ESP32 віддасть останній статус по тій команді
    
    CMD_GET_ALERT_DATA = 15,

    CMD_IS_HAND_NOT_IN = 16
} commands_t;

typedef enum {
    CMD_STATUS_OK = 0,
    CMD_STATUS_NONE = 1,
    CMD_STATUS_ERROR = 2,
    CMD_STATUS_NOT_READY = 3
} status_t;

//////////////////////////////////////
extern const char* data_standart_names[];

typedef enum {
    DATA_OK = 0,
    DATA_ERROR = 1
} data_standart_t;

/////////////////////////////////////
extern const char* data_cmd_5_get_bottle_status_names[];
typedef enum{
    DATA_CMD_5_NO_BARCODE = 0,
    DATA_CMD_5_HEAVY_WEIGHT = 1,
} data_cmd_5_get_bottle_status;

/////////////////////////////////////

typedef struct{
    uint32_t address;
    commands_t COMMAND;
    status_t STATUS;
    char* data;
}json_dto_t;

#endif