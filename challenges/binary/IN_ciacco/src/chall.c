#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checks.h"

void print_flag() {
    printf("[REDATTA]");
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
    fgets(guess, 333, stdin);
    guess[strcspn(guess, "\n")] = 0;

    if (check_input(guess)) {
        printf("Alcuni controlli non sono stati passati. Riprova\n");
        return 1;
    }

    print_flag();

    return 0;
}
