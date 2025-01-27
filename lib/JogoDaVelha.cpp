#include "JogoDaVelha.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

void JogoDaVelha::inicializar() {
    for (auto& linha : tabuleiro) {
        fill(linha.begin(), linha.end(), '-');
    }
}

bool JogoDaVelha::fazerJogada(int jogador, int linha, int coluna) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
        throw out_of_range("ERRO: Coordenadas fora do tabuleiro!");
    }
    if (tabuleiro[linha][coluna] != '-') {
        throw invalid_argument("ERRO: Posição já ocupada!");
    }
    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
    return true;
}

bool JogoDaVelha::verificarVitoria() {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] != '-' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return true;
        }
        if (tabuleiro[0][i] != '-' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return true;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return true;
    }
    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return true;
    }

    return false;
}

