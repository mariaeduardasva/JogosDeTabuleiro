#ifndef JOGODAVELHAHPP
#define JOGODAVELHAHPP

#include "JogoTabuleiro.hpp"
#include <vector>
#include <stack>
#include <tuple>

class JogoDaVelha : public JogoDeTabuleiro {
private:
    std::stack<std::tuple<int, int, int>> movimentosFeitos; // Histórico de jogadas (jogador, linha, coluna)
    std::vector<bool> undoDisponivel; // Controle de desfazer movimento para os dois jogadores
    int jogadasFeitas; // Contador de jogadas
    bool modoInfinito; // Indica o modo de jogo (clássico ou infinito)

public:
    JogoDaVelha();

    // Inicializa o tabuleiro com valores padrão e define o modo de jogo
    void inicializar() override;

    // Permite escolher o modo de jogo
    void definirModoJogo();

    // Realiza uma jogada; pode lançar exceções em caso de erro
    bool fazerJogada(int jogador, int linha, int coluna) override;

    // Verifica se há uma condição de vitória
    bool verificarVitoria() override;

    // Expande o tabuleiro dinamicamente
    void expandirTabuleiro(int novasLinhas, int novasColunas);

    // Permite desfazer o último movimento de um jogador
    bool desfazerJogada(int jogador);

    // Exibe o tabuleiro no console
    void exibirTabuleiro() const override;

    ~JogoDaVelha() override = default;
};

#endif


