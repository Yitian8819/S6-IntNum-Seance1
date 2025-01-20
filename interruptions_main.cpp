/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 50 
InterruptIn sw1(PA_8);
InterruptIn sw2(PB_10);
DigitalOut led1(PB_6);
DigitalOut led2(PA_7);

void sw_ISR1(void){
    bool led_state = led1;
    led1 = !led_state;
}

void sw_ISR2(void){
    bool led_state = led2;
    led2 = !led_state;
}

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    led1 = 0;
    led2 = 1;
    sw1.rise(&sw_ISR1);
    sw2.rise(&sw_ISR2);

    while (true)
    {
        thread_sleep_for(WAIT_TIME_MS);
    }
}
