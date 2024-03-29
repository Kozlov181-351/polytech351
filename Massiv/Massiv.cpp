// Massiv.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	//массив - блок из нескольких однотипных танных
	//задвать массивом удобно
	//множество точек 3д и 2д геометрии
	//просто какой-то числовой ряд, таблица и т.д.
	//строка - массив символов
	//синтаксис объявления массива

	//	тип_данных имя_массива[size];
	//тип_данных имя_массива[size]={value for all};
	//тип_данных имя_массива[size]={value1, value2,...};

	int mass[5] = { 0 };

	//обращение ко всем элементам массива
	for (int i = 0; i < 5; i++)
	{
		mass[i] = i;
		std::cout << mass[i] << std::endl;
	}

	int matrix3x3[3][3] = { {1,2,3},
							{4,5,6},
							{7,8,9} };


	int matrix3x3No2[3][3] = { {4,2,3},
								{2,4,5},
								{3,5,4} };

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix3x3[i][j] << " ";

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//умножение двух матриц

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix3x3No2[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int massresult[3][3] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			massresult[i][j] = matrix3x3[i][j] * matrix3x3No2[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Как бы произведение матриц, но нет:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << massresult[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}

	int massresult2[3][3] = { 0 };
	std::cout << "Нормальное произведение матриц:\n";
	//истинное умножение матриц
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				massresult2[i][j] += matrix3x3[i][k] * matrix3x3No2[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << massresult2[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
	return 0;
}