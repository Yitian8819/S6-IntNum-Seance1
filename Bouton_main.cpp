/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 50 
DigitalIn sw1(PA_8);
DigitalIn sw2(PB_10);
DigitalOut led1(PB_6);
DigitalOut led2(PA_7);

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    led1 = 0;
    led2 = 0;

    while (true)
    {
       if(sw1 == 1)
       {
           led1 = 1;
       }
       else {led1 = 0;}
       if(sw2 == 1)
       {
           led2 = 1;
       }
       else {led2 = 0;}
       thread_sleep_for(WAIT_TIME_MS);
    }
}
