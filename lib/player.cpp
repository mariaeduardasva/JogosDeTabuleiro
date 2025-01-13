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
string Player::getNick(){
    return _nick;
}
string Player::getNome(){
    return _nome;
}
void Player :: setVitoriaVelha(int quantidade){
    this->vitoriasJogoDaVelha = quantidade;
}
void Player :: setDerrotaVelha(int quantidade){
    this->derrotasJogoDaVelha = quantidade;
}
void Player :: setVitoriaReversi(int quantidade){
    this->vitoriasReversi = quantidade;
}
void Player :: setDerrotaReversi(int quantidade){
    this->derrotasReversi = quantidade;
}
void Player :: setVitoriaLig4(int quantidade){
    this->vitoriaslig4 = quantidade;
}
void Player :: setDerrotaLig4(int quantidade){
    this->derrotaslig4 = quantidade;
}

//getters para vitoria e derrota 

int Player :: getVitoriaVelha(){
    return vitoriasJogoDaVelha;
}
int Player :: getDerrotaVelha(){
    return derrotasJogoDaVelha;
}
int Player :: getVitoriaReversi(){
    return vitoriasReversi;
}
int Player :: getDerrotaReversi(){
    return derrotasReversi;
}
int Player :: getVitoriaLig4(){
    return vitoriaslig4;
}
int Player :: getDerrotaLig4(){
    return derrotaslig4;
}
