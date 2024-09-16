#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h> 
#include <time.h>
#include "../include/tela.h"
#include "../include/renderizacao.h"

int main() {
    srand(time(NULL));
    inicializaTela();
    inicializaSDL();

    processaEventos();

    finalizaSDL();
    finalizaTela();

    return 0;
}
