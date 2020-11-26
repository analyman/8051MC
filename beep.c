#include "beep.h"
#include "utils.h"

#define beep_bit P1_5

void beep(u16 interval) {
    beep_bit = 0;
    delay(interval);
    beep_bit = 1;
    delay(interval);
    return;
}
