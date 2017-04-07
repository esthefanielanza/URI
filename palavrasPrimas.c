#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificaPrimo(int p){

	int i;
	double j;
	
	//Calcula a raiz quadrada para p
	j = sqrt(p);


	for(i = 2; i <= j; i++){
		//Retorna 0 caso não seja um número primo
		if(p%i == 0)
			return 0;
	}

	//Retorna 1 quando é um número primo
	return 1;
}

void transformaString(char *string, int *inteiros){

	int i;

	for(i = 0; i < 20; i++){
		
		if(string[i] > 96)
			inteiros[i] = string[i] - 96;

		else if(string[i] > 64)
			inteiros[i] = string[i] - 38;

		else
			inteiros[i] = -1;
	}
}

int main(void){

	char string[20];
	int inteiros[20];

	int soma, i;

	for(i = 0; i < 20; i++)
		string[i] = -1;	

	while(scanf("%s", string) != EOF){
		
		soma = 0;
		
		transformaString(string, inteiros);
		
		for(i = 0; i < 20; i++){
			if(inteiros[i] != -1)
				soma += inteiros[i];
		}

		if(verificaPrimo(soma))
			printf("It is a prime word.\n");

		else
			printf("It is not a prime word.\n");

		for(i = 0; i < 20; i++)
			string[i] = -1;
	}

	return 0;
}