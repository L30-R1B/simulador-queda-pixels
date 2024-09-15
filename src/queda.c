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
    if (x < ALTURA && y < LARGURA && !tela[xNovo][yNovo]) {
        resetPixel(x, y);
        setPixel(xNovo, yNovo);
        return 1;
    }
    return 0;
}

int autenticaQueda(int x, int y) {
    if (x + DISTANCIA_QUEDA < ALTURA && !tela[x + DISTANCIA_QUEDA][y]) {
        xNovo = x + DISTANCIA_QUEDA;
        yNovo = y;
        return 1;
    }

    if (y + DISTANCIA_QUEDA < LARGURA && !tela[x][y + DISTANCIA_QUEDA]) {
        if (x + DISTANCIA_QUEDA < ALTURA && y + 2 * DISTANCIA_QUEDA < LARGURA && !tela[x][y + 2 * DISTANCIA_QUEDA]) {
            xNovo = x + DISTANCIA_QUEDA;
            yNovo = y + DISTANCIA_QUEDA;
            return 1;
        }
    }

    if (y - DISTANCIA_QUEDA >= 0 && !tela[x][y - DISTANCIA_QUEDA]) {
        if (x + DISTANCIA_QUEDA < ALTURA && y - 2 * DISTANCIA_QUEDA >= 0 && !tela[x][y - 2 * DISTANCIA_QUEDA]) {
            xNovo = x + DISTANCIA_QUEDA;
            yNovo = y - DISTANCIA_QUEDA;
            return 1;
        }
    }

    return 0;
}


void realizaQuedas() {
    for (unsigned i = 0; i < ALTURA; i++) {
        for (unsigned j = 0; j < LARGURA; j++) {
            if (tela[i][j] && autenticaQueda(i, j)) {
                if(realizaQueda(i, j)){
                    i = xNovo;
                    j = yNovo;
                    desenhaTela(renderer);
                    SDL_Delay(QUEDA_DELAY);
                }
            }
        }
    }
}
