# RVM_DEMO_Project

**1,2,3,4,5,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,40,41,42,43,44,47,48** Input and Output Pin

**14,15,19,22,23,24,25,26,27,28,29,30,31,32,33,43,44** FREE GPIO

# DIAPHRAGM MOTOR
- **DIR**:  GPIO_12
- **STEP**: GPIO_41
- **EN**:   GPIO_13

# LEDS
- **RED**:   GPIO_2
- **GREEN**: GPIO_42

# DC DC MOTORS
- **ON_MOTORS**: GPIO_1

# SHAFTS MOTORS
 ## SHAFTS MOTORS RIGHT
 - **DIR**:  GPIO_16
 - **STEP**: GPIO_17
 - **EN**:   GPIO_18
 
  ## SHAFTS MOTORS LEFT
 - **DIR**:  GPIO_10
 - **STEP**: GPIO_11
 - **EN**:   GPIO_8

# SHREDER MOTORS
- **DIR**:  GPIO_4
- **STEP**: GPIO_5
- **EN**:   GPIO_40

# RS485
- **DE_PIN**: GPIO_21
- **RE_PIN**: GPIO_47
 ## UART0
 - **UART_TX**: GPIO_20
 - **UART_RX**: GPIO_48


# ESP32_S3_WROOM_1_INFO 
Пины, не рекомендуемые для использования
GPIO	Назначение	Причина ограничения
26–32	Подключены к встроенной SPI Flash/PSRAM	Использование может привести к сбоям прошивки
33–37	Используются для Octal SPI Flash/PSRAM	Не доступны для внешнего использования при наличии Octal Flash/PSRAM
6–13	Используются для встроенной SPI Flash	Задействованы для внутренней памяти, не рекомендуется использовать

GPIO	Назначение	Особенности
0	Страппинг-пин	Определяет режим загрузки; должен быть подтянут к GND для входа в режим загрузки прошивки
Если GPIO0 будет LOW при сбросе, ESP32-S3 войдёт в режим загрузки (bootloader mode), а не в обычную работу.

3	Страппинг-пин	Контролирует поведение JTAG; требует осторожности при использовании
Можно подключить кнопку, датчик или другой источник сигнала, если сигнал стабилен при старте.
Рекомендуется подтяжка к HIGH через резистор (10k), чтобы избежать ложных срабатываний во время загрузки.
Не рекомендуется подключать туда что-то, что может быть LOW при старте питания без явной необходимости.

45	Страппинг-пин	Определяет напряжение VDD_SPI; влияет на режим загрузки
Можно использовать только как вход и только если уровень сигнала стабилен при старте

46	Страппинг-пин	Управляет выводом сообщений ROM; влияет на режим загрузки
При этом рекомендуется подтягивающий резистор, чтобы при старте был стабильный логический уровень (лучше — HIGH).

39	Особое поведение при сбросе	Переходит в высокий уровень после сброса, в отличие от большинства GPIO

42,47	Медленный переход в низкий уровень	Переходят в низкий уровень медленнее других GPIO при сбросе

Вхід-Вихід
0–21

38–41

42–44

47–48

Вхід тільки
34
35
36
37
38 (в некоторых ревизиях тоже только вход)
39
Это пины с ограничениями на выход — они не поддерживают внутренние драйверы вывода (т.е. не могут выдавать HIGH/LOW), но идеально подходят для подключения датчиков, кнопок и других источников сигнала.

9-10 пінов на вихід доступно
4 пінів на вхід

2rx uart штрих кода - 2 входа
2tx uart штрих кода - 2 вихода 

1 пін тактирования тензо - 1 виход
4 піна данних тензо - 4 виходи 

2 піна концевіків - 2 входи

2 піна для сонара(бажано переробити на i2c ) 1wire міст?



# RVM_DEMO_PROJECT
# RVM_ESP_EMULATOR_TEST
