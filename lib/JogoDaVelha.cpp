#include "JogoDaVelha.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <stack>

using namespace std;

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3), movimentosFeitos(), undoDisponivel({true, true}), modoInfinito(false) {}

void JogoDaVelha::inicializar() {
    tabuleiro.resize(3, vector<char>(3, '-'));
    movimentosFeitos = stack<tuple<int, int, int>>();
    undoDisponivel = {true, true}; 
    definirModoJogo();
}

void JogoDaVelha::definirModoJogo() {
    cout << "Escolha o modo de jogo:\n1. Clássico (com empate)\n2. Infinito (sem empate)\n";
    int escolha;
    while (!(cin >> escolha) || (escolha != 1 && escolha != 2)) {
        cout << "Escolha inválida. Digite 1 para Clássico ou 2 para Infinito: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    modoInfinito = (escolha == 2);
}

bool JogoDaVelha::fazerJogada(int jogador, int linha, int coluna) {
    if (!jogadaValida(linha, coluna)) {
        throw invalid_argument("ERRO: Posição inválida ou já ocupada!");
    }

    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
    movimentosFeitos.push({jogador, linha, coluna});
    jogadasFeitas++;

    if (!modoInfinito && jogadasFeitas >= linhas * colunas) {
        throw runtime_error("O jogo terminou em empate! Todas as posições foram ocupadas.");
    }
    return true;
}
