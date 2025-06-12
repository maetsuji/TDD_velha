# Makefile para projeto TDD - Jogo da Velha
# Autor: Rodrigo Rafik Menêzes de Moraes - 232009502

# Target principal: compila e executa os testes
all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha

# Apenas compila o programa sem executar
compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha	

# Executa apenas os testes (requer compilação prévia)
test: testa_velha	
	./testa_velha
	
# Verifica estilo do código com cpplint
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint   --exclude=catch.hpp  *.*
	
# Gera relatório de cobertura de código com gcov
gcov: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.cpp	
	
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck  --enable=warning . 

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -Wall -c velha.cpp
	
testa_velha: 	testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

clean:
	rm -rf *.o *.exe *.gc* 
	
	
