#include <stdio.h>
#include <stdlib.h>
void leNumero(int *a){

	char x[6];
	
	int i;

	for(i = 0; i < 6; i++)
		x[i] = -1;

	scanf("%s", x);

	for(i = 0; i < 6; i++){

		if(x[i] > 64)
			a[5 - i] = x[i] - 55;

		else if(x[i] > 30)
			a[5 - i] = x[i] - 48;

		else
			a[5 - i] = -1;

	}
}

int verificaZeros(int *a, int *b){
	if(a[5] == 0 && b[5] == 0){
		if(a[4] == -1 && b[4] == -1){
			return 0;
		}
	}

	return 1;
}


int main(){

	int a[6], b[6], soma[6];
	int i, j, vaiUm, verifica;

	int aCount, bCount;

	char final[6];

	leNumero(a);
	leNumero(b);

	verifica = verificaZeros(a, b);

	while(verifica){

		aCount = 0; bCount = 0;

		vaiUm = 0;

		while(a[aCount] == -1)
			aCount++;

		while(b[bCount] == -1)
			bCount++;

		for(i = 0; i < 6; i++)
			soma[i] = -1;

		j = 5;

		while(aCount < 6 || bCount < 6){

			if(aCount != 6 && bCount != 6){
				soma[j] = a[aCount] + b[bCount] + vaiUm;
				vaiUm = 0;
				aCount++;
				bCount++;
			}

			else if(aCount == 6 && bCount != 6){
				soma[j] = b[bCount] + vaiUm;
				vaiUm = 0;
				bCount++;
			}

			else if(aCount != 6 && bCount == 6){
				soma[j] = a[aCount] + vaiUm;
				vaiUm = 0;
				aCount++;
			}

			while(soma[j] > 35){
				soma[j] -= 36;
				vaiUm++;
			}

			j--;
		}

		if(vaiUm != 0){
			soma[j] = vaiUm;
			vaiUm = 0;
		}

		for(i = 0; i < 6; i++){
			if(soma[i] != -1){
				
				if(soma[i] > 9)
					final[i] = soma[i] + 55;

				else
					final[i] = soma[i] + 48;

				printf("%c", final[i]);
			}
		}

		printf("\n");


		leNumero(a);
		leNumero(b);

		verifica = verificaZeros(a, b);
	}

	return 0;
}