#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h> 
#include "../include/tela.h"
#include "../include/renderizacao.h"

int main() {
    inicializaTela();
    inicializaSDL();

    processaEventos();

    finalizaSDL();
    finalizaTela();

    return 0;
}
