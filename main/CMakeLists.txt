
idf_component_register(
    SRCS "main.c" 
    "communication/comunication.c" 
    "communication/command_json_parser.c"
    "communication/rvm_protocol_types.c"
    "communication/rs_485_driver.c"  
  
    "core/command_handler.c"
    "core/json_command_dto_for_tests.c"

    INCLUDE_DIRS "." 
    "communication"  
    "core" 
    REQUIRES driver json
)
