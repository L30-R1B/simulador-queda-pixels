#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "../include/tela.h"
#include "../include/queda.h"
#include "../include/renderizacao.h"

unsigned xNovo, yNovo;
#define DISTANCIA_QUEDA 1
#define QUEDA_DELAY 1

int realizaQueda(unsigned x, unsigned y) {
    setPixel(xNovo, yNovo, tela[x][y]);
    resetPixel(x, y);
    return 1;
}


int autenticaQueda(int x, int y) {
    int xBaixo = x + DISTANCIA_QUEDA;
    if (xBaixo < ALTURA) {
        if (!tela[xBaixo][y].ativo) {
            xNovo = xBaixo;
            yNovo = y;
            return 1;
        }

        if (y + DISTANCIA_QUEDA < LARGURA && !tela[xBaixo][y + DISTANCIA_QUEDA].ativo) {
            xNovo = xBaixo;
            yNovo = y + DISTANCIA_QUEDA;
            return 1;
        }

        if (y - DISTANCIA_QUEDA >= 0 && !tela[xBaixo][y - DISTANCIA_QUEDA].ativo) {
            xNovo = xBaixo;
            yNovo = y - DISTANCIA_QUEDA;
            return 1;
        }
    }
    return 0;
}

void realizaQuedas() {
    for (int i = ALTURA - demarcadorInferior; i >= (int) demarcadorSuperior; i--) {
        int j;
        for (j = 0; j <= LARGURA - 8; j += 8) {
            if (tela[i][j].ativo && autenticaQueda(i, j)) {
                realizaQueda(i, j);
            }
            if (tela[i][j + 1].ativo && autenticaQueda(i, j + 1)) {
                realizaQueda(i, j + 1);
            }
            if (tela[i][j + 2].ativo && autenticaQueda(i, j + 2)) {
                realizaQueda(i, j + 2);
            }
            if (tela[i][j + 3].ativo && autenticaQueda(i, j + 3)) {
                realizaQueda(i, j + 3);
            }
            if (tela[i][j + 4].ativo && autenticaQueda(i, j + 4)) {
                realizaQueda(i, j + 4);
            }
            if (tela[i][j + 5].ativo && autenticaQueda(i, j + 5)) {
                realizaQueda(i, j + 5);
            }
            if (tela[i][j + 6].ativo && autenticaQueda(i, j + 6)) {
                realizaQueda(i, j + 6);
            }
            if (tela[i][j + 7].ativo && autenticaQueda(i, j + 7)) {
                realizaQueda(i, j + 7);
            }
        }
        if((i % 2) == 0)
            desenhaTela();
    }
}

