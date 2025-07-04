#include "command_json_parser.h"
#include "cJSON.h"
#include <string.h>



command_json_parser_t parse_json_struct_to_string(const json_dto_t* const input_json_dto, char** output_string){

    cJSON* json = cJSON_CreateObject();

    cJSON_AddNumberToObject(json, "address", input_json_dto->address);
    cJSON_AddNumberToObject(json, "command", input_json_dto->COMMAND);
    cJSON_AddNumberToObject(json, "status", input_json_dto->STATUS);
    cJSON_AddStringToObject(json, "data", input_json_dto->data); 

    *output_string = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

return COMMAND_JSON_PARSER_OK;
}

command_json_parser_t parse_string_to_json_struct(json_dto_t* output_json_dto, const char* const input_string) {
    cJSON* json = cJSON_Parse(input_string);
    if (!json) return COMMAND_JSON_PARSER_ERROR;

    output_json_dto->address = cJSON_GetObjectItem(json, "address")->valueint;
    output_json_dto->COMMAND = (commands_t)cJSON_GetObjectItem(json, "command")->valueint;
    output_json_dto->STATUS = (status_t)cJSON_GetObjectItem(json, "status")->valueint;

    const cJSON* data_item = cJSON_GetObjectItem(json, "data");
    if (cJSON_IsString(data_item) && data_item->valuestring != NULL) {
        output_json_dto->data = strdup(data_item->valuestring);
    } else {
        output_json_dto->data = NULL;
    }

    cJSON_Delete(json);
    return COMMAND_JSON_PARSER_OK;
}