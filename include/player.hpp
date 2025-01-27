#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using namespace std;

class Player {
private:
    string nome;
    string nick;
    int vitoriasReversi, derrotasReversi;
    int vitoriasVelha, derrotasVelha;
    int vitoriasLig4, derrotasLig4;

public:
    Player();
    Player(const string &nome, const string &nick);

    string getNome() const;
    string getNick() const;

    int getVitoriaReversi() const;
    int getDerrotaReversi() const;
    void setVitoriaReversi(int v);
    void setDerrotaReversi(int d);

    int getVitoriaVelha() const;
    int getDerrotaVelha() const;
    void setVitoriaVelha(int v);
    void setDerrotaVelha(int d);

    int getVitoriaLig4() const;
    int getDerrotaLig4() const;
    void setVitoriaLig4(int v);
    void setDerrotaLig4(int d);

    void printaVitoriasEderrotas() const;
};

#endif

