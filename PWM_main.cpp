/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 200 
InterruptIn sw1(PA_8);
InterruptIn sw2(PB_10);
PwmOut led1(PA_7);
int i;
float val_rc = 0;

void sw_ISR1(void){
    i ++ ;
}

void sw_ISR2(void){
    i -- ;
}

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    sw1.rise(&sw_ISR1);
    sw2.rise(&sw_ISR2);

    led1.period_ms(10);
    led1.write(0);

    while (true)
    {
        val_rc = i/20.0;
            led1.write(val_rc);
            thread_sleep_for(WAIT_TIME_MS);
    }
}
