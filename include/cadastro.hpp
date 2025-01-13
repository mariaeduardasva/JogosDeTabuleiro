#ifndef CADASTRO_H
#include "player.hpp"
#include<map>
#include<string>
#include<fstream>
#include<vector>

using std::ifstream;
using std::ofstream;

using namespace std;

class ListaDeJogadores{
    protected:
    map<string, Player> players;
    
    public:
    Player player;
    void adicionaPlayer (const string &nome, const string &nick);
    void deletaPlayer(const string &nick);
    void leDoArquivo(ifstream &arquivo);
    void ordenaJogadoresEimprimeHistorico();
    void imprimeJogadoresNoArquivo( Player &player, const string &arquivo) const;
};





#endif //CADASTRO_H