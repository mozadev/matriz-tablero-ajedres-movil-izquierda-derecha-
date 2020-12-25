#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
using namespace System;

#define N 20
#define M 20
using namespace std;
using namespace System;


int Mapa1[N][M] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

};

void AsignarMatriz(int *Nivel, int **Matriz)
{
	if (*Nivel == 1)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Matriz[i][j] = Mapa1[i][j];
	
}
void MuestraMapa(int **Matriz)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			Console::SetCursorPosition(j, i);
			Console::BackgroundColor = ConsoleColor::White;
			if (Matriz[i][j] == 0)
				cout << " ";
			if (Matriz[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Black;
				cout << char(219);
			}
		}
}
void Juego(int **Matriz)
{
	int X = 5, Y = 4;
	char Tecla;
	Console::SetCursorPosition(X, Y);
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::White;
	cout << "+";
	bool direccion = true;
	int j = 7;
	while (1)
	{
		while (!_kbhit())
		{

			Console::SetCursorPosition(j, 6);
			cout << char(215);
			Sleep(300);
			Console::SetCursorPosition(j, 6);
			cout << " ";
			if (direccion == true)
				j++;
			else
				j--;
			if (Matriz[6][j] == 3)
				direccion = false;
			if (Matriz[6][j] == 2)
				direccion = true;

		}
		Tecla = _getch();
		Console::SetCursorPosition(X, Y);
		cout << " ";
		if (Tecla == 72) //arriba
		{
			Y--;
			if (Matriz[Y][X] == 1)
				Y++;
		}
		if (Tecla == 80) //abajo
		{
			Y++;
			if (Matriz[Y][X] == 1)
				Y--;
		}
		if (Tecla == 75) // izquierda
		{
			X--;
			if (Matriz[Y][X] == 1)
				X++;
		}
		if (Tecla == 77) //derecha
		{
			X++;
			if (Matriz[Y][X] == 1)
				X--;
		}
		if (X == 8 && Y == 8)//puerta al siguiente nivel
			break;
		Console::SetCursorPosition(X, Y);
		cout << "+";

	}
}
int main()
{
	int **Matriz;
	int Nivel;
	Matriz = new int *[N];
	for (int i = 0; i < N; i++)
		Matriz[i] = new int[M];

	Nivel = 1;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(Matriz);

	Nivel = 2;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(Matriz);
	_getch;
}