#ifndef SEVEN_SEG_DISPLAY_H_
#define SEVEN_SEG_DISPLAY_H_

#include "type.h"

#define NUMBER_OF_DISPLAY 8

void ssd_show();
void ssd_clear(u8 ps);
void ssd_set  (u8 ps, u8 val);

#endif // not SEVEN_SEG_DISPLAY_H_
