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
    // Atualiza a posição apenas uma vez
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
        for (int j = 0; j < LARGURA; j++) {
            if (tela[i][j].ativo && autenticaQueda(i, j)) {
                realizaQueda(i, j);
                i = xNovo;
                j = yNovo;
                desenhaTela();
            }
        }
    }
}
