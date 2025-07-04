#ifndef COMMAND_JSON_PARSER_H
#define COMMAND_JSON_PARSER_H
#include "rvm_protocol_types.h"

typedef enum{
    COMMAND_JSON_PARSER_OK = 0,
    COMMAND_JSON_PARSER_ERROR = 1
}command_json_parser_t;

command_json_parser_t parse_json_struct_to_string(const json_dto_t* input_json_dto, char** output_string);
command_json_parser_t parse_string_to_json_struct(json_dto_t* output_json_dto, const char* input_string);

#endif