#include <stdlib.h>
#include <stdio.h>
#include "../include/tela.h"

unsigned char **tela;

void alocaTela() {

    tela = (unsigned char **)malloc(ALTURA * sizeof(unsigned char *));

    if (tela == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tela.\n");
        exit(1);
    }

    for (unsigned i = 0; i < ALTURA; i++) {
        tela[i] = (unsigned char *)malloc(LARGURA * sizeof(unsigned char));
        if (tela[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para a linha %u da tela.\n", i);
            exit(1);
        }
    }
}

void inicializaTela(){
    alocaTela();

    for(unsigned i = 0; i < ALTURA; i ++)
        for(unsigned j = 0; j < LARGURA; j ++)
            tela[i][j] = 0;
}

void setPixel(unsigned x, unsigned y){
    tela[x][y] = 1;
}

void resetPixel(unsigned x, unsigned y){
    tela[x][y] = 0;
}

void finalizaTela() {
    for (unsigned i = 0; i < ALTURA; i++) {
        free(tela[i]);
    }
    free(tela);
}