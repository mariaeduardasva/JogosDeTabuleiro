#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "JogoDaVelha.cpp"
#include "doctest.h"

TEST_CASE("Teste: inicialização do tabuleiro"){
    JogoDaVelha jogo;
    jogo.inicializar();

    CHECK(jogo.getLinhas() == 3);
    CHECK(jogo.getColunas() == 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            CHECK(jogo.getCelula(i, j) == '-');
        }
    }
}

TEST_CASE("Teste: jogada válida"){
    JogoDaVelha jogo;
    jogo.inicializar();

    CHECK_NOTHROW(jogo.fazerJogada(1, 0, 0));
    CHECK(jogo.getCelula(0, 0) == 'X');
    CHECK_NOTHROW(jogo.fazerJogada(2, 1, 1));
    CHECK(jogo.getCelula(1, 1) == 'O');
}

TEST_CASE("Teste: jogada inválida"){
    JogoDaVelha jogo;
    jogo.inicializar();

    CHECK_THROWS_AS(jogo.fazerJogada(1, 3, 3), std::out_of_range); 
    CHECK_NOTHROW(jogo.fazerJogada(1, 0, 0));
    CHECK_THROWS_AS(jogo.fazerJogada(2, 0, 0), std::invalid_argument); 
}

TEST_CASE("Teste: verificação de vitória"){
    JogoDaVelha jogo;
    jogo.inicializar();

    jogo.fazerJogada(1, 0, 0);
    jogo.fazerJogada(1, 0, 1);
    jogo.fazerJogada(1, 0, 2);

    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste: desfazer jogada"){
    JogoDaVelha jogo;
    jogo.inicializar();

    jogo.fazerJogada(1, 0, 0);
    CHECK(jogo.desfazerJogada(1) == true);
    CHECK(jogo.getCelula(0, 0) == '-');
}
