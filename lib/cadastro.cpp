#include "cadastro.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include<algorithm>

using std::ofstream;
using std::pair;
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
            jogador.setDerrotaVelha(derrotasVelha);
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

void ListaDeJogadores::ordenaJogadoresEimprimeHistorico(){
    vector<string> jogadoresOrganizados;
    for(const auto &pair: players){
        jogadoresOrganizados.push_back(pair.first);
    } 
    sort(jogadoresOrganizados.begin(),jogadoresOrganizados.end());
    for (const auto &nick : jogadoresOrganizados){
        players[nick].printaVitoriasEderrotas();
    }
    
}
void ListaDeJogadores::imprimeJogadoresNoArquivo( Player &player, const string &arquivo) const{
    ofstream arquivoDeSaida(arquivo);
    if(!arquivoDeSaida.is_open()){
        std::cerr << "Erro ao abrir o arquivo para escrita" << endl;
        return;
    }
    arquivoDeSaida << player.getNick() << " " << player.getNome() << " " << player.getVitoriaReversi()
    <<  " " << player.getDerrotaReversi() <<  " " << player.getVitoriaLig4() << " " <<  player.getDerrotaLig4() 
    <<  " " << player.getVitoriaVelha() <<  " " << player.getDerrotaVelha();
}