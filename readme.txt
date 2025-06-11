Trabalho TDD - Rodrigo Rafik Menêzes de Moraes - 232009502

Como compilar e executar o programa

1. Certifique-se de que você tenha o compilador g++, o utilitário make, o catch2 e as demais dependências instaladas no seu sistema.

2. Navegue até o diretório do projeto:
   cd TDD_romanos

3. Para compilar e executar os testes, basta executar o comando:
   make

   Isso irá:
   - Compilar os arquivos necessários.
   - Gerar o executável testa_romanos.
   - Executar os testes automaticamente.

4. Caso queira apenas compilar o programa sem executar os testes, use:
   make compile

5. Para executar os testes manualmente após a compilação, use:
   make test

6. Para verificar o código com o cpplint (analisador de estilo), use:
   make cpplint

7. Para gerar relatórios de cobertura de código com gcov, use:
   make gcov

8. Para depurar o programa com o gdb, use:
   make debug

9. Para verificar vazamentos de memória com o valgrind, use:
   make valgrind

10. Para limpar os arquivos gerados durante a compilação, use:
    make clean

Observações:
- Certifique-se de que o arquivo Makefile está no mesmo diretório que os arquivos do projeto.
- O programa foi desenvolvido para converter números romanos em decimais e validar entradas inválidas.
- Os testes estão implementados utilizando o framework Catch2.