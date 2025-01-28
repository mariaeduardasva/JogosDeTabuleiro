#include "JogoReversi.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

JogoReversi::JogoReversi() : JogoDeTabuleiro(8, 8), capturasJogador1(0), capturasJogador2(0){}

void JogoReversi::inicializar(){
    for (auto& linha : tabuleiro){
        fill(linha.begin(), linha.end(), '-');
    }

    // posições iniciais padrão
    tabuleiro[3][3] = tabuleiro[4][4] = 'O';
    tabuleiro[3][4] = tabuleiro[4][3] = 'X';
}

bool JogoReversi::fazerJogada(int jogador, int linha, int coluna){
    if (!posicaoValida(linha, coluna)){
        throw out_of_range("ERRO: Coordenadas fora do tabuleiro!");
    }
    if (tabuleiro[linha][coluna] != '-') {
        throw invalid_argument("ERRO: Posição já ocupada!");
    }
    if (!capturarPecas(jogador, linha, coluna)){
        throw invalid_argument("ERRO: Jogada não captura peças do adversário!");
    }

    tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
    return true;
}

bool JogoReversi::verificarVitoria(){
    int countX = 0, countO = 0;
    for (const auto& linha : tabuleiro){
        for (char celula : linha){
            if (celula == 'X') ++countX;
            else if (celula == 'O') ++countO;
        }
    }

    cout << "Resultado Final: X = " << countX << ", O = " << countO << endl;

    // critério de desempate
    if (countX == countO){
        if (capturasJogador1 > capturasJogador2){
            cout << "Vencedor por desempate: Jogador X (peças capturadas)" << endl;
        } else if (capturasJogador1 < capturasJogador2){
            cout << "Vencedor por desempate: Jogador O (peças capturadas)" << endl;
        } else {
            cout << "Empate total!" << endl;
        }
    } else {
        //determina vencedor
        if (countX > countO) {
            cout << "Vencedor: Jogador X!" << endl;
        } else {
            cout << "Vencedor: Jogador O!" << endl;
        }
    }

    return countX + countO == linhas * colunas;
}

bool JogoReversi::posicaoValida(int linha, int coluna) const{
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

bool JogoReversi::capturarPecas(int jogador, int linha, int coluna){
    char peca = (jogador == 1) ? 'X' : 'O';
    char adversario = (jogador == 1) ? 'O' : 'X';
    bool capturou = false;

    // direções (linha, coluna)
    const vector<pair<int, int>> direcoes ={
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // verificação das direções
    for (const auto& [dLinha, dColuna] : direcoes){
        int x = linha + dLinha;
        int y = coluna + dColuna;
        bool temAdversario = false;
        vector<pair<int, int>> pecasCapturadas;

        // verificação de peças adversárias
        while (posicaoValida(x, y) && tabuleiro[x][y] == adversario){
            pecasCapturadas.push_back({x, y});
            x += dLinha;
            y += dColuna;
            temAdversario = true;
        }

        // caso encontrou uma peça adversária e uma peça do jogador no final da direção
        if (temAdversario && posicaoValida(x, y) && tabuleiro[x][y] == peca){
            // captura as peças do adversário
            for (const auto& [capturadaX, capturadaY] : pecasCapturadas){
                tabuleiro[capturadaX][capturadaY] = peca;

                // atualiza o contador de peças capturadas
                if (peca == 'X'){
                    capturasJogador1++;
                } else {
                    capturasJogador2++;
                }
            }
            capturou = true;
        }
    }

    return capturou;
}

void JogoReversi::exibirPontuacao() const{
    cout << "Pontuação de capturas: Jogador X = " << capturasJogador1
         << ", Jogador O = " << capturasJogador2 << endl;
}
