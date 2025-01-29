#include "JogoLig4.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

JogoLig4::JogoLig4() : JogoDeTabuleiro(6, 7) {}

void JogoLig4::inicializar() {
    for (auto& linha : tabuleiro) {
        fill(linha.begin(), linha.end(), '-');
    }
}

bool JogoLig4::fazerJogada(int jogador, int linha, int coluna) {
    if (coluna < 0 || coluna >= colunas) {
        throw out_of_range("ERRO: Coluna inválida!");
    }

    for (int linha = linhas - 1; linha >= 0; --linha) {
        if (tabuleiro[linha][coluna] == '-') {
            tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
            return true;
        }
    }

    throw invalid_argument("ERRO: Coluna cheia!");
}

bool JogoLig4::verificarVitoria() {
    const int CONSECUTIVO = 4;

    // Verifica linhas
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas - CONSECUTIVO; ++coluna) {
            char peca = tabuleiro[linha][coluna];
            if (peca != '-' && all_of(tabuleiro[linha].begin() + coluna, tabuleiro[linha].begin() + coluna + CONSECUTIVO,
                                       [peca](char c) { return c == peca; })) {
                return true;
            }
        }
    }

    // Verifica colunas
    for (int coluna = 0; coluna < colunas; ++coluna) {
        for (int linha = 0; linha <= linhas - CONSECUTIVO; ++linha) {
            char peca = tabuleiro[linha][coluna];
            if (peca != '-' && all_of(tabuleiro.begin() + linha, tabuleiro.begin() + linha + CONSECUTIVO,
                                       [coluna, peca](const vector<char>& row) { return row[coluna] == peca; })) {
                return true;
            }
        }
    }

    // Verifica diagonais principais
    for (int linha = 0; linha <= linhas - CONSECUTIVO; ++linha) {
        for (int coluna = 0; coluna <= colunas - CONSECUTIVO; ++coluna) {
            char peca = tabuleiro[linha][coluna];
            if (peca != '-') {
                bool vitoria = true;
                for (int i = 0; i < CONSECUTIVO; ++i) {
                    if (tabuleiro[linha + i][coluna + i] != peca) {
                        vitoria = false;
                        break;
                    }
                }
                if (vitoria) return true;
            }
        }
    }

    // Verifica diagonais secundárias
    for (int linha = 0; linha <= linhas - CONSECUTIVO; ++linha) {
        for (int coluna = CONSECUTIVO - 1; coluna < colunas; ++coluna) {
            char peca = tabuleiro[linha][coluna];
            if (peca != '-') {
                bool vitoria = true;
                for (int i = 0; i < CONSECUTIVO; ++i) {
                    if (tabuleiro[linha + i][coluna - i] != peca) {
                        vitoria = false;
                        break;
                    }
                }
                if (vitoria) return true;
            }
        }
    }

    return false;
}

void JogoLig4::exibirTabuleiro() {
    cout << "Tabuleiro atual: " << endl;
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {
            cout << tabuleiro[linha][coluna] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
