#include <stdlib.h>
#include <stdio.h>
#include "../include/tela.h"

Tela **tela;
unsigned char r, g, b;
unsigned demarcadorInferior;
unsigned demarcadorSuperior;

void alocaTela() {

    tela = (Tela **)malloc(ALTURA * sizeof(Pixel *));
    demarcadorInferior = 1;
    demarcadorSuperior = 0;
    r = rand() % 230 + 25;
    g = rand() % 230 + 25;
    b = rand() % 230 + 25;

    if (tela == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tela.\n");
        exit(1);
    }

    for (unsigned i = 0; i < ALTURA; i++) {
        tela[i] = (Pixel *)malloc(LARGURA * sizeof(Pixel));
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
            tela[i][j].ativo = 0;
}

void atualizaCor(){
    r = rand() % 230 + 25;
    g = rand() % 230 + 25;
    b = rand() % 230 + 25;
}

unsigned atualizaDemarcadorInferior(){
    unsigned char resul;
    for(int i = ALTURA - demarcadorInferior; i >= 0; i --){
        resul = 1;
        for(unsigned j = 0; j < LARGURA; j ++){
            resul = resul & tela[i][j].ativo;
            if(!resul){
                return demarcadorInferior;
            }
        }
        demarcadorInferior ++;
    }
    return demarcadorInferior;
}

unsigned atualizaDemarcadorSuperior(){
    unsigned char resul;
    demarcadorSuperior = 0;
    for(int i = 0; i < ALTURA; i ++){
        resul = 0;
        for(unsigned j = 0; j < LARGURA; j ++){
            resul = resul | tela[i][j].ativo;
            if(resul){
                return demarcadorSuperior;
            }
        }
        demarcadorSuperior ++;
    }
    return demarcadorSuperior;
}

void setPixel(unsigned x, unsigned y, Pixel p){
    tela[x][y].ativo = 1;
    tela[x][y].r = p.r;
    tela[x][y].g = p.g;
    tela[x][y].b = p.b;
}

void resetPixel(unsigned x, unsigned y){
    tela[x][y].ativo = 0;
    tela[x][y].r = 0;
    tela[x][y].g = 0;
    tela[x][y].b = 0;
}

void finalizaTela() {
    for (unsigned i = 0; i < ALTURA; i++) {
        free(tela[i]);
    }
    free(tela);
}