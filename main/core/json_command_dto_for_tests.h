#ifndef JSON_COMMAND_DTO_FOR_TESTS_H
#define JSON_COMMAND_DTO_FOR_TESTS_H

#include "rvm_protocol_types.h"
#include "sdkconfig.h"

#define ESP_MOTORS_ADDR_0 0
#define ESP_PERIPH_ADDR_1 1

extern json_dto_t CMD_OPEN_DIAPHRAGM_JSON_DTO;
extern json_dto_t CMD_CLOSE_DIAPHRAGM_JSON_DTO;
extern json_dto_t CMD_LED_GREEN_JSON_DTO;
extern json_dto_t CMD_LED_RED_JSON_DTO;
extern json_dto_t CMD_GET_BOTTLE_STATUS_JSON_DTO;
extern json_dto_t CMD_GET_BARCODE_JSON_DTO;
extern json_dto_t CMD_SHAFTS_ON_JSON_DTO;
extern json_dto_t CMD_SHAFTS_OFF_JSON_DTO;
extern json_dto_t CMD_OPEN_SHAFTS_JSON_DTO;
extern json_dto_t CMD_CLOSE_SHAFTS_JSON_DTO;
extern json_dto_t CMD_IS_BOTTLE_FALL_JSON_DTO;
extern json_dto_t CMD_ON_SHREDER_JSON_DTO;
extern json_dto_t CMD_OFF_SHREDER_JSON_DTO;
extern json_dto_t CMD_GET_COMMAND_STATUS_JSON_DTO;
extern json_dto_t CMD_GET_ALERT_DATA_JSON_DTO;
extern json_dto_t CMD_IS_HAND_NOT_IN_JSON_DTO;

#endif