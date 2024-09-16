# 🎨 **Tela Interativa com Quedas de Pixels** 🖼️

Bem-vindo ao projeto **Tela Interativa com Quedas de Pixels**! Este programa em C utiliza a biblioteca SDL2 para criar uma simulação visual, onde os pixels caem na tela em uma animação fluida e com cores dinâmicas. O objetivo do programa é criar uma experiência gráfica simples e eficiente, com pré-renderização de áreas estáticas da tela para melhorar a performance.

## 🚀 **Funcionalidades**

- **Quedas de Pixels Dinâmicas**: Simulação de pixels caindo na tela com atualizações contínuas.
- **Renderização Eficiente**: A área abaixo de um demarcador inferior é pré-renderizada para otimizar a performance.
- **Interatividade**: Suporte para eventos do mouse que permitem desenhar pixels com cores customizadas.
- **Atualização de Cor**: As cores dos pixels podem ser alteradas dinamicamente durante a execução.
- **Controle de Velocidade**: Configuração de delay para as quedas, ajustando a fluidez da simulação.

## 📋 **Pré-requisitos**

Antes de compilar e rodar o programa, você precisa instalar as seguintes dependências:

- [SDL2](https://www.libsdl.org/download-2.0.php) - Simple DirectMedia Layer 2.0
- Um compilador C (como `gcc`)

## 🛠️ **Como compilar e executar**

Siga os passos abaixo para compilar e rodar o programa:

1. **Clone o repositório**:
    ```bash
    git clone https://github.com/seu-usuario/simulador-queda-pixels.git
    ```
2. **Navegue até o diretório do projeto**:
    ```bash
    cd simulador-queda-pixels
    ```
3. **Compile o código**:
    ```bash
    make
    ```
4. **Execute o programa**:
    ```bash
    ./bin/main
    ```

## 🎮 **Como usar**

- **Queda de Pixels**: A simulação é iniciada automaticamente com a queda de pixels na tela.
- **Desenho Interativo**: Pressione e segure o botão direito do mouse para desenhar pixels na tela com a cor atual.
- **Demarcador Inferior**: Pixels abaixo do demarcador inferior são pré-renderizados, o que otimiza a performance.

## ⚙️ **Configurações e Ajustes**

Você pode ajustar alguns parâmetros no código para modificar o comportamento da simulação:

- **`DEMARCADOR_SUPERIOR` e `DEMARCADOR_INFERIOR`**: Ajustam os limites da área dinâmica e estática.
- **`WINDOW_SCALE`**: Define o tamanho de cada pixel renderizado.
- **`QUEDA_DELAY`**: Altera a velocidade da queda dos pixels.
  
## 🌈 **Modificação das Cores**

O programa permite a alteração dinâmica de cores com a função `atualizaCor()`, que pode ser ajustada para alterar a paleta de cores dos pixels a cada 5 segundos, ou conforme necessário.

## 🖥️ **Estrutura do Código**

O projeto contém as seguintes funções principais:

- **`desenhaTela()`**: Responsável pela renderização da tela, com otimizações para evitar redesenhar pixels estáticos.
- **`realizaQuedas()`**: Simula a queda dos pixels ativos, atualizando a tela dinamicamente.
- **`processaEventos()`**: Trata a interação do usuário com o mouse e eventos da janela.
  
## 💡 **Melhorias Futuras**

Aqui estão algumas ideias para aprimorar o projeto:

- **Adição de Física Mais Complexa**: Introduzir colisões e comportamentos mais realistas para os pixels.
- **Suporte a Cores Customizadas pelo Usuário**: Permitir que o usuário selecione a cor dos pixels antes de desenhar.
- **Som e Efeitos Visuais**: Adicionar sons e efeitos visuais durante a interação do usuário.

## 🤝 **Contribuições**

Contribuições são muito bem-vindas! Sinta-se à vontade para abrir *issues* ou enviar *pull requests*.
