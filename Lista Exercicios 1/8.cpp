//	Exercicio 8 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/***************************************************
Crie uma fun��o que receba uma string como par�metro 
(de tamanho desconhecido) e retorne uma c�pia da 
mesma. A assinatura da fun��o deve ser: 
char* strcopy(char *str);
***************************************************/

//
//
// 	PROGRAMA BRICA COM ESPACOS!!
//
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

char* strcopy(char *str) {
	
	int sizeStr = 0, i = 0;	
	//tamanho? Lembrar que string termina com '\0'!
	for (sizeStr = 0; str[sizeStr] != '\0'; sizeStr++)
	{}
	//alocar memoria
	char *nstr = (char*)malloc(sizeStr * sizeof(char));
	//copiar string
	for (i = 0; i <= sizeStr; i++) {
		nstr[i] = str[i];
	}
	return nstr;
}

int main()
{
	char str2cpy[50];
	cout << "String? ";
	cin >> str2cpy;
	printf("Retornado de strcopy: %s", strcopy(str2cpy));
	
	return 0;
}

