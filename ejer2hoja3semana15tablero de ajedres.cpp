#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

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
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
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
int Mapa2[N][M] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 2, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 2, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
void AsignarMatriz(int *Nivel, int **Matriz)
{
	if (*Nivel == 1)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Matriz[i][j] = Mapa1[i][j];
	if (*Nivel == 2)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Matriz[i][j] = Mapa2[i][j];
	//if (*Nivel == 2)
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
			if (Matriz[i][j] == 2)
			{
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << "*";
			}

			if (Matriz[i][j] == 3)
			{
				Console::ForegroundColor = ConsoleColor::Magenta;
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
	int j = 1;
	int i = 1;
	while (1)
	{

		while (!_kbhit() && j<9)
		{
			
			Console::SetCursorPosition(j+5,6);
			cout << char(215);
			Sleep(300);
			Console::SetCursorPosition(j+5, 6);
			cout << " ";
			j++;
			
			
			
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
		if (X == 8 && Y == 8)
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