cmake_minimum_required(VERSION 3.27)
project(example C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(example
        1302rtc_main.c
        24C02_main.c
        AT24C02.c
        AT24C02.h
        button.c
        button.h
        button_main.c
        Buzzer.c
        Buzzer.h
        buzzer_main.c
        display_main.c
        DS1302.c
        DS1302.h
        I2C.c
        I2C.h
        lcd1602.c
        lcd1602.h
        lcd1602_main.c
        led8x8display_main.c
        main.c
        matrix_keyboard_main.c
        matrix_led.c
        matrix_led.h
        MatrixKey.c
        MatrixKey.h
        Nixie.c
        Nixie.h
        public.c
        public.h
        serial_main.c
        Timer0.c
        Timer0.h
        timer_main.c
        UART.c
        UART.h)
