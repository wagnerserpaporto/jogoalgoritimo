#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LARGURAC 10  // Largura da caixa
#define TAM 50

#define LARGURA 20 /*width*/
#define ALTURA 10 /*height*/
#define PASSARO_X 5 /*BIRD_X*/
#define MAX_PILARES 3  /*MAX_PILLARS -> N�mero m�ximo de pilares*/
/*#define DIST_MIN_BURACOS 3  // MIN_GAP_DISTANCE -> Dist�ncia m�nima entre os buracos
//c�digos abaixo simplesmente para implementa��o de cores nos pilares
//defini��o de cores*/
#define LIMPA "\x1B[0m"
#define RESET "\033[m"
#define VERDE "\033[38;2;0;156;59m"
#define AMARELO "\033[38;2;255;223;0m"
#define AZUL "\033[38;2;0;39;118m"
#define PADRAO "\033[m"

#define NORMAL "\x1B[0m"
#define INTENSO "\x1B[1m"
#define SUB "\x1B[4m"
#define PISCA "\x1B[5m"
#define PISCAAM "\x1B[5m\033[33m"
#define VERDE "\033[38;2;0;156;59m"

void centralizar_retornos(char *texto) {
    int comprimento_texto = strlen(texto);
    int espacos_esquerda = (TAM - 2 - comprimento_texto) / 2;
    int espacos_direita = TAM - 2 - comprimento_texto - espacos_esquerda;

    printf("\xBA");
    int i;
    for (i = 0; i < espacos_esquerda; i++) {
        printf(" ");
    }

    printf("%s", texto);

    for (i = 0; i < espacos_direita; i++) {
        printf(" ");
    }
    printf("\xBA\n");
}


void centralizar_nomepadrao(char *nome, int tam, int op_grafico) {
    int comprimento_texto = strlen(nome);
    int espacos_esquerda = (tam - 2 - comprimento_texto) / 2;
    int espacos_direita = tam - 2 - comprimento_texto - espacos_esquerda;

    char grafico = (op_grafico == 0) ? '|' : '\xBA';

    printf("%c", grafico);


    int i;
    for (i = 0; i < espacos_esquerda; i++) {
        printf(" ");
    }
    printf("%s", nome);

    for (i = 0; i < espacos_direita; i++) {
        printf(" ");
    }

    printf("%c", grafico);
}

void centralizar_numpadrao(int *num, int tam, int grafico) {
    char buffer[100]; /*Buffer para o número convertido em string*/

    /*Converte o número apontado por 'num' para string*/
    snprintf(buffer, sizeof(buffer), "%d", *num);

    /*Chama a função centralizar_nomepadrao passando o número como string*/
    centralizar_nomepadrao(buffer, tam, grafico);
}

void centralizar_textoind(char *texto) {
    int k;
    int esp = (48 - strlen(texto) - 4) / 2;
    printf("\t\t\xBA%s%s%s:", PISCA, texto, NORMAL);
    for (k = 0; k < esp; k++) {
        printf(" ");
    }
}

char *bar(int pontos) {
    /*Aloca mem�ria para a string (inclui +1 para o caractere nulo '\0')*/
    char *barra = (char *) malloc((pontos + 1) * sizeof(char));
    if (barra == NULL) {
        /*Verifica falha na aloca��o de mem�ria*/
        printf("Erro ao alocar mem�ria.\n");
        exit(EXIT_FAILURE);
    }
    /*Preenche a string com o caractere '\xCD'*/
    int j;
    for (j = 0; j < pontos; j++) {
        barra[j] = '\xCD';
    }
    barra[pontos] = '\0'; /*Termina a string com o caractere nulo*/
    return barra;
}
