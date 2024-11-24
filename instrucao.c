#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "configs.h"
#include "score.h"

void tela_instrucao() {
    system("cls");
    printf("\t\t%sBem vindo ao Flappy Bird!%s\n\n", INTENSO, NORMAL);
    printf("\t\t\t%sInstrucoes:%s\n\n", SUB, NORMAL);
    printf("\t\t1. Pressione espaco para flutuar.\n");
    printf("\t\t2. Nao bata nos pilares!\n");
    printf("\t\t3. Pontue passando pelos espacos.\n");
    system("pause");
    adicionar_jogador();
}

