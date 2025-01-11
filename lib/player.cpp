#include<iostream>
#include<string>
#include "player.hpp"

using std::cout;
using std::endl;

Player::Player(const string &nome, const string &nick):_nome(nome),_nick(nick),vitoriasJogoDaVelha(0),derrotasJogoDaVelha(0),
vitoriaslig4(0),derrotaslig4(0), vitoriasReversi(0),derrotasReversi(0){}

void Player::printaVitoriasEderrotas(){
    cout << "Apelido: " << _nick << " " << "Nome:" << _nome << endl;
    cout << "REVERSI - V: " << vitoriasReversi << " D: " << derrotasReversi << endl;
    cout << "LIG4 - V: " << vitoriasJogoDaVelha << " D: " << derrotasJogoDaVelha << endl;
    cout << "VELHA - V: " << vitoriaslig4 << " D: " << derrotaslig4 << endl;
}