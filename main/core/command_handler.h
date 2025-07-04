#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

typedef enum {
    COMMAND_HANDLER_OK = 0,
    COMMAND_HANDLER_ERROR  = 1
}command_handler_status_t;

command_handler_status_t command_handler(int cmd);

void tasks_init(void);
#endif