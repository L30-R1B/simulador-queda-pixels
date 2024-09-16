#ifndef _renderizacao_h_
#define _renderizacao_h_

#include <SDL2/SDL.h>

#define WINDOW_SCALE 4

extern SDL_Window* window;
extern SDL_Renderer* renderer;

void inicializaSDL();
void processaEventos();
void desenhaTela();
void finalizaSDL();

#endif