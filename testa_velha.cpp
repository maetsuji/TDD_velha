#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "velha.hpp"


TEST_CASE( "Jogos da Velha", "[jogos]" ) {
    // Implementar testes aqui:
    int tabuleiro1[3][3] = {{0,0,0},{0,0,0},{0,0,0}};    // Teste 1
    int resultado1 = -1;                                                                                                                                                                                                                                                                                                                                                                                                                                           // Indefinido
    REQUIRE( valida_velha(tabuleiro1) == resultado1);
    
    int tabuleiro2[3][3] = {{1,1,1},{0,0,0},{2,2,0}};    // Teste 2
    int resultado2 = 1;  // Jogador 1 venceu
    REQUIRE( valida_velha(tabuleiro2) == resultado2);

    int tabuleiro3[3][3] = {{2,0,0},{2,0,0},{2,1,1}};    // Teste 3
    int resultado3 = -2; // Proibido, Quantidade de O é maior que a de X
    REQUIRE( valida_velha(tabuleiro3) == resultado3);

    int tabuleiro4[3][3] = {{1,1,2},{2,1,1},{1,2,2}};    // Teste 4
    int resultado4 = 0 ; // Empate
    REQUIRE( valida_velha(tabuleiro4) == resultado4);

    int tabuleiro7[3][3] = {{1,2,1},{2,1,1},{2,2,1}};    // Teste 7
    int resultado7 = 1; // permitido
    REQUIRE( valida_velha(tabuleiro7) == resultado7);
}

TEST_CASE( "Jogos da Velha Invalidos", "[jogos]" ) {
    int tabuleiro5a[3][3] = {{2,2,0},{0,1,0},{0,0,0}};    // Teste 5
    int resultado5a = -2; // Proibido, Quantidade de O é maior que a de X
    REQUIRE( valida_velha(tabuleiro5a) == resultado5a);

    int tabuleiro5b[3][3] = {{2,2,2},{1,1,1},{0,0,0}};    // Teste 5
    int resultado5b = -2; // Proibido, dois jogadores venceram na horizontal
    REQUIRE( valida_velha(tabuleiro5b) == resultado5b);

    int tabuleiro6[3][3] = {{2,0,1},{2,0,1},{2,0,1}};    // Teste 6
    int resultado6 = -2; // Proibido, dois jogadores venceram na vertical
    REQUIRE( valida_velha(tabuleiro6) == resultado6);

    int tabuleiro8[3][3] = {{1,1,1},{1,1,1},{1,1,1}};    // Teste 8
    int resultado8 = -2; // tudo x
    REQUIRE( valida_velha(tabuleiro8) == resultado8);
}

TEST_CASE( "Mais Jogos da Velha", "[jogos]" ) {
    int tabuleiro9[3][3] = {{0,0,0},{0,0,0},{0,0,0}};    // Teste 9
    int resultado9 = -1; // Indefinido
    REQUIRE( valida_velha(tabuleiro9) == resultado9);

    int tabuleiro10[3][3] = {{1,1,1},{0,99,0},{2,2,0}};    // Teste 10
    int resultado10 = -2; // Proibido, valor inválido (99)
    REQUIRE( valida_velha(tabuleiro10) == resultado10);
}
