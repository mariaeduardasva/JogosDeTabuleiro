#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include "JogoTabuleiro.hpp"
#include <stdexcept>

class JogoDaVelha : public JogoDeTabuleiro {
public:
    JogoDaVelha();

    // inicializa o tabuleiro com valores padrão
    void inicializar() override;

    // Realiza uma jogada; pode lançar exceções em caso de erro
    bool fazerJogada(int jogador, int linha, int coluna) override;

    // Verifica se há uma condição de vitória
    bool verificarVitoria() override;

    ~JogoDaVelha() override = default;
};

#endif


