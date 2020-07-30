#include <stdio.h>

int main(int argc, char **argv)
{
	// Váriavel
	int num1;
	
	// Pedir inserção do número
	printf("Insira um numero inteiro: \n");
	scanf("%d", &num1);
	
	// Decidir e mostrar o número *2 ou /2
	if (num1 <10)
	{ 
	printf("%d", num1 * 2);
	}	
	else 
	{
		printf("%d", num1 / 2);
	}
// Pausa 
	getchar();	
}

