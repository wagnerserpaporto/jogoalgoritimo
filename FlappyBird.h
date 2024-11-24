//
// Created by natan on 24/11/2024.
//

#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "configs.h"

const char *getRandomColor();
void desenharJogo(Passaro *passaro, Pilar pilares[], int pontuacao);
int checarColisao(Passaro *passaro, Pilar pilares[]);
void moverPilares(Pilar pilares[], int *pontuacao);
void atualizarPassaro(Passaro *passaro);
int flappy();
#endif //FLAPPYBIRD_H
