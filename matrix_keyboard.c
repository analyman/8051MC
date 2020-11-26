#include "matrix_keyboard.h"
#include "utils.h"
#include "type.h"
#include "beep.h"

u8 matrix_keyboard_value;
#define keyboard_port P1

void get_keyboard_value() //{
{
    u8 keyport_temp1, keyport_temp2;
    matrix_keyboard_value = 0;
    keyboard_port = 0x0F;
    keyport_temp1 = keyboard_port;
    if(keyport_temp1 == 0X0F) return;
    keyboard_port = 0xF0;
    keyport_temp2 = keyboard_port;
    if(keyport_temp2 == 0xF0) return;
    switch(keyport_temp1) {
        case 0xE: matrix_keyboard_value = 4; break;
        case 0xD: matrix_keyboard_value = 3; break;
        case 0xB: matrix_keyboard_value = 2; break;
        case 0x7: matrix_keyboard_value = 1; break;
    }
    switch(keyport_temp2) {
        case 0xE0: matrix_keyboard_value += 12; break;
        case 0xD0: matrix_keyboard_value += 8;  break;
        case 0xB0: matrix_keyboard_value += 4;  break;
        case 0x70: matrix_keyboard_value += 0;  break;
    }
    return;
} //}

