#ifndef JOGO_LIG4_HPP
#define JOGO_LIG4_HPP

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

    // Exibe o estado atual do tabuleiro
    void exibirTabuleiro(); 

    ~JogoLig4() override = default;
};

#endif
