#ifndef JOGOTABULEIRO_HPP
#define JOGOTABULEIRO_HPP

#include <string>
#include <vector>
#include <stdexcept>

class JogoDeTabuleiro{
protected:
    std::vector<std::vector<char>> tabuleiro;
    int linhas, colunas;

public:
    JogoDeTabuleiro(int l, int c);

    virtual void inicializar() = 0;
    virtual bool fazerJogada(int jogador, int linha, int coluna) = 0;
    virtual bool verificarVitoria() = 0;
    virtual void exibirTabuleiro() const;
    virtual ~JogoDeTabuleiro() = default;
};
#endif
