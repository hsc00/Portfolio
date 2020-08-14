#include <stdio.h>

int main(int argc, char **argv)
{
	// Variáveis 
	float teste1, comportamento, notaTrabalho, notaFinal;
	
	// Pedir inserção do valor do teste1
	printf("Insira o valor do teste1:  ");
	scanf("%f", &teste1);
	
	// Pedir inserção do valor do comportamento
	
	printf("Insira o valor do comportamento:  ");
	scanf("%f", &comportamento);
	
	// Pedir inserção do valor do notaTrabalho
	
	printf("Insira o valor do notaTrabalho:  ");
	scanf("%f", ¬aTrabalho);

	
	// Calcular a nota final
	notaFinal=(0.6 * teste1) + (0.2 * comportamento) + (0.2 * notaTrabalho);
	
	// Mostrar a nota final no ecrã
	
	printf("A nota final e %.2f", notaFinal);
	
	// Pausa 
	getchar();	
}

