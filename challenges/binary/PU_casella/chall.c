#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_flag(char flag[57]) {
    char s1[] = "VQ[DQcR\x7f}Melyxl}Lav{Hw~cw`jwLgmq}\x7f|Fs\x7f{\x7fOsyMtG{xruczx\x7fxe";
    char s2[] = "31415926535897932384626433832795028841971693993751058209";

    for (int i = 0; i < 56; i++) {
        flag[i] = (char)(s1[i] ^ s2[i] ^ 33);
    }
    flag[56] = 0;
}

int main() {
    char guess[333];

    printf("Aspettando al piede della montagna del purgatorio, non potete far a meno di ripensare alla parola segreta per l'accesso al sentiero che conduce alla vetta.\nCi siete quasi, continuate a camminare in fila, dietro agli altri, mentre vi concentrate profondamente per non dimenticare.\n\nE' finalmente il vostro turno, siete confidenti, alzate lo sguardo, ma sfortunatamente posizionate male il piede su una roccia sporgente il giusto per farvi ritrovare a terra confusi.\nMentre cercare di raccapezzarvi su quanto successo, realizzate di esservi dimenticati l'importante parola che stavate cercando di non scordare.\nSiete certi iniziasse con DANTE...qualcos'altro, ma fate fatica a ricordare il resto...\n\nPoiche' e' il vostro turno, dovrete pur dire qualcosa ed il tempo non e' dalla vostra parte.\n\n...Qual'era? Forse: ");

    fgets(guess, 57, stdin);
    char flag[57];
    get_flag(flag);
    if (strncmp(guess, flag, 56) == 0) {
        printf("\nChe sollievo, nel mezzo degli infiniti pensieri riuscite a ricordare la parola segreta che v'era smarrita. Vi e' consentito l'accesso al sentiero...\n" );
    } else {
        printf("\nMh, non siete del tutto convinti, che sia meglio concentrarsi su altro?\n Qualcosa vi fa pensare che sia meglio non sbagliare...\n");
    }

    return 0;
}
