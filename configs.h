#ifndef CONFIGS_H
#define CONFIGS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LARGURAC 10
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

typedef struct {
    int y; /*Bird's vertical position.*/
} Passaro;

typedef struct {
    int x; /*Pillar's horizontal position*/
    int buracoY; /*gapY - Posi��o do buraco no eixo Y*/
    int buracoTam; /*gapTamanho -> tamanho do buraco do cano*/
} Pilar;

void centralizar_retornos(char *texto);

void centralizar_nomepadrao(char *nome, int tam, int op_grafico);

void centralizar_numpadrao(int *num, int tam, int grafico);

void centralizar_textoind(char *texto);

char *bar(int pontos);

#endif
