#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "hardware/timer.h"

const uint PIN_U_ECHO = 14;
const uint PIN_U_TRIG = 15;

float measure_distance() {
    gpio_put(PIN_U_TRIG, 1);
    sleep_us(10);
    gpio_put(PIN_U_TRIG, 0);

    uint32_t start_ticks = 0;
    uint32_t end_ticks = 0;

    while (gpio_get(PIN_U_ECHO) == 0) {
        start_ticks = time_us_32();
    }

    while (gpio_get(PIN_U_ECHO) == 1) {
        end_ticks = time_us_32();
    }

    uint32_t elapsed_time_us = end_ticks - start_ticks;
    float distance_cm = elapsed_time_us * 0.0343 / 2;

    return distance_cm;
}

int main() {
	bi_decl(bi_program_description("This is a program to read Ultrasonic sensor"));
	
	stdio_init_all();
	
	gpio_init(PIN_U_ECHO);
	gpio_set_dir(PIN_U_ECHO, GPIO_IN);
	
	gpio_init(PIN_U_TRIG);
	gpio_set_dir(PIN_U_TRIG, GPIO_OUT);
	
	while(1) {
		float distance = measure_distance();
        printf("Distance: %.2f cm\n", distance);
        sleep_ms(1000);
		
	}
	
}
