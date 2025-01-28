#ifndef JOGODAVELHAHPP
#define JOGODAVELHAHPP

#include "JogoTabuleiro.hpp"
#include <vector>
#include <stack>
#include <tuple>

class JogoDaVelha : public JogoDeTabuleiro{
private:
    std::stack<std::tuple<int, int, int>> movimentosFeitos; // Histórico de jogadas
    std::vector<bool> undoDisponivel; // Controle de movimento
    int jogadasFeitas; // Jogadas
    bool modoInfinito; // Tipo de jogo

public:
    JogoDaVelha();

    void inicializar() override; 
    void definirModoJogo(); 
    bool fazerJogada(int jogador, int linha, int coluna) override; 
    bool verificarVitoria() override; 
    void expandirTabuleiro(int novasLinhas, int novasColunas); 
    bool desfazerJogada(int jogador);  
    void exibirTabuleiro() const override; 

    ~JogoDaVelha() override = default;
};
#endif


