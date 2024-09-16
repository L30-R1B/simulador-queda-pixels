#ifndef _tela_h_
#define _tela_h_

#define ALTURA 128
#define LARGURA 128

typedef struct {
    unsigned char ativo;
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel, Tela;

extern Tela **tela;
extern unsigned char r, g, b;
extern unsigned demarcadorInferior;
extern unsigned demarcadorSuperior;

void inicializaTela();
void atualizaCor();
unsigned atualizaDemarcadorInferior();
unsigned atualizaDemarcadorSuperior();
void setPixel(unsigned x, unsigned y, Pixel p);
void resetPixel(unsigned x, unsigned y);
void finalizaTela();

#endif