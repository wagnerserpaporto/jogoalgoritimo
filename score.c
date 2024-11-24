#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "configs.h"
#include "FlappyBird.h"
#include "inicio.h"
#include "score.h"

void linhacaixat(void){
    printf("\t\t");
    int i;
    for (i = 0; i < TAM; i++) {
        printf("\xCD");
    }
}

bool verificar_registros() {
    /*Verifica se h� registros no arquivo*/
    FILE *file = fopen("data.dat", "rb");
    if (file == NULL) {
        return false;
        /*Falso significa que o arquivo n�o foi criado, logo n�o temos registro*/
    }

    jogadores_t jogador;
    bool possui_registros = fread(&jogador, sizeof(jogadores_t), 1, file) > 0;
    fclose(file);
    return possui_registros;
    /*Positivo significa que o arquivo foi criado, logo temos registro*/
}

/*Gera um ID �nico para o jogador*/
int gerar_id_unico() {
    FILE *file = fopen("data.dat", "rb");
    if (file == NULL) {
        return rand() % 10 + 1;
        /*Retorna um ID aleat�rio entre 1 e 10 se o arquivo ainda n�o existir*/
    }

    jogadores_t jogador;
    int ids_usados[10] = {0};
    int total_jogadores = 0;

    while (fread(&jogador, sizeof(jogadores_t), 1, file)) {
        ids_usados[jogador.id - 1] = 1;
        total_jogadores++;
    }

    fclose(file);

    if (total_jogadores >= 10) {
        printf(
            "Limite de 10 jogadores atingido!\nNao e possivel adicionar novos jogadores.\n");
        return -1;
    }

    int novo_id;
    do {
        novo_id = rand() % 10 + 1;
    } while (ids_usados[novo_id - 1] == 1);

    return novo_id;
}

