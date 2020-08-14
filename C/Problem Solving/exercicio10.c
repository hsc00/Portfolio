#include <stdio.h>

int main(int argc, char **argv)
{
	//Declarar Variáveis
	
	int opcaoEscolhida;
	double salarioFinal;
	float salario;
	// Pedir salário
	printf("Insira o seu salario: ");
	scanf("%f", &salario);
	puts("");
	// Pedir facturação 1, 2 ou 3.
	puts("Quanto facturou em vendas este mes:");
	puts("");
	puts("        > 1 - Menos de 10.000 euros");
	puts("        > 2 - Entre 10.000 euros e 20.000 euros");
	puts("        > 3 - Mais de 20.000 Euros");
	puts("");
	printf("              Opcao: ");
	scanf("%d", &opcaoEscolhida);

	// Decidir e calcular salário
switch(opcaoEscolhida)
	{
case 1:
	salarioFinal = (salario * 1);
	printf("\n");
	printf("========== resultado ==========\n");
	printf("O seu salario este mes e de: %6.2f euros.", salarioFinal);
	break;
case 2:
	salarioFinal = (salario * 1.1);
	printf("\n");
	printf("========== resultado ==========\n");
	printf("O seu salario este mes e de: %6.2f euros.", salarioFinal);
	break;
case 3:
	salarioFinal = (salario * 1.2);
	printf("\n");
	printf("========== resultado ==========\n");
	printf("O seu salario este mes e de: %6.2f euros.", salarioFinal);
	break;
}
// Pausa 
	getchar();
	
}

