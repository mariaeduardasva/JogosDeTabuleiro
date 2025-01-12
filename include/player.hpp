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
    void setVitoriaVelha(int quantidade);
    void setDerrotaVelha(int quantidade);
    void setVitoriaReversi(int quantidade);
    void setDerrotaReversi(int quantidade);
    void setVitoriaLig4(int quantidade);
    void setDerrotaLig4(int quantidade);
    string getNick();
    string getNome();
    
};




#endif // PLAYER_H