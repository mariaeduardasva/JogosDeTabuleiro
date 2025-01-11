#ifndef CADASTRO_H
#include "player.hpp"
#include<map>
#include<string>

using namespace std;

class ListaDeJogadores{
    protected:
    map<string, Player> players;
    public:
    void adicionaPlayer (const string &nome, const string &nick);
    void deletaPlayer(const string &nome,  const string &nick);
};





#endif //CADASTRO_H