//
// Created by natan on 24/11/2024.
//

#ifndef SCORE_H
#define SCORE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//#include "configs.h"
#include "FlappyBird.h"

typedef struct jogador {
    int id;
    char nome[100];
    int partidas;
    int pontuacoes[100];
    int pontuacao_total;
} jogadores_t;

void linhacaixat(void);
void jogar_novamente();
bool verificar_registros();
int gerar_id_unico();
void adicionar_jogador();
void visualizar_individual();
void visualizar_todos();

#endif //SCORE_H
