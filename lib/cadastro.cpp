#include "cadastro.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void ListaDeJogadores::adicionaPlayer(const string &nome, const string &nick){
    if(players.find(nick) != players.end()){
        cout << "ERRO: Jogador repetido" << endl;
        return;
    }
    players[nick] = Player(nome, nick);
    cout << "Jogador: " << nick << " cadastrado com sucesso!" << endl;
}

void ListaDeJogadores::deletaPlayer(const string &nick){
    auto it = players.find(nick);
    if(it != players.end()){
        players.erase(nick);
        cout << "Jogador " << nick << " apagado com sucesso!" << endl;
        return;
    } else {
        cout << "Jogador inexistente" << endl;
    }
}

void ListaDeJogadores::leDoArquivo(ifstream &arquivo){
    string nome, nick;
    int vitoriasReversi, derrotasReversi, vitoriasVelha, derrotasVelha, vitoriasLig4, derrotasLig4;
    
    if (arquivo.is_open()) {
        while(arquivo >> nome >> nick >> vitoriasReversi >> derrotasReversi >> vitoriasVelha >> derrotasVelha >> vitoriasLig4 >> derrotasLig4) {
            Player jogador(nome, nick);
            jogador.setVitoriaVelha(vitoriasVelha);
            jogador.setVitoriaVelha(derrotasVelha);
            jogador.setVitoriaReversi(vitoriasReversi);
            jogador.setDerrotaReversi(derrotasReversi);
            jogador.setVitoriaLig4(vitoriasLig4);
            jogador.setDerrotaLig4(derrotasLig4);
            players[nick] = jogador;
        }
    } else {
        cout << "Erro: nao foi possivel abrir o arquivo" << endl;
    }
}

void ListaDeJogadores::adicionaPlayer(const string &nome, const string &nick){
    if (players.find(nick) != players.end())
    {
       cout<<"Erro: jogador repetido" << endl;
    }
    players[nick] = Player(nick, nome);
    cout << "Jogador " << nick << "adicionado com sucesso!" << endl; 
}