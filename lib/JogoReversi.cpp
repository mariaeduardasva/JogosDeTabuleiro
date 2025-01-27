#include "JogoReversi.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

JogoReversi::JogoReversi() : JogoDeTabuleiro(8, 8) {}

void JogoReversi::inicializar() {
    for (auto& linha : tabuleiro) {
        fill(linha.begin(), linha.end(), '-');
    }

    // Posições iniciais padrão
    tabuleiro[3][3] = tabuleiro[4][4] = 'O';
    tabuleiro[3][4] = tabuleiro[4][3] = 'X';
}

bool JogoReversi::fazerJogada(int jogador, int linha, int coluna) {
    if (!posicaoValida(linha, coluna)) {
        throw out_of_range("ERRO: Coordenadas fora do tabuleiro!");
    }
    if (tabuleiro[linha][coluna] != '-') {
        throw invalid_argument("ERRO: Posição já ocupada!");
    }
    if (!capturarPecas(jogador, linha, coluna)) {
        throw invalid_argument("ERRO: Jogada não captura peças do adversário!");
    }

    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
    return true;
}

bool JogoReversi::verificarVitoria() {
    int countX = 0, countO = 0;
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            if (celula == 'X') ++countX;
            else if (celula == 'O') ++countO;
        }
    }

    cout << "Resultado Final: X = " << countX << ", O = " << countO << endl;
    return countX + countO == linhas * colunas;
}

bool JogoReversi::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

bool JogoReversi::capturarPecas(int jogador, int linha, int coluna) {
    char peca = (jogador == 1) ? 'X' : 'O';
    char adversario = (jogador == 1) ? 'O' : 'X';
    bool capturou = false;

    // Direções (linha, coluna)
    const vector<pair<int, int>> direcoes = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (const auto& [dLinha, dColuna] : direcoes) {
        int x = linha + dLinha;
        int y = coluna + dColuna;
        bool temAdversario = false;

        while (posicaoValida(x, y) && tabuleiro[x][y] == adversario) {
            x += dLinha;
            y += dColuna;
            temAdversario = true;
        }

        if (temAdversario && posicaoValida(x, y) && tabuleiro[x][y] == peca) {
            // Capturar peças
            x -= dLinha;
            y -= dColuna;
            while (x != linha || y != coluna) {
                tabuleiro[x][y] = peca;
                x -= dLinha;
                y -= dColuna;
            }
            capturou = true;
        }
    }

    return capturou;
}
