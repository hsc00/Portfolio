#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
enum OpcoesMenu { OMP_Sair = 27 };
char op;
int linhas = 0;
string op1;
string sLine;
bool aux;
string dif;

void MenuDificuldade();
void Iniciante();
void VerdadeiroFalso();
void Perguntas();
void Amador();
void Mediano();
void Dificil();
void Extremo();


void MenuPrincipal()
{
	while (op != OMP_Sair)
	{
		system("cls");
		cout << "**********************************************************" << endl;
		cout << "1 - Iniciar jogo" << endl;
		cout << "ESC - Sair" << endl;
		cout << "**********************************************************" << endl;
		op = (OpcoesMenu)_getch();

		switch (op)
		{
		case '1':
			MenuDificuldade();
			break;
		case OMP_Sair:
			cout << "Obrigado por jogar o Quem Quer Ser Milionario!!" << endl;
			Sleep(4000);
			exit(0);
			break;
		}
	}
}

void MenuDificuldade()
{

		system("cls");

		cout << "**********************************************************" << endl;
		cout << "1 - Nivel de dificuldade: Iniciante " << endl;
		cout << "2 - Nivel de dificuldade: Amador " << endl;
		cout << "3 - Nivel de dificuldade: Mediano " << endl;
		cout << "4 - Nivel de dificuldade: Dificil " << endl;
		cout << "5 - Nivel de dificuldade: Extremo " << endl;
		cout << "V - Voltar ao Menu Inicial" << endl;
		cout << "**********************************************************" << endl;
		cin >> op;

		switch (op)
		{
		case '1':
			Iniciante();
			break;
		case '2':
			Amador();
			break;
		case '3':
			Mediano();
			break;
		case '4':
			Dificil();
			break;
		case '5':
			Extremo();
			break;
		case 'V':
		case 'v':
			system("cls");
			MenuPrincipal();
			break;
		}

	}

void Iniciante()
{
	system("cls");
	dif = "iniciante.txt";
	Perguntas();
}
void Amador()
{
	system("cls");
	dif = "amador.txt";
	Perguntas();
}
void Mediano()
{
	system("cls");
	dif = "mediano.txt";
	Perguntas();
}
void Dificil()
{
	system("cls");
	dif = "dificil.txt";
	Perguntas();
}
void Extremo()
{
	system("cls");
	dif = "extremo.txt";
	Perguntas();
}

void Perguntas()
{
	ifstream ficheiro(dif);
	if (ficheiro.good())
	{

		linhas = 0;

		while (linhas < 50)
		{

			if (linhas == 5)
			{
				getline(ficheiro, sLine);
				VerdadeiroFalso();
				if (aux == false)
				{
					system("cls");
					MenuDificuldade();
				}


			}

			if (linhas == 10)
			{
				getline(ficheiro, sLine);
				VerdadeiroFalso();
				if (aux == false)
				{
					system("cls");
					MenuDificuldade();
				}
			}

			if (linhas == 15)
			{
				getline(ficheiro, sLine);
				VerdadeiroFalso();
				if (aux == true)
				{
					cout << "Terminou este nivel de dificuldade. Parabens!" << endl;
					Sleep(3000);
				}
				MenuDificuldade();
			}

			getline(ficheiro, sLine);
			cout << sLine << endl;
			linhas++;

		}

		ficheiro.close();

	}
}


void VerdadeiroFalso()
{
	cin >> op1;

	if (sLine == op1)
	{
		aux = true;
		cout << "A sua resposta esta certa!!" << endl;
		Sleep(3000);
		system("cls");
	}
	else
	{
		aux = false;
		cout << "A sua resposta esta errada!!" << endl;
		Sleep(3000);
	}
}

int main()
{
	MenuPrincipal();
}