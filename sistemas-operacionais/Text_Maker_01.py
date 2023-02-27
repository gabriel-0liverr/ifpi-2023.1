import os

print('### Gerador de Texto ###\n')

print('#Caso queira criar um novo arquivo digite um nome inexistente')
print('#Caso queira abrir um arquivo existente apenas digite seu nome, sem o ".txt"')

entries = os.listdir()
print("\nC:/.../Pasta atual/\n",entries,"\n")

#Define o Nome do Arquivo
arquivo_nome = input('Nome do Arquivo: ')
arquivo_nome += ".txt"

#Cria o Arquivo
file = open(arquivo_nome,"w")

#Define Seu Conteúdo
print("\nEscrevendo 'Só alegria hahaha'...")
arquivo_texto = "Só alegria hahaha"

#Escreve no Arquivo
file.write(arquivo_texto)
file.close()

#Log de Conclusão
print('\nO arquivo ',arquivo_nome,' foi salvo com sucesso!')
input('Digite Enter para sair...')