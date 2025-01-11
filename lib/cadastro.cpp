#include "cadastro.hpp"

void ListaDeJogadores::adicionaPlayer(const string &nome, const string &nick){
    if(players.find(nome) != players.end()){
        cout<< "ERRO: Jogador repetido" << endl;
        return;
    }
    players[nick] = Player(nome, nick);
    cout<< "Jogador: "<< nick << "cadastrado com sucesso!" << endl;

}
void ListaDeJogadores::deletaPlayer(const string &nome, const string &nick){
    auto it = players.find(nick);
    if(it != players.end()){
        players.erase(nick);
        cout << "Jogador " << nick << " apagado com sucesso! " << endl;
        return;
    }else{
        cout<< "Jogador inesistente" << endl;
    }
}