#include "velha.hpp"
#include <cstring> // For strlen

int conta_ocorrencia(int matriz[3][3], int VOX) { // Recebe uma matriz de inteiros com 3 linhas e 3 colunas
    // Esta função conta quantos X e O existem na matriz.
    int contagem = 0; // Inicializa o contador de ocorrências
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == VOX) {
                contagem++;
            }
        }
    }
    return contagem; // Retorna o número de ocorrências de Vazios, X ou O
}
int valida_velha(int matriz[3][3]) { // Recebe uma matriz de inteiros com 3 linhas e 3 colunas
    // O jogo da velha é representado como uma matriz 3x3 de inteiros. 
    // O valor 0 significa que a posição está vazia 
    // O valor 1 significa que a posição está com um X 
    // O valor 2 significa que a posição está com um O
    
    int resultado = -1; // Inicializa o resultado como indefinido, deixando para acertar a lógica depois
    int vencedorFlag = 0; // Inicializa o vencedor final como 0 (nenhum vencedor)

    // Percorre a matriz para contar quantos X, O e posições vazias existem
    // Isso é importante para determinar o estado do jogo
    // e se o jogo é válido ou não.
    int contagemX = conta_ocorrencia(matriz, 1); // Contador de X
    int contagemO = conta_ocorrencia(matriz, 2); // Contador de O
    int contagemVazio = conta_ocorrencia(matriz, 0); // Contador de posições vazias

    // Verifica se há um vencedor:
    if (contagemX < contagemO || contagemX > contagemO + 1) {
        // Se a quantidade de X é menor que a de O ou maior que a de O + 1, o jogo é impossível
        resultado = -2; // Jogo impossível pelas regras
    } else {
        // Verifica linhas
        if (!vencedorFlag) {
            for (int i = 0; i < 3; i++) {
                if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
                    if (matriz[i][0] == 1) {
                        if (vencedorFlag) {
                            return -2; // Se já encontrou um vencedor, mas ainda está verificando, é inválido
                        } else {
                            vencedorFlag = 1; // Marca que já encontrou um vencedor
                            resultado = 1; // O venceu
                        }
                    } else if (matriz[i][0] == 2) {
                        if (vencedorFlag) {
                            return -2; // Se já encontrou um vencedor, mas ainda está verificando, é inválido
                        } else {
                            vencedorFlag = 1; // Marca que já encontrou um vencedor
                            resultado = 2; // O venceu
                        }
                    }
                }
            }
        }
                // Verifica colunas
        if (!vencedorFlag) {            
            for (int j = 0; j < 3; j++) {
                if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j]) {
                    if (matriz[0][j] == 1) {
                        if (vencedorFlag) {
                            resultado = -2; // Se já encontrou um vencedor, mas ainda está verificando, é inválido
                        } else {
                            vencedorFlag = 1; // Marca que já encontrou um vencedor
                            resultado = 1; // X venceu
                        }
                    } else if (matriz[0][j] == 2) {
                        if (vencedorFlag) {
                            return -2; // Se já encontrou um vencedor, mas ainda está verificando, é inválido
                        } else {
                            vencedorFlag = 1; // Marca que já encontrou um vencedor
                            resultado = 2; // O venceu
                        }
                    }
                }
            }
        }
        // Verifica diagonal principal 
        if (!vencedorFlag) { 
            if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
                if (matriz[0][0] == 1) {
                    resultado = 1; // X venceu
                    vencedorFlag = 1; // Marca que já encontrou um vencedor
                } else if (matriz[0][0] == 2) {
                    resultado = 2; // O venceu
                    vencedorFlag = 1; // Marca que já encontrou um vencedor
                }
            }
        }
        // Verifica diagonal secundária
        if (!vencedorFlag) { 
            if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
                if (matriz[0][2] == 1) {
                    resultado = 1; // X venceu
                    vencedorFlag = 1; // Marca que já encontrou um vencedor
                } else if (matriz[0][2] == 2) {
                    resultado = 2; // O venceu
                    vencedorFlag = 1; // Marca que já encontrou um vencedor
                }
            }
        }
        if (!vencedorFlag) {
            // Se não houve vencedor, verifica se o jogo está empatado
            if (contagemVazio == 0) {
                resultado = 0; // Empate
            } else {
                resultado = -1; // Jogo indefinido (ex. tem apenas um X)
            }
        }
    }

    return resultado; 
    // Retorna 1 se o vencedor foi o X 
    // Retorna 2 se o vencedor foi o O 
    // Retorna 0 se o jogo está empatado 
    // Retorna -1 se o jogo está indefinido (ex. tem apenas um X) 
    // Retorna -2 se o jogo é com certeza impossível pelas regras (ex. todas as posições são X) 
}