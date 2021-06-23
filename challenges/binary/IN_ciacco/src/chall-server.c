#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checks.h"

void print_flag() {
    printf("DANTE{v01_c1tt4d1n1_m1_ch14m45t3_c14cc0_p3r_l4_d4nn054_c0lp4_d3ll4_g0l4_c0m3_tu_v3d1_4ll4_p10gg14_m1_f14cc0}");
}

int check_input(char *guess) {
    printf("Check 1\n");
    if (!check1(guess)) return 1;

    printf("Check 2\n");
    if (!check2(guess)) return 1;

    printf("Check 3\n");
    if (!check3(guess)) return 1;

    printf("Check 4\n");
    if (!check4(guess)) return 1;

    return 0;
}

int main() {
    char guess[334];

    // get string without \n
    printf("Password: ");
    fflush(stdout);
    fgets(guess, 333, stdin);
    guess[strcspn(guess, "\n")] = 0;

    if (check_input(guess)) {
        printf("Alcuni controlli non sono stati passati. Riprova\n");
        return 1;
    }

    print_flag();

    return 0;
}