void adicionar_jogador() {
    srand(time(NULL));

    int id = gerar_id_unico();
    if (id == -1) {
        system("pause");
    }

    FILE *file = fopen("data.dat", "ab");
    if (file == NULL) {
        perror("Erro ao gerar o arquivo!");
        return;
        /*system("pause");*/
    }

    jogadores_t novo_jogador;
    novo_jogador.id = id;

    printf("Digite o nome do jogador: ");
    fflush(stdin);
    fgets(novo_jogador.nome, sizeof(novo_jogador.nome), stdin);
    novo_jogador.nome[strcspn(novo_jogador.nome, "\n")] = '\0';

    novo_jogador.partidas = 0;
    novo_jogador.pontuacao_total = 0;
    int i;
    for (i = 0; i < 100; i++) {
        novo_jogador.pontuacoes[i] = 0;
    }

    fwrite(&novo_jogador, sizeof(jogadores_t), 1, file);
    printf("Id: %d\tJogador %s adicionado com sucesso!\n", novo_jogador.id,
           novo_jogador.nome);
    fclose(file);

    /*AQUI DEVE COME�AR O JOGO*/
    int pontuacao = flappy();
    file = fopen("data.dat", "rb+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para atualiza��o!");
        return;
    }

    bool encontrado = false;
    while (fread(&novo_jogador, sizeof(jogadores_t), 1, file)) {
        if (novo_jogador.id == id) {
            encontrado = true;
            /*Atualiza as informa��es do jogador*/
            novo_jogador.pontuacoes[novo_jogador.partidas] = pontuacao;
            /*Registra a pontua��o*/
            novo_jogador.partidas++; /*Incrementa o n�mero de partidas*/
            novo_jogador.pontuacao_total += pontuacao;
            /*Atualiza a pontua��o total*/

            /*Move o cursor para reescrever os dados do jogador no arquivo*/
            long posicao = ftell(file) - sizeof(jogadores_t);
            fseek(file, posicao, SEEK_SET);
            fwrite(&novo_jogador, sizeof(jogadores_t), 1, file);
            printf(
                "Pontuacao inicial registrada com sucesso para o jogador %s!\n",
                novo_jogador.nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Erro: Jogador nao encontrado no arquivo apos adicionar!\n");
    }

    fclose(file);
    system("pause");
}

void jogar_novamente() {
    int id;
    printf("Digite o ID do jogador para continuar o jogo: ");
    scanf("%d", &id);

    FILE *file = fopen("data.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    jogadores_t jogador;
    bool encontrado = false;

    while (fread(&jogador, sizeof(jogadores_t), 1, file)) {
        if (jogador.id == id) {
            encontrado = true;
            int pontuacao = flappy();


            if (jogador.partidas < 100) {
                jogador.pontuacoes[jogador.partidas] = pontuacao;
                jogador.partidas++;
                jogador.pontuacao_total += pontuacao;

                long posicao = ftell(file) - sizeof(jogadores_t);
                fseek(file, posicao, SEEK_SET);
                fwrite(&jogador, sizeof(jogadores_t), 1, file);

                printf("Pontuacao registrada com sucesso!\n");
            } else {
                printf(
                    "O jogador ja atingiu o limite maximo de 100 partidas.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Jogador com ID %d nao encontrado.\n", id);
    }

    fclose(file);
    system("pause");
}

void visualizar_individual() {

    int id;
    printf("Digite o ID do jogador: ");
    scanf("%d", &id);

    FILE *file = fopen("data.dat", "rb");
    if (file == NULL) {
        printf("%sNenhum jogador cadastrado ainda%s.\n", SUB, NORMAL);
        system("pause");
    }

    jogadores_t jogador;
    bool encontrado = false;

    while (fread(&jogador, sizeof(jogadores_t), 1, file)) {
        if (jogador.id == id) {
            encontrado = true;
            linhacaixat();

            printf("\n\t\t\xBA%s************ %sINFORMACOES DO JOGADOR%s ",
                   INTENSO, SUB, NORMAL);
            printf("%s************%s\xBA\n", INTENSO, NORMAL);
            centralizar_textoind("ID");
            printf("% 24d\xBA\n", jogador.id);
            centralizar_textoind("NOME");
            printf("%s% 23s%s\xBA\n", INTENSO, jogador.nome, NORMAL);
            centralizar_textoind("Partidas Jogadas");
            printf("% 17d\xBA\n", jogador.partidas);

            int i;
            for (i = 0; i < jogador.partidas; i++) {
                if (jogador.pontuacoes[i] != 0) {
                    char partida[11];
                    sprintf(partida, "Partida % .2d", i + 1);
                    centralizar_textoind(partida);
                    printf("% .2d", jogador.pontuacoes[i]);
                    char *grafico = bar(jogador.pontuacoes[i]);
                    centralizar_nomepadrao(grafico, 17, 0);

                    printf("\xBA\n");
                }
            }
            centralizar_textoind("Pontuacao Total");
            printf("% 18d\xBA\n", jogador.pontuacao_total);
            linhacaixat();
            break;
        }
    }
    if (!encontrado) {
        printf("Jogador com ID %d nao encontrado.\n", id);
    }
    fclose(file);
    printf("\n");
}

void visualizar_todos() {
    FILE *file = fopen("data.dat", "rb");
    if (file == NULL) {
        printf("Nenhum jogador cadastrado ainda...\n");
    } else {
        jogadores_t jogador;
        printf("\n===============*** ");
        centralizar_nomepadrao("TODOS OS JOGADORES", TAM, 0);
        printf(" ***===============\n");
        centralizar_nomepadrao("ID", 8, 1);
        centralizar_nomepadrao("NOME", TAM, 1);
        centralizar_nomepadrao("Partidas", 11, 1);
        centralizar_nomepadrao("PONTUACAO TOTAL", 19, 1);
        while (fread(&jogador, sizeof(jogadores_t), 1, file)) {
            int tam = strlen(jogador.nome);
            if (tam < 50) {
                tam = 50;
            }
            printf("\n");
            centralizar_numpadrao(&jogador.id, 8, 1);

            centralizar_nomepadrao(jogador.nome, TAM, 1);
            centralizar_numpadrao(&jogador.partidas, 11, 1);

            centralizar_numpadrao(&jogador.pontuacao_total, 19, 1);
        }
        printf(
            "\n========================================================================================\n");

        fclose(file);
        char resp;
        printf("Pontuacao individual: (s|n)");
        fflush(stdin);
        resp = getchar();
        switch (resp) {
            case 's':
                visualizar_individual();
                break;
            case 'n':

                break;
            default:
                printf("Opcao Invalida\nRetornando ao menu inicial...");
                break;
        }
    }
    system("pause");
}
