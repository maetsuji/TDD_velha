#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "velha.hpp"


TEST_CASE( "Jogos da Velha", "[jogos]" ) {
    // Implementar testes aqui:
    int tabuleiro[3][3] = {{0,0,0},{0,0,0},{0,0,0}}; // Teste 1
    int resultado = -1  // Indefinido
    REQUIRE( valida_velha(tabuleiro) == resultado);
    
    int tabuleiro[3][3] = {{1,1,1},{0,0,0},{2,2,0}};// Teste 2
    resultado = 1;  // Jogador 1 venceu
    REQUIRE( valida_velha(tabuleiro) == resultado);
}
