
# Script para automatizar o ciclo TDD (Test Driven Development)
# Uso: ./commiter.sh <numero_do_teste>
# 
# Este script implementa o ciclo Red-Green-Refactor:
# 1. RED: Implementa o teste (que deve falhar inicialmente)
# 2. GREEN: Implementa o código mínimo para passar no teste
# 3. REFACTOR: Revisa e melhora o código mantendo os testes passando

# Exibe mensagem indicando qual teste está sendo implementado
echo "#: Implementando teste $1"

# FASE 1: COMMIT DO TESTE IMPLEMENTADO
# Adiciona todas as alterações ao staging area do git
git add .

# Faz commit com mensagem padronizada indicando que o teste foi implementado
git commit -m "Teste $1 - ⚙️ Implementado" 

# Verifica se o commit foi bem-sucedido ($? armazena o código de saída do último comando)
if [ $? -ne 0 ]; then
    echo "#: Erro ao fazer commit. Verifique se há alterações a serem commitadas."
    exit 1
fi

# Envia as alterações para o repositório remoto (branch main)
git push origin main

# FASE 2: EXECUÇÃO INICIAL DO TESTE (ESPERADO FALHAR - RED)
echo "#: Teste $1 implementado e commitado com sucesso."
echo "#: Executando teste $1..."

# Executa o comando make para compilar e rodar os testes
make

# Verifica o resultado da execução dos testes
if [ $? -eq 0 ]; then
    echo "#: Teste $1 passou inesperadamente! Esperava-se que falhasse."
    echo "#: Verifique o teste implementado, pois ele deve falhar inicialmente."
    exit 1
fi

echo "#: Teste $1 falhou!"

# Adiciona o resultado da execução e commita a falha do teste
git add .
git commit -m "Teste $1 - ❌ Falhou" 

# FASE 3: PAUSA PARA IMPLEMENTAÇÃO DO CÓDIGO (GREEN)
echo "#: Agora, implemente o código necessário para passar no teste $1."

# Pausa o script e aguarda o usuário implementar o código necessário
read -p "Pressione Enter quando estiver pronto para continuar..."

# FASE 4: EXECUÇÃO DO TESTE APÓS IMPLEMENTAÇÃO (GREEN)
echo "#: Executando o teste $1 novamente..."

# Executa novamente o make para verificar se o teste passou
make

# Verifica o resultado da execução dos testes
if [ $? -eq 0 ]; then
    echo "#: Teste $1 passou com sucesso!"
    # Adiciona as alterações e commita o sucesso do teste
    git add .
    git commit -m "Teste $1 - ✅ Passou"
else
    echo "#: Teste $1 falhou novamente."
fi

# FASE 5: MENSAGENS FINAIS E ORIENTAÇÕES
echo "#: Lembre-se de revisar o código e os testes antes de prosseguir."
echo "#: Se precisar de ajuda, consulte a documentação ou peça ajuda a um colega."
echo "#: Boa sorte com o próximo teste!"
echo "#: Fim do processo para o teste $1."