#include <stdio.h>

int main(int argc, char **argv)
{
	 // Variáveis 
    float num1, num2, media;
   
    // Pedir inserção dos números
    printf ("Insira o primeiro valor: ");
    scanf ("%f", &num1);
    
    printf ("Insira o segundo valor: "); 
    scanf ("%f", &num2); 
    
    // Efectuar a divisão
    media = (num1 + num2) / 2;
    
    // Mostrar a média
    printf("=> A sua media e de: %.0f", media);
    
    // Pausa
    getchar();	
}

