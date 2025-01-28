#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP

#include "JogoTabuleiro.hpp"
#include <stdexcept>

class JogoLig4 : public JogoDeTabuleiro{
public:
    JogoLig4();
    void inicializar() override;
    bool fazerJogada(int jogador, int linha, int coluna) override;
    bool verificarVitoria() override;
    void exibirTabuleiro(); 

    ~JogoLig4() override = default;
};
#endif
