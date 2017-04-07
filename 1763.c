#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ALFABETO 27
#define PRIMEIRA_LETRA_ASCII 'a'
#define PALAVRA_MAX 20

//Estrutura para nós da árvore// 
typedef struct TNode{ 

	//Cada nó aponta para um número n de filhos, onde n é o tamanho do alfabeto//
	struct TNode *filhos[TAMANHO_ALFABETO];

	//Indica o fim de uma palavra, 0 para não é fim e 1 para é fim//
	int finalPalavra; 

	int pais;

} TNode;

TNode *criaNode(void){

	int i;

	TNode *newNode;

	//Aloca espaço para o novo nó//
	newNode = (TNode*) malloc(sizeof(TNode));
	if(!newNode) { perror(NULL); exit(EXIT_FAILURE); }

	//Inicializa a variável do struct final como zero, quando em 1 representa o fim de uma palavra//
	newNode->finalPalavra = 0;
	newNode->pais = 0;

	//Inicializa todos os filhos do nó, correspondentes a tamanho do alfabeto, como NULL//
	for(i = 0; i < TAMANHO_ALFABETO; i++)
		newNode->filhos[i] = NULL;
	
	return newNode;
}

TNode *criaTrie(void){

	//Cria um nó para a raiz
	return criaNode();
}

void inserePalavra(TNode *node, char *palavra, int *pais){

	int i;
	int tamanhoPalavra, indiceLetra;
	
	//Calcula o tamanho da palavra lida//
	tamanhoPalavra = strlen(palavra);
	
	//Enquanto não chegar ao fim da palavra//
	for(i = 0; i < tamanhoPalavra; i++){

		//Calculamos o indice correspondente a letra//
		if(palavra[i] != '-')
			indiceLetra = (int)palavra[i] - PRIMEIRA_LETRA_ASCII;
		else
			indiceLetra = 26;

		//Se não existe um nó para o caractere correspondente, criamos o nó//
		if(node->filhos[indiceLetra] == NULL)
			node->filhos[indiceLetra] = criaNode();

		//Caminhamos para o nó criado//
		node = node->filhos[indiceLetra];
	}

	//Indicamos que é o final de uma palavra//
	node->finalPalavra = 1;
	node->pais = *pais;
	*pais = *pais + 1;
}

int procuraPalavra(TNode *node, char *palavra, int *paisAtual){

	int i;
	int tamanhoPalavra, indiceLetra;

	tamanhoPalavra = strlen(palavra);

	for(i = 0; i < tamanhoPalavra; i++){

		if(palavra[i] != '-')
			indiceLetra = (int)palavra[i] - PRIMEIRA_LETRA_ASCII;
		else
			indiceLetra = 26;
		
		//Se ainda não existe um nó criado para determinado indice, retornamos pois a palavra não foi encontrada//
		if(node->filhos[indiceLetra] == NULL){
			return 0;
		}	

		//Caminhamos para o próximo nó//
		node = node->filhos[indiceLetra];
	}

	if(node->finalPalavra){
		*paisAtual = node->pais;
		return 1;
	}

	return 0;
}

int main(void){

	TNode *raiz;

	int pais = 0, paisAtual;
	char paises[30];
	char felizNatal[30][30] = {"Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!", "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", 
	"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
	"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu"};

	raiz = criaTrie();

	inserePalavra(raiz, "brasil", &pais);
	inserePalavra(raiz, "alemanha", &pais); 
	inserePalavra(raiz, "austria", &pais); 
	inserePalavra(raiz, "coreia", &pais); 
	inserePalavra(raiz, "espanha", &pais); 
	inserePalavra(raiz, "grecia", &pais); 
	inserePalavra(raiz, "estados-unidos", &pais); 
	inserePalavra(raiz, "inglaterra", &pais); 
	inserePalavra(raiz, "australia", &pais);
	inserePalavra(raiz, "portugal", &pais);
	inserePalavra(raiz, "suecia", &pais);
	inserePalavra(raiz, "turquia", &pais);
	inserePalavra(raiz, "argentina", &pais);
	inserePalavra(raiz, "chile", &pais);
	inserePalavra(raiz, "mexico", &pais);
	inserePalavra(raiz, "antardida", &pais);
	inserePalavra(raiz, "canada", &pais);
	inserePalavra(raiz, "irlanda", &pais);
	inserePalavra(raiz, "belgica", &pais);
	inserePalavra(raiz, "italia", &pais);
	inserePalavra(raiz, "libia",  &pais);
	inserePalavra(raiz, "siria", &pais);
	inserePalavra(raiz, "marrocos", &pais);
	inserePalavra(raiz, "japao", &pais);

	while(scanf("%s", paises) > EOF){
		if(procuraPalavra(raiz, paises, &paisAtual))
			printf("%s\n", felizNatal[paisAtual]);
		else
			printf("--- NOT FOUND ---\n");
	}
	

	return 1;
}