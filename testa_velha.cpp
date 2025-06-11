#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "velha.hpp"


TEST_CASE( "Jogos da Velha", "[jogos]" ) {
    // Implementar testes aqui:
    int tabuleiro[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    REQUIRE( valida_velha(tabuleiro) == -1); // Indefinido
}
