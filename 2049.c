#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BMH(char *p, int n, char *t, int m){

	int i, j, k;
	int d[10];

	for(i = 0; i < 10; i++) d[i] = n;
	//for(i = 0; i < 10; i++) printf("d[%d] = %d\n", i, d[i]);

	for(i = 0; i < n - 1; i++) d[(int)p[i] - 48] = n - i - 1;
	//for(i = 0; i < 10; i++) printf("d[%d] = %d\n", i, d[i]);

	i = n;

	while( i <= m ){
		//printf("nha\n"); 
		j = i;
		k = n;

		//printf("Comparando t[%c] = p[%c]\n", t[j-1], p[k-1]);
		while(t[j - 1] == p[k - 1] && k > 0) { j--; k--;}
		
		if(k == 0){
			//printf("Achou !\n");
			return 1;
		}

		//printf("Deslocando[%d] = %d\n", t[i] - 48, d[(int)t[i] - 48]);
		i += d[(int)t[i - 1] - 48];
	}

	return 0;
}

int main(void){

	int n, m, achou = 0, instancia = 1;
	char p[8], t[300001];

	scanf("%s[^\n]\n", p);
	n = strlen(p);
	//printf("Tamanho padrão: %d\n", n);

	while(p[0] != '0' || n != 1){
		
		scanf("%s[^\n]\n", t);
		m = strlen(t);
		
		if(instancia > 1)
			printf("\n");

		//printf("Tamanho texto: %d\n", m);

		printf("Instancia %d\n", instancia);

		achou = BMH(p, n, t, m);

		if(achou)
			printf("verdadeira\n");
		else
			printf("falsa\n");

		instancia++;

		scanf("%s[^\n]\n", p);
		n = strlen(p);

	}

	return 0;
}