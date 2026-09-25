#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t shift_reg;
    uint8_t state;
    uint8_t rising_edge;
    uint8_t falling_edge;
} Debouncer;

void debouncer_init(Debouncer *d);
void debouncer_update(Debouncer *d, uint8_t raw_input);

#endif // DEBOUNCER_H
