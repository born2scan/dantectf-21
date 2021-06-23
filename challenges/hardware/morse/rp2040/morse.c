#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "morse.pio.h"
#include "pico/stdlib.h"

void push(PIO pio, uint32_t value) {
    // Push a value on both SM0 and SM1 TX FIFOs
    pio_sm_put_blocking(pio, 0, value);
    pio_sm_put_blocking(pio, 1, value);
}

int main() {
    // Init HW UART + USB UART
    stdio_init_all();

    const PIO pio = pio0;
    const uint32_t clock = clock_get_hz(clk_sys);

    // Define morse lengths in hardware cycles
    /* generated code START */
    const uint32_t morse_short = clock * 0.24;
    const uint32_t morse_long = clock * 0.72;
    /* generated code END */

    // Load PIO code
    uint offset = pio_add_program(pio, &morse_program);
    printf("PIO program loaded at offset %d\n", offset);

    // Init PIO code on PIO0, SM0
    morse_program_init(pio, 0, offset, 25);
    pio_sm_set_enabled(pio, 0, true);
    printf("PIO program enabled on PIO0, SM0\n");
    // Init PIO code on PIO0, SM1
    morse_program_init(pio, 1, offset, 15);
    pio_sm_set_enabled(pio, 1, true);
    printf("PIO program enabled on PIO0, SM1\n");

    // Set delay between chars
    printf("Presetting delay between chars\n");
    pio->txf[0] = morse_short;
    pio->txf[1] = morse_short;

    // Continuously print morse flag
    while (true) {
        //printf("Morse'ing on GP25 & GP15\n");

        /* generated code START */
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf("-");
        push(pio, morse_long);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf("-");
        push(pio, morse_long);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(".");
        push(pio, morse_short);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf("-");
        push(pio, morse_long);
        printf("-");
        push(pio, morse_long);
        printf(" ");
        push(pio, 0);
        push(pio, morse_long * 2);
        printf(".");
        push(pio, morse_short);
        printf("-");
        push(pio, morse_long);
        printf("\n");

        sleep_ms(12000);
        /* generated code END */
    }

    return 0;
}
