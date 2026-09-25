#include <stdio.h>
#include "debouncer.h"

int main(void) {
    Debouncer d;
    debouncer_init(&d);

    uint8_t inputs[] = {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0};
    int total = sizeof(inputs) / sizeof(inputs[0]);

    printf("=== Testbench Debouncer (16-bit Shift Register) ===\n\n");
    for (int i = 0; i < total; i++) {
        debouncer_update(&d, inputs[i]);
        printf("Muestra %02d | Input: %d | ShiftReg: 0x%04X | State: %d | Edges (R/F): %d/%d\n",
               i, inputs[i], d.shift_reg, d.state, d.rising_edge, d.falling_edge);
    }

    return 0;
}
