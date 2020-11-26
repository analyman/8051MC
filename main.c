#include "type.h"
#include "utils.h"
#include "seven_seg_display.h"
#include "matrix_keyboard.h"
#include "beep.h"

#define led1 P2_0

static __sbit flags;

#define __delay delay

void __init_interrupt() //{
{
    // interrupt 0, external interrupt 0
    EX0 = 1;
    PX0 = 0;

    // interrupt 2, external interrupt 1
    EX1 = 1;
    PX1 = 1;

    // interrupt 1, timer interrupt 0
    ET0 = 1;
    PT0 = 1;

    EA  = 1;
} //}

#define DELAY __delay(50000)
void __light_flickering() //{
{
    P2_0 = 0; DELAY; P2_0 = 1;
    P2_1 = 0; DELAY; P2_1 = 1;
    P2_2 = 0; DELAY; P2_2 = 1;
    P2_3 = 0; DELAY; P2_3 = 1;
    P2_4 = 0; DELAY; P2_4 = 1;
    P2_5 = 0; DELAY; P2_5 = 1;
    P2_6 = 0; DELAY; P2_6 = 1;
    P2_7 = 0; DELAY; P2_7 = 1;
} //}

void __reverse_light_flickering() //{
{
    P2_7 = 0; DELAY; P2_7 = 1;
    P2_6 = 0; DELAY; P2_6 = 1;
    P2_5 = 0; DELAY; P2_5 = 1;
    P2_4 = 0; DELAY; P2_4 = 1;
    P2_3 = 0; DELAY; P2_3 = 1;
    P2_2 = 0; DELAY; P2_2 = 1;
    P2_1 = 0; DELAY; P2_1 = 1;
    P2_0 = 0; DELAY; P2_0 = 1;
} //}

void flickering_led1() //{
{
    led1 = 0; DELAY; led1 = 1; DELAY;
} //}

void __ext_int0_handle() __interrupt 0 //{
{
    flags = 1;
    while(flags) {
        beep(800);
    }
    return;
} //}

void __timer0_handle() __interrupt 1 //{
{
    flags = 0;
} //}

void __ext_int1_handle() __interrupt 2 //{
{
    /*
    u16 i = 0xFFFF;
    while(i--) {
        beep(1600);
    }
    return;
    */
    flags = 0;
    return;
} //}

void main() //{
{
//    __init_interrupt();
    while(1) {
        P2_0 = 0;
        P2_7 = 1;
    }
    ssd_set(0, 15);
    ssd_set(1, 15);
    while(1) {
        get_keyboard_value();
        if(matrix_keyboard_value != 0) {
            if(matrix_keyboard_value == 16) {
                ssd_set(0, 1);
                ssd_set(1, 0);
            } else {
                ssd_set(0, matrix_keyboard_value);
                ssd_set(1, 16);
            }
        }
        ssd_show();
    }
} //}

