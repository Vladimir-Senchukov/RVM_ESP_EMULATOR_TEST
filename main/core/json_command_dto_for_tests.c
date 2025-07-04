
#include "json_command_dto_for_tests.h"

json_dto_t CMD_OPEN_DIAPHRAGM_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_OPEN_DIAPHRAGM,
    #ifdef CONFIG_CMD_OPEN_DIAPHRAGM_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_OPEN_DIAPHRAGM_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_CLOSE_DIAPHRAGM_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_CLOSE_DIAPHRAGM,
    #ifdef CONFIG_CMD_CLOSE_DIAPHRAGM_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_CLOSE_DIAPHRAGM_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_LED_GREEN_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_LED_GREEN,
    #ifdef CONFIG_CMD_LED_GREEN_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_LED_GREEN_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_LED_RED_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_LED_RED,
    #ifdef CONFIG_CMD_LED_RED_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_LED_RED_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_GET_BOTTLE_STATUS_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_GET_BOTTLE_STATUS,
    #ifdef CONFIG_CMD_GET_BOTTLE_STATUS_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_GET_BOTTLE_STATUS_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = "HEAVY_WEIGHT"
    #elif defined(CONFIG_CMD_GET_BOTTLE_STATUS_STATUS_NOT_READY)
    .STATUS = CMD_STATUS_NOT_READY,
    .data = ""
    #endif
};

json_dto_t CMD_GET_BARCODE_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_GET_BARCODE,
    #ifdef CONFIG_CMD_GET_BARCODE_OK
    .STATUS = CMD_STATUS_OK,
    .data = "4823063126298"
    #elif defined(CONFIG_CMD_GET_BARCODE_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #elif defined(CONFIG_CMD_GET_BARCODE_STATUS_STATUS_NOT_READY)
    .STATUS = CMD_STATUS_NOT_READY,
    .data = ""
    #endif
};

json_dto_t CMD_SHAFTS_ON_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_SHAFTS_ON,
    #ifdef CONFIG_CMD_SHAFTS_ON_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_SHAFTS_ON_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_SHAFTS_OFF_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_SHAFTS_OFF,
    #ifdef CONFIG_CMD_SHAFTS_OFF_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_SHAFTS_OFF_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_OPEN_SHAFTS_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_OPEN_SHAFTS,
    #ifdef CONFIG_CMD_OPEN_SHAFTS_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_OPEN_SHAFTS_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_CLOSE_SHAFTS_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_CLOSE_SHAFTS,
    #ifdef CONFIG_CMD_CLOSE_SHAFTS_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_CLOSE_SHAFTS_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_IS_BOTTLE_FALL_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_IS_BOTTLE_FALL,
    #ifdef CONFIG_CMD_IS_BOTTLE_FALL_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_ON_SHREDER_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #elif defined(CONFIG_CMD_IS_BOTTLE_FALL_STATUS_NOT_READY)
    .STATUS = CMD_STATUS_NOT_READY,
    .data = ""
    #endif
};

json_dto_t CMD_ON_SHREDER_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_ON_SHREDER,
    #ifdef CONFIG_CMD_ON_SHREDER_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_ON_SHREDER_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_OFF_SHREDER_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0,
    .COMMAND = CMD_OFF_SHREDER,
    #ifdef CONFIG_CMD_OFF_SHREDER_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_OFF_SHREDER_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_GET_COMMAND_STATUS_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0, // додати вибір адреси
    .COMMAND = CMD_GET_COMMAND_STATUS,
    #ifdef CONFIG_CMD_GET_COMMAND_STATUS_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_GET_COMMAND_STATUS_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_GET_ALERT_DATA_JSON_DTO = {
    .address = ESP_MOTORS_ADDR_0, // додати вибір адреси
    .COMMAND = CMD_GET_ALERT_DATA,
    #ifdef CONFIG_CMD_GET_ALERT_DATA_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_GET_ALERT_DATA_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #endif
};

json_dto_t CMD_IS_HAND_NOT_IN_JSON_DTO = {
    .address = ESP_PERIPH_ADDR_1,
    .COMMAND = CMD_IS_HAND_NOT_IN,
    #ifdef CONFIG_CMD_IS_HAND_NOT_IN_OK
    .STATUS = CMD_STATUS_OK,
    .data = ""
    #elif defined(CONFIG_CMD_IS_HAND_NOT_IN_STATUS_ERROR)
    .STATUS = CMD_STATUS_ERROR,
    .data = ""
    #elif defined(CONFIG_CMD_IS_HAND_NOT_IN_STATUS_NOT_READY)
    .STATUS = CMD_STATUS_NOT_READY,
    .data = ""
    #endif
};
