#include "seven_seg_display.h"
#include "utils.h"

// 0 1 2 3 4 5 6 7 8 9 A B C D E F
static u8 _code[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                       0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71, 0x00};

#define data_port P0 // data port is P0 port according to the PCB layout
#define addr_a    P2_2
#define addr_b    P2_3
#define addr_c    P2_4

void ssd_set(u8 ps, u8 val) //{
{
    if(val > 16 || ps  > NUMBER_OF_DISPLAY) return;
    addr_a = ps ^ 0x1;
    addr_b = ps ^ 0x2;
    addr_c = ps ^ 0x4;
    data_port = _code[val];
    delay(500);
    addr_a = 1;
    addr_b = 1;
    addr_c = 1;
    data_port = 0xFF;
} //}

void ssd_clear(u8 ps) //{
{
    ssd_set(ps, 16);
} //}

