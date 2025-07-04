#include "rvm_protocol_types.h"
#include <stdint.h>


const uint32_t ESP_MOTOR_ADDRESS = 0;
const uint32_t ESP_MOTOR_PERIPH_ADDRESS = 1;

const char* data_standart_names[] = {"OK", "ERROR"};

const char* data_cmd_5_get_bottle_status_names[] = {"NO_BARCODE", "HEAVY_WEIGHT"}; 
