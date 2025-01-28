# Jogos de Tabuleiro

Este projeto implementa três jogos clássicos: Jogo da Velha, Lig4 e Reversi. O sistema permite cadastrar jogadores, gerenciar partidas e acompanhar estatísticas, explorando conceitos de programação orientada a objetos em C++.

## Estrutura do Projeto

```plaintext
├── bin/         # Executáveis gerados
├── include/     # Arquivos de cabeçalho (.hpp)
├── lib/         # Implementações das classes (.cpp)
├── obj/         # Arquivos objeto
├── src/         # Código-fonte principal
├── tests/       # Testes automatizados
├── Makefile     # Compilação automatizada
└── README.md    # Documentação
```

## Compilação e Execução

### Pré-requisitos
- Linux ou Windows
- Compilador C++ compatível com C++17 (ex.: `g++`)
- `make` instalado

### Passos para Compilação
1. Clone o repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_DIRETORIO>
   ```
2. Compile o projeto:
   ```bash
   make
   ```
3. Execute o programa:
   ```bash
   ./bin/programa
   ```
4. Limpe os arquivos gerados (opcional):
   ```bash
   make clean
   ```

## Funcionalidades

### Cadastro de Jogadores
- Adicionar: Coloca jogadores no sistema.
- Remover: Exclui jogadores do sistema.
- Listar: Mostra a lista de jogadores cadastrados.

### Jogos Implementados
1. **Jogo da Velha:**
   - Modo clássico e infinito com expansão dinâmica.
   - Opção de desfazer jogadas.
2. **Lig4:**
   - Tabuleiro 6x7 e vitória com 4 peças consecutivas(horizontal, vertical ou diagonal).
3. **Reversi:**
   - Tabuleiro 8x8 e critério de desempate por capturas.

## Classes Principais
- **`JogoDeTabuleiro` (Abstrata):** Base para os jogos, inicializa o tabuleiro, realiza uma jogada, verifica condição de vitória, exibe o tabuleiro no console.
- **Jogos Específicos:** `JogoDaVelha`, `JogoLig4`, `JogoReversi`(estabelece as regras de cada jogo).
- **`Player`:** Representa jogadores e estatísticas deles.
- **`ListaDeJogadores`:** Gerencia jogadores.

### Testes
-
-


### Principais dificuldades encontradas
- 
---

Este projeto foi desenvolvido para fins acadêmicos e como prática de programação em C++.
