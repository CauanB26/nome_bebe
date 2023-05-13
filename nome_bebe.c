/*
Crie um programa que junte o primeiro nome dado a um bebe, com o nome do meio da mae e o ultimo nome do pai.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ultimoNome(char* nomeCompleto);
char* criaNome(char* nomePai, char* nomeMae, char* nomeBebe);


int main(void)
{
	char *nome_bebe = "Dwight"; //Cria nome do bebe
	char* nome_mae = "Pamella Besley Ramos"; //Cria nome da mae
	char *nome_pai = "Jim Halpert da Costa"; //Cria nome do pai

	nome_bebe = criaNome(nome_pai, nome_mae, nome_bebe); // Atribui o novo nome do bebe a string "nome_bebe"
	
	if (nome_bebe == NULL)
	{
		printf("Ocorreu um erro ao alocar o nome do bebe.\n");
	}
	else
	{
		printf("%s", nome_bebe);
		free(nome_bebe);
	}
	
	return 0;
}

char* ultimoNome(char* nomeCompleto)
{
	int i;

	for (i = strlen(nomeCompleto) - 1; i >= 0; i--) // Procurar o último espaço em branco na string
	{
		if (nomeCompleto[i] == ' ')
		{
			char* sobrenome = &nomeCompleto[i + 1]; // Copiar o sobrenome a partir do último espaço em branco encontrado
			return sobrenome;
		}
	}
	return nomeCompleto; // Se não houver espaço em branco na string, retornar a própria string
}

char* criaNome(char* nomePai, char* nomeMae, char* nomeBebe)
{
	char* novo_nome_bebe; //Nova cadeia para guardar o novo_nome_bebe
	int tam_mae, tam_pai, tam_bebe, tam_total;

	tam_mae = strlen(ultimoNome(nomeMae)); //Qtd caracteres nome da mae
	tam_pai = strlen(ultimoNome(nomePai)); //Qtd caracteres nome do pai
	tam_bebe = strlen(ultimoNome(nomeBebe)); //Qtd caracteres nome do bebe
	tam_total = tam_mae + tam_pai + tam_bebe + 3;

	novo_nome_bebe = (char*)malloc(tam_total * sizeof(char));
	if (novo_nome_bebe == NULL)
	{
		printf("Erro ao alocar memoria.\n");
		exit(1); //Não coloquei "return -1", pois, a função tem que retornar um ponteiro para char.
	}

	strcpy(novo_nome_bebe, nomeBebe); //Copia o primeiro nome para o novo_nome_bebe
	strcat(novo_nome_bebe, " "); //Adiciona um espaço
	strcat(novo_nome_bebe, ultimoNome(nomeMae)); //Concatena o primeiro nome do novo_nome_bebe com o sobrenome da mae
	strcat(novo_nome_bebe, " "); //Adiciona um espaço
	strcat(novo_nome_bebe, ultimoNome(nomePai)); //Concatena o primeiro nome do novo_nome_bebe com o sobrenome do pai

	return novo_nome_bebe;
}