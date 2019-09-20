#include <stdio.h>

void imprime_vetor(const int* vetor, const size_t tamanho);
void imprime_vetor2(const int* vetor, size_t tamanho);
void imprime_vetor3(const int* vetor, const size_t tamanho);
void imprime_vetor4(const int* vetor, size_t tamanho);

int main()
{
	int vetor[] = { 0, 1, 2, 3, 4, 5 };

	imprime_vetor(vetor, sizeof(vetor) / 4);
	imprime_vetor2(vetor, sizeof(vetor) / 4);
	imprime_vetor3(vetor, sizeof(vetor) / 4);
	imprime_vetor4(vetor, sizeof(vetor) / 4);
}

/* versão array-like */
void imprime_vetor(const int* vetor, const size_t tamanho)
{
	unsigned int i;

	for (i = 0; i < tamanho; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

/* versão para quem gosta de ponteiros ;)*/
void imprime_vetor2(const int* vetor, size_t tamanho)
{
	while (tamanho--) {
		printf("%d ", *vetor++);
	}
	printf("\n");
}

//// -----------

/* versão array-like */
void imprime_vetor3(const int* vetor, const size_t tamanho)
{
	unsigned int i;

	for (i = 0; i < tamanho; i++) {	
		printf("%d%c", vetor[i], (i == tamanho-1)[" \n"]);
	}
}

/* versão para quem gosta de ponteiros ;)*/
void imprime_vetor4(const int* vetor, size_t tamanho)
{
	while (tamanho--) {
		printf("%d%c", *vetor++, ((tamanho==0)[" \n"]));
	}
}
