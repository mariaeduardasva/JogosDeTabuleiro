# Jogos de Tabuleiro

## Descrição do Projeto

Este projeto foi desenvolvido como trabalho final da disciplina de Programação e Desenvolvimento de Software II (PDS II). Ele implementa um sistema que permite jogar três jogos clássicos: **Jogo da Velha**, **Lig4** e **Reversi**. O sistema também oferece funcionalidades de cadastro, gerenciamento de jogadores, estatísticas e persistência de dados.

### Jogos Disponíveis
- **Jogo da Velha:** Inclui modo clássico (3x3) e modo infinito (com expansão dinâmica do tabuleiro).
- **Lig4:** Tabuleiro de 6x7 com vitória obtida ao alinhar 4 peças consecutivas.
- **Reversi:** Tabuleiro de 8x8, com critério de desempate baseado nas peças capturadas.

---

## Funcionalidades Implementadas

### Sistema de Gerenciamento de Jogadores
- Cadastro, remoção e listagem de jogadores.
- Estatísticas detalhadas para cada jogador (vitórias e derrotas por jogo).
- Persistência de dados (os jogadores e suas estatísticas são salvos em arquivo para reutilização posterior).

### Funcionalidades Extras
- **Modo Infinito no Jogo da Velha:** O tabuleiro expande dinamicamente para jogos mais longos.
- **Desfazer Jogada:** Permite que cada jogador desfaça a última jogada uma vez.
- **Critério de desempate no Reversi:** Considera as peças capturadas caso haja empate no tabuleiro.
- **Testes Automatizados:** Verificam as principais funcionalidades do **Jogo da Velha**.

---

## Estrutura do Projeto

```plaintext
├── bin/         # Arquivos executáveis
├── include/     # Arquivos de cabeçalho (.hpp)
├── lib/         # Implementações das classes (.cpp)
├── obj/         # Arquivos objeto (.o)
├── src/         # Código-fonte principal
├── tests/       # Arquivos de teste
├── docs/        # Documentação gerada pelo Doxygen
├── Makefile     # Automação da compilação
└── README.md    # Documentação do projeto
```

### Classes Principais

1. **`JogoDeTabuleiro`** (classe abstrata):
   - Representa a base para todos os jogos.
   - Métodos principais:
     - `inicializar()`
     - `fazerJogada()`
     - `verificarVitoria()`
     - `exibirTabuleiro()`

2. **`JogoDaVelha`**, **`JogoLig4`**, **`JogoReversi`**:
   - Implementam as regras e mecânicas específicas de cada jogo.

3. **`Player`**:
   - Armazena informações de jogadores (nome, apelido, vitórias e derrotas).

4. **`ListaDeJogadores`**:
   - Gerencia o cadastro, remoção e listagem de jogadores.
   - Implementa a persistência de dados.

---

## Compilação e Execução

### Pré-requisitos
- **Linux/Windows**
- **Compilador C++** (compatível com C++17)
- **Makefile** instalado

### Passos para Compilação
1. Clone o repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <DIRETORIO_DO_PROJETO>
   ```
2. Compile o programa:
   ```bash
   make
   ```
3. Execute o programa:
   ```bash
   ./bin/programa
   ```
4. Execute os testes (opcional):
   ```bash
   make tests
   ./bin/tests
   ```
5. Limpe os arquivos gerados (opcional):
   ```bash
   make clean
   ```

---

## Documentação

A documentação foi gerada utilizando a ferramenta **Doxygen**. Para acessar:
1. Navegue até a pasta `DocumentaçãoOUT/html`.
2. Abra o arquivo `index.html` no navegador.

---

## Principais Dificuldades e Aprendizados

### Dificuldades
1. **Gerenciamento de múltiplos arquivos:**
   - A modularização do projeto exigiu atenção especial para garantir que as dependências fossem resolvidas corretamente.
2. **Persistência de dados:**
   - Lidar com arquivos para salvar e carregar jogadores demandou cuidados para evitar inconsistências, como linhas em branco ou dados corrompidos.
3. **Integração de funcionalidades extras:**
   - Implementar o modo infinito e o desfazer no Jogo da Velha trouxe desafios relacionados à manipulação dinâmica do tabuleiro e histórico de jogadas.
4. **Testes Automatizados:**
   - Criar testes robustos para garantir o funcionamento correto do sistema foi uma etapa trabalhosa, mas essencial.
5. **Doxygen:**
   - Tivemos dificuldade também em realizar a documentação com a ferramente do Doxygen, mas depois de pesquisar e estudar melhor, conseguimos realizar.

### Aprendizados
- **Programação orientada a objetos:**
   - Aplicação de conceitos como herança, polimorfismo e encapsulamento.
- **Uso de ferramentas de automação:**
   - Aprendizado prático de Makefile para simplificar o processo de compilação.
- **Documentação com Doxygen:**
   - Produção de documentação clara e navegável para projetos de software.
- **Colaboração em equipe:**
   - Controle de versão com Git e gerenciamento de tarefas.

---

## Contribuidores
Este projeto foi desenvolvido por:
- **[Juliane Aparecida Guaracy Ruas Dutra]**
- **[Maria Eduarda Rodrigues Silva]**
- **[Giovanna Vieira Souza]**
- **[Evandro Eurico Morais Penido]**

