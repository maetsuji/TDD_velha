# Trabalho TDD
## Rodrigo Rafik Menêzes de Moraes - 232009502

### Legenda:
1. **Matriz de entrada**:
   - O jogo da velha é representado como uma matriz 3x3 de inteiros. 
   - O valor 0 significa que a posição está vazia 
   - O valor 1 significa que a posição está com um X 
   - O valor 2 significa que a posição está com um O
   Ou seja:
   ```plaintext
                                         [X][X][X]
   [[1, 1, 1],[0, 2, 2],[0, 2, 1]]  ==   [ ][O][O]
                                         [ ][O][X]
   ```

2. **Resultado**:
   - Retorna 1 se o vencedor foi o X 
   - Retorna 2 se o vencedor foi o O 
   - Retorna 0 se o jogo está empatado 
   - Retorna -1 se o jogo está indefinido (ex. tem apenas um X) 
   - Retorna -2 se o jogo é com certeza impossível pelas regras (ex. todas as posições são X) 

### Como compilar e executar o programa

1. Certifique-se de que você tenha o compilador `g++`, o utilitário `make` e as demais dependências instaladas no seu sistema.

2. Para compilar e executar os testes, basta executar o comando:
   ```
   make
   ```

   Isso irá:
   - Compilar os arquivos necessários.
   - Gerar o executável `testa_velha`.
   - Executar os testes automaticamente.

3. Caso queira apenas compilar o programa sem executar os testes, use:
   ```
   make compile
   ```

4. Para executar os testes manualmente após a compilação, use:
   ```
   make test
   ```

5. Para verificar o código com o `cpplint` (analisador de estilo), use:
   ```
   make cpplint
   ```

6. Para gerar relatórios de cobertura de código com `gcov`, use:
   ```
   make gcov
   ```

7. Para depurar o programa com o `gdb`, use:
   ```
   make debug
   ```

8. Para verificar vazamentos de memória com o `valgrind`, use:
   ```
   make valgrind
   ```

9. Para limpar os arquivos gerados durante a compilação, use:
   ```
   make clean
   ```

# Observações
- Certifique-se de que o arquivo `Makefile` está no mesmo diretório que os arquivos do projeto.
- O programa foi desenvolvido para validar estados do jogo da velha, retornando um valor numérico conforme a legenda.
- Os testes estão implementados utilizando o framework Catch2.