echo "#: Implementando teste $1"

git add .
git commit -m "Teste $1 - Implementado" 
if [ $? -ne 0 ]; then
    echo "#: Erro ao fazer commit. Verifique se há alterações a serem commitadas."
    exit 1
fi
git push origin main

echo "#: Teste $1 implementado e commitado com sucesso."
echo "#: Executando teste $1..."
make
echo "#: Teste $1 (provavelmente) falhou!"
git add .
git commit -m "Teste $1 - ❌ Falhou" 
echo "#: Agora, implemente o código necessário para passar no teste $1."
# aguardar um OK do usuário
read -p "Pressione Enter quando estiver pronto para continuar..."
echo "#: Executando o teste $1 novamente..."
make
if [ $? -eq 0 ]; then
    echo "#: Teste $1 passou com sucesso!"
    git add .
    git commit -m "Teste $1 - ✅ Passou"
else
    echo "#: Teste $1 falhou novamente."
fi
echo "#: Lembre-se de revisar o código e os testes antes de prosseguir."
echo "#: Se precisar de ajuda, consulte a documentação ou peça ajuda a um colega."
echo "#: Boa sorte com o próximo teste!"
echo "#: Fim do processo para o teste $1."