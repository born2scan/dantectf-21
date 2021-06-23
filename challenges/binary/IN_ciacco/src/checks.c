#include <stdlib.h>
#include "checks.h"

// D1vin4_daN7e_c0MM3d1a

bool check1(char *guess) {
    return (strlen(guess) == 21);
}

bool check2(char *guess) {
    return (
        guess[0] == 'D' &&
        guess[2] == 'v' &&
        guess[4] == 'n' &&
        guess[7] == 'd' &&
        guess[9] == 'N' &&
        guess[11] == 'e' &&
        guess[13] == 'c' &&
        guess[15] == 'M' &&
        guess[17] == '3' &&
        guess[19] == '1'
    );
}

bool check3(char *guess) {
    return (
        guess[1] == '1' &&
        guess[8] == 'a' &&
        guess[10] == '7' &&
        guess[14] == '0' &&
        guess[20] == 'a'
    );
}

bool check4(char *guess) {
    return (
        guess[3] == 'i' &&
        guess[5] == '4' &&
        guess[6] == '_' &&
        guess[12] == '_' &&
        guess[16] == 'M' &&
        guess[18] == 'd'
    );
}
