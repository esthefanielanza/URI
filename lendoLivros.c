#include <stdio.h>
#include <stdlib.h>

int main(void){

	int qPaginasDia, diasAdiantados, qPaginasDiaDepois, paginasLivro;

	while(1){

		scanf("%d", &qPaginasDia);

		if(qPaginasDia == 0)
			break;

		scanf("%d %d", &diasAdiantados, &qPaginasDiaDepois);

		diasAdiantados = diasAdiantados * qPaginasDiaDepois * qPaginasDia;

		paginasLivro = diasAdiantados / (qPaginasDiaDepois - qPaginasDia);

		printf("%d paginas\n", paginasLivro);
	}

	return 0;
}