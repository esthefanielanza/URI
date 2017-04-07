#include <stdlib.h>
#include <stdio.h>

long long int fatorial(long long int n){

	long int i, resultado = 1; 

	for(i = 1; i <= n; i++){
		resultado *= i;
	}

	return resultado;
}

int main(void){
	
	long long int n, m, nFatorial, mFatorial;

	while(scanf("%lld %lld", &n, &m) != EOF){

		nFatorial = fatorial(n);
		mFatorial = fatorial(m);

		printf("%lld", nFatorial + mFatorial);
	}

	return 0;	
}