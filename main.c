#include <mcs51/8051.h>

typedef unsigned char      u8;
typedef unsigned short int u16;

void __delay(u16 time)
{
    while(time--);
}

void main()
{
    while(1) {
        P2_0 = 1;
        __delay(50000);
        P2_0 = 0;
        __delay(50000);
    }
}
