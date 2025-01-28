#include "JogoDaVelha.hpp"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <stack>

using namespace std;

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3), movimentosFeitos(), undoDisponivel({true, true}), modoInfinito(false){}

void JogoDaVelha::inicializar(){
    tabuleiro.resize(3, vector<char>(3, '-'));
    movimentosFeitos = stack<tuple<int, int, int>>(); // Limpa o histórico
    undoDisponivel = {true, true}; // Reseta a possibilidade de desfazer
    jogadasFeitas = 0; // Reinicia o contador
    definirModoJogo(); // Definição de modo
}

void JogoDaVelha::definirModoJogo(){
    cout << "Escolha o modo de jogo:\n1. Clássico (com empate)\n2. Infinito (sem empate)\n";
    int escolha;
    cin >> escolha;
    while (escolha != 1 && escolha != 2){
        cout << "Escolha inválida. Digite 1 para Clássico ou 2 para Infinito: ";
        cin >> escolha;
    }
    modoInfinito = (escolha == 2);
}

bool JogoDaVelha::fazerJogada(int jogador, int linha, int coluna){
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas){
        throw out_of_range("ERRO: Coordenadas fora do tabuleiro!");
    }
    if (tabuleiro[linha][coluna] != '-') {
        throw invalid_argument("ERRO: Posição já ocupada!");
    }
//Expansão
    if (modoInfinito && (linha >= linhas || coluna >= colunas)){
        expandirTabuleiro(max(linha + 1, linhas), max(coluna + 1, colunas));
    }

    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
    movimentosFeitos.push({jogador, linha, coluna});
    jogadasFeitas++;

    // Empate no modo clássico
    if (!modoInfinito && jogadasFeitas >= linhas * colunas){
        throw runtime_error("O jogo terminou em empate! Todas as posições foram ocupadas.");
    }
    return true;
}

bool JogoDaVelha::verificarVitoria(){
    for (int i = 0; i < linhas; ++i){
        for (int j = 0; j <= colunas - 3; ++j){
            if (tabuleiro[i][j] != '-' && tabuleiro[i][j] == tabuleiro[i][j + 1] && tabuleiro[i][j + 1] == tabuleiro[i][j + 2]){
                return true;
            }
        }
    }

    for (int j = 0; j < colunas; ++j){
        for (int i = 0; i <= linhas - 3; ++i){
            if (tabuleiro[i][j] != '-' && tabuleiro[i][j] == tabuleiro[i + 1][j] && tabuleiro[i + 1][j] == tabuleiro[i + 2][j]){
                return true;
            }
        }
    }

    for (int i = 0; i <= linhas - 3; ++i){
        for (int j = 0; j <= colunas - 3; ++j){
            if (tabuleiro[i][j] != '-' && tabuleiro[i][j] == tabuleiro[i + 1][j + 1] && tabuleiro[i + 1][j + 1] == tabuleiro[i + 2][j + 2]){
                return true;
            }
        }
    }

    for (int i = 0; i <= linhas - 3; ++i){
        for (int j = 2; j < colunas; ++j){
            if (tabuleiro[i][j] != '-' && tabuleiro[i][j] == tabuleiro[i + 1][j - 1] && tabuleiro[i + 1][j - 1] == tabuleiro[i + 2][j - 2]){
                return true;
            }
        }
    }
    return false;
}

void JogoDaVelha::expandirTabuleiro(int novasLinhas, int novasColunas){
    tabuleiro.resize(novasLinhas);
    for (auto& linha : tabuleiro){
        linha.resize(novasColunas, '-');
    }
    linhas = novasLinhas;
    colunas = novasColunas;
}

bool JogoDaVelha::desfazerJogada(int jogador){
    if (!undoDisponivel[jogador - 1]){
        throw invalid_argument("ERRO: Jogador já utilizou o desfazer!");
    }

    while (!movimentosFeitos.empty()){
        auto [ultimoJogador, linha, coluna] = movimentosFeitos.top();
        if (ultimoJogador == jogador) {
            tabuleiro[linha][coluna] = '-';
            movimentosFeitos.pop();
            undoDisponivel[jogador - 1] = false;
            jogadasFeitas--;
            return true;
        } else {
            movimentosFeitos.pop();
        }
    }
    throw invalid_argument("ERRO: Nenhuma jogada encontrada para desfazer!");
    
}

void JogoDaVelha::exibirTabuleiro() const{
    for (const auto& linha : tabuleiro){
        for (char celula : linha){
            cout << celula << " ";
        }
        cout << endl;
    }
}
