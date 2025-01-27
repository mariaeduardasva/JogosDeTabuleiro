#ifndef JOGO_REVERSI_HPP
#define JOGO_REVERSI_HPP

#include "JogoTabuleiro.hpp"
#include <stdexcept>

class JogoReversi : public JogoDeTabuleiro {
public:
    JogoReversi();

    // Inicializa o tabuleiro com valores padrão
    void inicializar() override;

    // Realiza uma jogada; pode lançar exceções em caso de erro
    bool fazerJogada(int jogador, int linha, int coluna) override;

    // Verifica se há uma condição de vitória
    bool verificarVitoria() override;

    // Exibe a pontuação das capturas
    void exibirPontuacao() const;

    ~JogoReversi() override = default;

private:
    // Verifica se a posição é válida para jogar
    bool posicaoValida(int linha, int coluna) const;

    // Realiza a captura de peças; retorna true se capturou peças
    bool capturarPecas(int jogador, int linha, int coluna);

    // Contadores de peças capturadas por cada jogador
    int capturasJogador1;
    int capturasJogador2;
};

#endif
