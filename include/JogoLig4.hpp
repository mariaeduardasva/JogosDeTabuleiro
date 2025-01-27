#ifndef JOGOLIG4_H
#define JOGOLIG4_H

#include "JogoTabuleiro.hpp"
#include <stdexcept>

class JogoLig4 : public JogoDeTabuleiro {
public:
    JogoLig4();

    // Inicializa o tabuleiro com valores padrão
    void inicializar() override;

    // Realiza uma jogada; pode lançar exceções em caso de erro
    bool fazerJogada(int jogador, int linha, int coluna) override;

    // Verifica se há uma condição de vitória
    bool verificarVitoria() override;

    ~JogoLig4() override = default;
};

#endif

