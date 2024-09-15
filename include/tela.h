#ifndef _tela_h_
#define _tela_h_

#define ALTURA 32
#define LARGURA 32

extern unsigned char **tela;


void inicializaTela();
void setPixel(unsigned x, unsigned y);
void resetPixel(unsigned x, unsigned y);
void printaTela();
unsigned contaParticulas();
void finalizaTela();

#endif