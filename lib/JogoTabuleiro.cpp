#include "JogoTabuleiro.hpp"
#include <iostream>

using namespace std;

JogoDeTabuleiro::JogoDeTabuleiro(int l, int c) : linhas(l), colunas(c) {
    if (l <= 0 || c <= 0) {
        throw invalid_argument("Dimensões do tabuleiro devem ser maiores que zero!");
    }
    tabuleiro = vector<vector<char>>(linhas, vector<char>(colunas, '-'));
}

void JogoDeTabuleiro::exibirTabuleiro() const {
    cout << "  ";
    for (int i = 0; i < colunas; i++) {
        cout << i << " "; 
    }
    cout << endl;
    
    for (int i = 0; i < linhas; i++) {
        cout << i << " ";
        for (char celula : tabuleiro[i]) {
            cout << celula << " ";
        }
        cout << endl;
    }
}

bool JogoDeTabuleiro::jogadaValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && tabuleiro[linha][coluna] == '-';
}
