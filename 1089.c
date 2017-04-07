#include <stdio.h>

int main(void){

	int nAmostras, primeiraNota, nota, notaAnterior, primeiroMaiorMenor, menorMaior = -1, i, picos = 0;
	
	scanf("%d", &nAmostras);

	while(nAmostras != 0){

		for(i = 0; i < nAmostras + 1; i++){

			if(i != nAmostras)
				scanf("%d", &nota);

			else
				nota = primeiraNota;

			if(i == 0)
				primeiraNota = nota;
			
			else{
				//printf("Comparou \n");
				if(notaAnterior < nota){
						
					if(menorMaior == 0)
						picos++;

					else if(menorMaior == -1)
						primeiroMaiorMenor = 1;

					menorMaior = 1;
				}

				else{

					if(menorMaior == 1)
						picos++;

					else if(menorMaior == -1)
						primeiroMaiorMenor = 0;

					menorMaior = 0;
				}
			}

			if(i == nAmostras){

				if(menorMaior != primeiroMaiorMenor)
					picos++;
			}


			notaAnterior = nota;
		}

		printf("%d\n", picos);
		picos = 0;
		menorMaior = -1;
		scanf("%d", &nAmostras);
	}

	return 0;
}