#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "JogoTabuleiro.hpp"
#include <stdexcept>

class JogoReversi :public JogoDeTabuleiro{
public:
    JogoReversi();
    void inicializar() override;
    bool fazerJogada(int jogador, int linha, int coluna) override;
    bool verificarVitoria() override;
    void exibirPontuacao() const;

    ~JogoReversi() override = default;

private:
    bool posicaoValida(int linha, int coluna) const;
    bool capturarPecas(int jogador, int linha, int coluna);

    int capturasJogador1;
    int capturasJogador2;
};
#endif
