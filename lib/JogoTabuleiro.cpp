#include "JogoTabuleiro.hpp"
#include <iostream>

using namespace std;

JogoDeTabuleiro::JogoDeTabuleiro(int l, int c) : linhas(l), colunas(c){
    if (l <= 0 || c <= 0) {
        throw invalid_argument("Dimensões do tabuleiro devem ser maiores que zero!");
    }
    tabuleiro = vector<vector<char>>(linhas, vector<char>(colunas, '-'));
}

void JogoDeTabuleiro::exibirTabuleiro() const{
    for (const auto& linha : tabuleiro){
        for (char celula : linha){
            cout << celula << " ";
        }
        cout << endl;
    }
}
