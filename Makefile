# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -g `sdl2-config --cflags`

# Nome do executável
TARGET = main

# Diretórios
OBJDIR = obj
BINDIR = bin

# Lista de arquivos fonte
SOURCES = src/main.c src/tela.c src/queda.c src/renderizacao.c

# Lista de cabeçalhos
HEADERS = include/tela.h include/queda.h include/renderizacao.h

# Gera os nomes dos arquivos objeto
OBJECTS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Regra principal para construir o executável
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)  # Cria o diretório bin se não existir
	$(CC) $(CFLAGS) $(OBJECTS) `sdl2-config --libs` -lm -lz -o $@

# Regra para construir arquivos objeto a partir de arquivos fonte
$(OBJDIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(OBJDIR)  # Cria o diretório obj se não existir
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos intermediários e o executável
clean:
	rm -f $(OBJECTS) $(BINDIR)/$(TARGET)

.PHONY: clean
