#include <stdio.h>
#include <stdlib.h>

#include "configs.h"

void creditos(void){
    system("cls");
    char alunos[7][100] = {
        "Emerson Silva",
        "Gabriel Alberto Duarte de Andrade",
        "Juliano Arthur da Silva Braga",
        "Luis Felipe Trega Cipriano",
        "Natanael Ferreira Neves",
        "Thiago Antonio Vieira",
        "Wagner Serpa Porto"
    };

    int i;
    char cabecalho[4][100] = {
        "Pro-Reitoria Academica",
        "Escola de Educacao, Tecnologia e Comunicacao",
        "Curso de Bacharelado em Engenharia de Software",
        "Trabalho de Algoritmos e Programacao Estruturada"
    };

    for (i = 0; i < 4; i++) {
        printf("\t%s%s\n", INTENSO, cabecalho[i]);
        //printf("\t%s\n", cabecalho[i]);
    }
    printf("\n\n");
    printf("%sProjeto desenvolvido pelos alunos%s: \n\n", SUB, NORMAL);
    //printf("Projeto desenvolvido pelos alunos: \n\n");
    for (i = 0; i < 7; i++) {
        printf("\t\t%s\n", alunos[i]);
    }
    printf("\n\t%sOrientador%s: %sProf. Me. Jefferson Salomao Rodrigues\n\n",
           SUB, NORMAL, INTENSO);
    /*printf("\n\tOrientador:. Me. Jefferson Salomao Rodrigues\n\n");*/
    system("pause");
}
