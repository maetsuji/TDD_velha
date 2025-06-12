#include "velha.hpp"

// Conta quantas vezes um valor (0, 1 ou 2) aparece na matriz
int conta_ocorrencia(int matriz[3][3], int VOX) {
    int contagem = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matriz[i][j] == VOX)
                contagem++;
    return contagem;
}

// Verifica se há algum valor inválido na matriz (não 0, 1, ou 2)
// bool contem_valor_invalido(int matriz[3][3]) {
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (matriz[i][j] < 0 || matriz[i][j] > 2)
//                 return true;
//     return false;
// }

// Retorna o vencedor (1 para X, 2 para O) ou 0 se não houver
int verifica_vencedor(int matriz[3][3]) {
    // Linhas
    for (int i = 0; i < 3; i++)
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0)
            return matriz[i][0];

    // Colunas
    for (int j = 0; j < 3; j++)
        if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[0][j] != 0)
            return matriz[0][j];

    // Diagonal principal
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0)
        return matriz[0][0];

    // Diagonal secundária
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0)
        return matriz[0][2];

    return 0;
}

// Verifica se há mais de um vencedor
bool dois_vencedores(int matriz[3][3]) {
    int cont = 0;
    int vencedor_atual = 0;

    // Linhas
    for (int i = 0; i < 3; i++)
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0)
            if (vencedor_atual == 0)
                vencedor_atual = matriz[i][0];
            else if (vencedor_atual != matriz[i][0])
                return true;

    // Colunas
    for (int j = 0; j < 3; j++)
        if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[0][j] != 0)
            if (vencedor_atual == 0)
                vencedor_atual = matriz[0][j];
            else if (vencedor_atual != matriz[0][j])
                return true;

    // Diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0)
        if (vencedor_atual == 0)
            vencedor_atual = matriz[0][0];
        else if (vencedor_atual != matriz[0][0])
            return true;

    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0)
        if (vencedor_atual == 0)
            vencedor_atual = matriz[0][2];
        else if (vencedor_atual != matriz[0][2])
            return true;

    return false;
}

int valida_velha(int matriz[3][3]) {
    // O jogo da velha é representado como uma matriz 3x3 de inteiros. 
    // O valor 0 significa que a posição está vazia 
    // O valor 1 significa que a posição está com um X 
    // O valor 2 significa que a posição está com um O
    
    // if (contem_valor_invalido(matriz))
    //     return -2;

    int contagemX = conta_ocorrencia(matriz, 1);
    int contagemO = conta_ocorrencia(matriz, 2);
    int contagemVazio = conta_ocorrencia(matriz, 0);

    if (contagemX < contagemO || contagemX > contagemO + 1)
        return -2;

    if (dois_vencedores(matriz))
        return -2;

    int vencedor = verifica_vencedor(matriz);

    if (vencedor == 1 && contagemX != contagemO + 1)
        return -2;

    if (vencedor == 2 && contagemX != contagemO)
        return -2;

    if (vencedor != 0)
        return vencedor;

    if (contagemVazio == 0)
        return 0; // empate

    return -1; // jogo indefinido

    // Retorna 1 se o vencedor foi o X 
    // Retorna 2 se o vencedor foi o O 
    // Retorna 0 se o jogo está empatado 
    // Retorna -1 se o jogo está indefinido (ex. tem apenas um X) 
    // Retorna -2 se o jogo é com certeza impossível pelas regras (ex. todas as posições são X) 

}