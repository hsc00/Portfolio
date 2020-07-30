#include <stdio.h>

int main(int argc, char **argv)
{
	// Variável 
	float numero;
	
	// Pedir inserção do número
	printf("Insira um numero:  ");
	scanf("%f", &numero);
	
	// Mostrar número escolhido
	printf("O numero inserido e': %.0f", numero);
	
	// Pausa 
	getchar();	
}

