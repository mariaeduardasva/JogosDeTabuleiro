#include "JogoDaVelha.hpp"
#include "JogoLig4.hpp"
#include "JogoReversi.hpp"
#include "player.hpp"
#include "cadastro.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void exibirMenu() {
    cout << "============================\n";
    cout << "      SISTEMA DE JOGOS     \n";
    cout << "============================\n";
    cout << "1. Cadastrar Jogador\n";
    cout << "2. Remover Jogador\n";
    cout << "3. Listar Jogadores\n";
    cout << "4. Jogar Jogo da Velha\n";
    cout << "5. Jogar Lig 4\n";
    cout << "6. Jogar Reversi\n";
    cout << "7. Sair\n";
    cout << "Escolha uma opção: ";
}

void executarJogoDaVelha() {
    JogoDaVelha jogo;
    jogo.inicializar();
    jogo.exibirTabuleiro();

    int turno = 1;
    while (true) {
        try {
            cout << "Jogador " << turno << ", faça sua jogada (linha e coluna): ";
            int linha, coluna;
            cin >> linha >> coluna;

            jogo.fazerJogada(turno, linha, coluna);
            jogo.exibirTabuleiro();

            if (jogo.verificarVitoria()) {
                cout << "Parabéns, Jogador " << turno << " venceu!\n";
                break;
            }

            cout << "Deseja desfazer sua jogada? (1-Sim, 0-Não): ";
            int desfazer;
            cin >> desfazer;
            if (desfazer == 1) {
                jogo.desfazerJogada(turno);
                jogo.exibirTabuleiro();
            }

            turno = 3 - turno;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

void executarJogoLig4() {
    JogoLig4 jogo;
    jogo.inicializar();
    jogo.exibirTabuleiro();

    int turno = 1;
    while (true) {
        try {
            cout << "Jogador " << turno << ", escolha a coluna para jogar: ";
            int coluna;
            cin >> coluna;

            jogo.fazerJogada(turno, 0, coluna);
            jogo.exibirTabuleiro();

            if (jogo.verificarVitoria()) {
                cout << "Parabéns, Jogador " << turno << " venceu!\n";
                break;
            }

            turno = 3 - turno;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

void executarJogoReversi() {
    JogoReversi jogo;
    jogo.inicializar();
    jogo.exibirTabuleiro();

    int turno = 1;
    while (true) {
        try {
            cout << "Jogador " << turno << ", faça sua jogada (linha e coluna): ";
            int linha, coluna;
            cin >> linha >> coluna;

            jogo.fazerJogada(turno, linha, coluna);
            jogo.exibirTabuleiro();

            cout << "Pontuação atual:\n";
            jogo.exibirPontuacao();

            if (jogo.verificarVitoria()) {
                cout << "Jogo encerrado!\n";
                break;
            }

            turno = 3 - turno;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

int main() {
    ListaDeJogadores listaDeJogadores;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
        case 1: {
            string nome, apelido;
            cout << "Digite o nome do jogador: ";
            cin >> nome;
            cout << "Digite o apelido do jogador: ";
            cin >> apelido;
            listaDeJogadores.adicionaPlayer(nome, apelido);
            break;
        }
        case 2: {
            string apelido;
            cout << "Digite o apelido do jogador a ser removido: ";
            cin >> apelido;
            listaDeJogadores.deletaPlayer(apelido);
            break;
        }
        case 3:
            listaDeJogadores.ordenaJogadoresEimprimeHistorico();
            break;

        case 4:
            executarJogoDaVelha();
            break;

        case 5:
            executarJogoLig4();
            break;

        case 6:
            executarJogoReversi();
            break;

        case 7:
            cout << "Saindo do sistema...\n";
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }

    } while (opcao != 7);

    return 0;
}
