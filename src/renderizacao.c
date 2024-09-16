#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "../include/tela.h"
#include "../include/renderizacao.h"
#include "../include/queda.h"


#define QUEDA_DELAY 1

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* texturaEstatica = NULL;

unsigned ultimoDelInf;

void desenhaTela() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (demarcadorInferior != ultimoDelInf) {
        texturaEstatica = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, LARGURA * WINDOW_SCALE, ALTURA * WINDOW_SCALE);
        ultimoDelInf = demarcadorInferior;

        SDL_SetRenderTarget(renderer, texturaEstatica);

        for (int i = ALTURA - demarcadorInferior; i < ALTURA; i++) {
            for (unsigned j = 0; j < LARGURA; j++) {
                SDL_SetRenderDrawColor(renderer, tela[i][j].r, tela[i][j].g, tela[i][j].b, 255);
                SDL_Rect pixel = { j * WINDOW_SCALE, i * WINDOW_SCALE, WINDOW_SCALE, WINDOW_SCALE };
                SDL_RenderFillRect(renderer, &pixel);
            }
        }

        SDL_SetRenderTarget(renderer, NULL);
    }

    SDL_RenderCopy(renderer, texturaEstatica, NULL, NULL);

    for (int i = ALTURA - demarcadorInferior; i >= (int) demarcadorSuperior; i--) {
        for (unsigned j = 0; j < LARGURA; j++) {
            if (tela[i][j].ativo) {
                SDL_SetRenderDrawColor(renderer, tela[i][j].r, tela[i][j].g, tela[i][j].b, 255);
                SDL_Rect pixel = { j * WINDOW_SCALE, i * WINDOW_SCALE, WINDOW_SCALE, WINDOW_SCALE };
                SDL_RenderFillRect(renderer, &pixel);
            }
        }
    }

    SDL_RenderPresent(renderer);
}


void inicializaSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erro ao inicializar SDL: %s\n", SDL_GetError());
        exit(1);
    }

    ultimoDelInf = 0;

    window = SDL_CreateWindow("Simulação de Areia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGURA * WINDOW_SCALE, ALTURA * WINDOW_SCALE, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Erro ao criar renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

void finalizaSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void processaEventos() {
    SDL_Event event;
    int mouseX, mouseY;
    int clicando = 0;
    Uint32 lastColorUpdate = SDL_GetTicks();  
    const Uint32 colorUpdateInterval = 5000;  

    while (1) {
        Uint32 currentTicks = SDL_GetTicks();

        if (currentTicks - lastColorUpdate >= colorUpdateInterval) {
            atualizaCor();
            atualizaDemarcadorInferior();
            lastColorUpdate = currentTicks;
        }
        
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return;
                
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_RIGHT) {
                        clicando = 1;
                    }
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_RIGHT) {
                        clicando = 0;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    if (clicando) {
                        mouseX = event.motion.x / WINDOW_SCALE;
                        mouseY = event.motion.y / WINDOW_SCALE;

                        if (mouseX < LARGURA && mouseY < ALTURA && mouseX >= 0 && mouseY >= 0) {
                            if(tela[mouseY][mouseX].ativo)
                                break;
                            setPixel(mouseY, mouseX, (Pixel){1, r, g, b});
                            desenhaTela(renderer);
                        }
                    }
                    break;
            }
        }
        atualizaDemarcadorSuperior();
        realizaQuedas();
    }
}

