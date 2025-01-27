#include "player.hpp"
#include <iostream>

using std::cout;
using std::endl;

Player::Player() : nome(""), nick(""), vitoriasReversi(0), derrotasReversi(0),
                   vitoriasVelha(0), derrotasVelha(0), vitoriasLig4(0), derrotasLig4(0) {}

Player::Player(const string &nome, const string &nick) 
    : nome(nome), nick(nick), vitoriasReversi(0), derrotasReversi(0), 
      vitoriasVelha(0), derrotasVelha(0), vitoriasLig4(0), derrotasLig4(0) {}

void Player::printaVitoriasEderrotas() const {
    cout << "Nick: " << nick << " Nome: " << nome << endl;
    cout << "Reversi - Vitórias: " << vitoriasReversi << ", Derrotas: " << derrotasReversi << endl;
    cout << "Lig4 - Vitórias: " << vitoriasLig4 << ", Derrotas: " << derrotasLig4 << endl;
    cout << "Velha - Vitórias: " << vitoriasVelha << ", Derrotas: " << derrotasVelha << endl;
}

// Setters
void Player::setVitoriaVelha(int v) { vitoriasVelha = v; }
void Player::setDerrotaVelha(int d) { derrotasVelha = d; }
void Player::setVitoriaReversi(int v) { vitoriasReversi = v; }
void Player::setDerrotaReversi(int d) { derrotasReversi = d; }
void Player::setVitoriaLig4(int v) { vitoriasLig4 = v; }
void Player::setDerrotaLig4(int d) { derrotasLig4 = d; }

// Getters
int Player::getVitoriaVelha() const { return vitoriasVelha; }
int Player::getDerrotaVelha() const { return derrotasVelha; }
int Player::getVitoriaReversi() const { return vitoriasReversi; }
int Player::getDerrotaReversi() const { return derrotasReversi; }
int Player::getVitoriaLig4() const { return vitoriasLig4; }
int Player::getDerrotaLig4() const { return derrotasLig4; }
string Player::getNick() const { return nick; }
string Player::getNome() const { return nome; }
