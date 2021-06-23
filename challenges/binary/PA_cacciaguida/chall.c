#include <stdio.h>
#include <stdlib.h>

int main() {
    char *flag = "53mpr3_14_c0nfu510n_d3_13_p3r50n3_pr1nc1p10_fu_d31_m41_d3_14_c1774d3";
    char *flag_redacted = "53m...";
    char answer;

    printf("Dopo aver vagato a lungo, riuscite finalmente a raggiungere la vetta della montagna del Limbo. Vi e' stato concesso l'accesso al paradiso, volete entrare? [S/N]\r\n");

    answer = getchar();
    if ((char)answer == 'S' || (char)answer == 's') {
        printf("\r\nAhime', la bandiera in paradiso non vi puo' accompagnare, ed anche se questa situazione vi e' al quanto familiare, di costei solo questo vi rimane: DANTE{%s}", flag_redacted);
    } else {
        printf("\r\nRinunciate a questa occasione unica...\r\nVi allontanate lentamente, pensierosi della scelta compiuta.\r\n");
    }

    return 0;
}
