#ifndef __PIN3_ROTARY_H
#define __PIN3_ROTARY_H

void pin3_rotary_setup();
void pin3_rotary_loop();

struct pinConfig_struct {
    uint8_t a = 2;
    uint8_t b = 3;
};

#endif