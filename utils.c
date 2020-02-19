#include "utils.h"

// @param cycle how many loop cycle will run, cycle = 1 will cost 0.9(us) in 10MHz CPU
void delay(u16 cycle) //{
{
    while(cycle--);
    return;
} //}

