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
A decisão de utilizar o C++17 neste projeto foi motivada pelos recursos e aprimoramentos que essa versão oferece, tornando o código mais eficiente e fácil de manter. O padrão é amplamente suportado e consolidado pela maioria dos compiladores, garantindo compatibilidade em diversos ambientes de desenvolvimento. Além disso, o C++17 incentiva boas práticas de programação, fornecendo recursos que ajudam a evitar erros comuns.

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
   - Modo clássico com tabuleiro 3x3 e infinito com expansão dinâmica.
   - Opção de desfazer a última jogada.
     
2. **Lig4:**
   - Tabuleiro 6x7 e vitória com 4 peças consecutivas (horizontal, vertical ou diagonal).
     
3. **Reversi:**
   - Tabuleiro 8x8 e critério de desempate por capturas.

## Classes Principais
- **`JogoDeTabuleiro` (Abstrata):** Base para os jogos, inicializa o tabuleiro, realiza uma jogada, verifica condição de vitória, exibe o tabuleiro no console.
- **Jogos Específicos:** `JogoDaVelha`, `JogoLig4`, `JogoReversi`(estabelece as regras de cada jogo).
- **`Player`:** Representa jogadores e estatísticas deles.
- **`ListaDeJogadores`:** Gerencia jogadores.

### Tests
- Teste do jogo da velha.
- Utilizamos a biblioteca Doctest como arquivo de teste para o jogo da velha. Este arquivo contém uma série de casos de teste que verificam as funcionalidades da classe "Jogodavelha".
- Primeiro testamos a inicialização do tabuleiro, se é inicializado de forma correta com 3 linhas, 3 colunas e se todas as células estão preenchidas com o caractere"-".
- Depois testamos se o método fazerjogada funciona corretamente ao realizar jogadas e se as células são atualizadas de forma correta.
- Após isso, verificamos se o método verificarVitoria detecta de forma correta uma vitória ao preencher uma linha com peças do mesmo jogador.
- Por último, testamos o recurso de desfazer jogada. Analisamos se o método desfazerJogada remove sem erros a última jogada e se o tabuleiro é atualizado com esta remoção.


### Principais dificuldades encontradas
- Gerenciar arquivos múltiplos simultaneamente.
- Lidar com a preocupação de efeitos em cascata, visto que alterações em um trecho do código podem impactar outras partes do sistema.
  
---

Este projeto foi desenvolvido para fins acadêmicos e como prática de programação em C++.
