#include <stddef.h>
#include "debouncer.h"

void debouncer_init(Debouncer *d) {
    if (d == NULL) return;
    d->shift_reg = 0x0000;
    d->state = 0;
    d->rising_edge = 0;
    d->falling_edge = 0;
}

void debouncer_update(Debouncer *d, uint8_t raw_input) {
    if (d == NULL) return;

    d->shift_reg = (d->shift_reg << 1) | (raw_input & 0x01);
    uint8_t prev_state = d->state;

    if (d->shift_reg == 0xFFFF) {
        d->state = 1;
    } else if (d->shift_reg == 0x0000) {
        d->state = 0;
    }

    d->rising_edge = (prev_state == 0 && d->state == 1) ? 1 : 0;
    d->falling_edge = (prev_state == 1 && d->state == 0) ? 1 : 0;
}
