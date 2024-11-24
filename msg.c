#include <stdio.h>
#include <stdlib.h>

#include "configs.h"

void msg() {
    system("cls");
    int i, j, k;

    printf("\n\n");
    for (i = 0; i < 4; i++) {
        for (k = 1; k < 5; k++) {
            for (j = 1; j <= 40 - (2 * i + k); j++) {
                printf(" ");
            }
            printf("%s/%s", VERDE, NORMAL);
            for (j = 1; j < (2 * i + k); j++) {
                printf("%sM%s", VERDE, NORMAL);
            }
            for (j = 1; j < (2 * i + k); j++) {
                printf("%sM%s", VERDE, NORMAL);
            }
            printf("%s\\%s\n", VERDE, NORMAL);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 38; j++) {
            printf(" ");
        }
        printf("\xBA \xBA\n");
    }

    printf("\n");
    for (i = 0; i < 32; i++) {
        printf(" ");
    }
    printf("Venha nota boa!!!\n");
    for (i = 0; i < 35; i++) {
        printf(" ");
    }
    printf("Feliz Natal\n");
    system("pause");
}
