#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>


using std::string;
using std::getline;


int exercicio2(string s, int n);


// declaraçao de variaveis globais 
string s;
int n;
int conta;
int A;

using namespace std;


int main()
{

	// Pede para introduzir a palavra e guarda na variavel s
	cout << "Introduza uma palavra:" << endl;
	cin >> s;
	// Pede para introduzir o tamanho que a variavel que introduziu na linha de cima vai ter 
	cout << "Introduza o numero de carateres:" << endl;
	cin >> n;
	// Chama a funçao
	exercicio2(s, n);


}

int exercicio2(string s, int n)
{
	// iguala a variavel conta á variavel s
	conta = s.length();

	// se os caracteres na variavel conta forem igual a 0 ou superior a 100 
	// se o numero que de caracteres que deseja for igual a 0 ou superior a 10 elevado a 12
	if (conta == 0 || conta > 100 || n == 0 || n > pow(10, 12))
	{
		printf("Tamanho introduzido invalido");
	}
	// senao enquanto conta for diferente de n 
	else
	{
		while (conta != n)
		{
			// duplica o conteudo da variavel
			s += s;
			conta = conta + conta;
			// enquanto conta for maior que n 
			while (conta > n)
			{
				// elimina o ultimo caracter da variavel ate ter os caracteres pretendidos
				s = s.erase(s.length() - 1);
				conta = conta - 1;
			}
			// se conta for igual a n
			if (conta == n)
			{
				int count = 0;

				// percorre o tamanho da variavel ja pretendido e conta quantos "a" tem
				for (int i = 0; i < s.size(); i++)
					// se encontrar 1 "a" count + 1;
					if (s[i] == 'a') count++;
				A = count;
			}

		}

		cout << "\nPalavra com o tamanho introduzido: " << s << endl;

		cout << "\nA palavra introduzida tinha " << A << " caracteres 'a'\n" << endl;
	}
	system("pause");

	return 0;
}