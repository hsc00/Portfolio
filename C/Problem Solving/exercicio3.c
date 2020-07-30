#include <stdio.h>

int main(int argc, char **argv)
{
	//Variáveis
    int num1, num2, sum, sub, mult, div, res;
	// Pedir inserção dos números
    printf("Digite o primeiro numero: " );
    scanf("%d", &num1);

    printf("Digite o segundo numero: " );
    scanf("%d", &num2);

    //Soma
    sum = num1 + num2;

    //Subtração
    sub = num1 - num2;

    //Multiplicaçao
    mult = num1 * num2;

    //Divisão
    div = num1/num2;
    
    //Resto
    res = (num1 % num2);

	//Mostrar resultados
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d * %d = %d\n", num1, num2, mult);
    printf("%d / %d = %d\n", num1, num2, div);
    printf("%d / %d tem resto = %d\n", num1, num2, res);
// Pausa 
	getchar();	
}

