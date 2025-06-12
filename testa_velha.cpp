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
}
