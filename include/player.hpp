#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>

using std::string;




class Player
{
protected:
    string _nome;
    string _nick;
    int vitoriasJogoDaVelha;
    int derrotasJogoDaVelha;
    int vitoriasReversi;
    int derrotasReversi;
    int derrotaslig4;
    int vitoriaslig4;
public:
    Player(const string &nome, const string &nick);
    void printaVitoriasEderrotas();
    ~Player(){};
};




#endif // PLAYER_H