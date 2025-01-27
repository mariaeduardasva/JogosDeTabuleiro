#ifndef JOGOTABULEIRO_H
#define JOGOTABULEIRO_H

#include <vector>
#include <stdexcept>
#include <string>

class JogoDeTabuleiro {
protected:
    std::vector<std::vector<char>> tabuleiro;
    int linhas, colunas;

public:
    JogoDeTabuleiro(int l, int c);

    // Inicializa o tabuleiro
    virtual void inicializar() = 0;

    // Realiza uma jogada
    virtual bool fazerJogada(int jogador, int linha, int coluna) = 0;

    // Verifica condição de vitória
    virtual bool verificarVitoria() = 0;

    // Exibe o tabuleiro no console
    virtual void exibirTabuleiro() const;

    // Virtual destructor
    virtual ~JogoDeTabuleiro() = default;
};

#endif
