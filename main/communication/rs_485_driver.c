#include "rs_485_driver.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "driver/gpio.h"

#define TX_UART_PIN GPIO_NUM_20
#define RX_UART_PIN GPIO_NUM_48
#define DE_PIN GPIO_NUM_21
#define RE_PIN GPIO_NUM_47
#define BUF_SIZE 256

QueueHandle_t rs_485_rx_queue;

static rs_485_status_t rs_485_uart_init(void){
    esp_err_t err = ESP_OK;

    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    err = uart_driver_install(RS_485_UART_NUM, BUF_SIZE * 2, BUF_SIZE * 2, 10, &rs_485_rx_queue, 0);
    if( err != ESP_OK){
        ESP_LOGE("rs_485_uart_init", "uart_driver_install faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }

    err = uart_param_config(RS_485_UART_NUM, &uart_config);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_uart_init", "uart_param_config faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }

    err = uart_set_pin(RS_485_UART_NUM, TX_UART_PIN, RX_UART_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_uart_init", "uart_set_pin faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }
    return RS_485_OK;
}

static rs_485_status_t rs_485_re_de_gpio_init(){
    esp_err_t err = ESP_OK;
    err = gpio_set_direction(DE_PIN, GPIO_MODE_OUTPUT);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_re_de_gpio_init", "gpio_set_direction DE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }

    err = gpio_set_direction(RE_PIN, GPIO_MODE_OUTPUT);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_re_de_gpio_init", "gpio_set_direction RE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }
    return RS_485_OK;
}

rs_485_status_t rs_485_init(void){
    if(rs_485_uart_init() == RS_485_ERROR){
        ESP_LOGE("rs_485_init","rs_485_uart_init init failed");
        return RS_485_ERROR;
    }

    if(rs_485_re_de_gpio_init() == RS_485_ERROR){
        ESP_LOGE("rs_485_init","rs_485_re_de_gpio_init init failed");
        return RS_485_ERROR;
    }
    return RS_485_OK;
}

rs_485_status_t rs_485_set_rx_mode(void) {
    esp_err_t err = ESP_OK;
    
    err = gpio_set_level(DE_PIN, 0);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_set_rx_mode", "gpio_set_level DE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }

    err = gpio_set_level(RE_PIN, 0);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_set_rx_mode", "gpio_set_leve RE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }
    return RS_485_OK;
}

rs_485_status_t rs_485_set_tx_mode(void) {
    esp_err_t err = ESP_OK;

    err = gpio_set_level(DE_PIN, 1);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_set_tx_mode", "gpio_set_level DE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }

    err = gpio_set_level(RE_PIN, 1);
    if(err != ESP_OK){
        ESP_LOGE("rs_485_set_tx_mode", "gpio_set_leve RE_PIN faliled:%s", esp_err_to_name(err));
        return RS_485_ERROR;
    }
    return RS_485_OK;
}

