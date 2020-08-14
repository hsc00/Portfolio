#include <stdio.h>

int main(int argc, char **argv)
{
	// Variáveis
    int num, max, min;
	// Pedir numeros
    printf ("Introduza 5 numeros: ");
    scanf ("%d", &num);
    max = min = num;
	// 'Organizar' e decidir
    for (int i = 0; i < 4; i++)
    { 
        scanf ("%d", &num);
        if (max < num)
            max = num;
        else if (min > num)
            min = num;
    }
	// Imprimir mais baixo e mais alto
    printf ("Os numeros mais baixo e mais alto sao %d e %d respectivamente.\n", min,  max);
// Pausa 
	getchar();
	
}

