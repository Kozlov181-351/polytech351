// lvl4v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std; 

int func(int dd)
{
	if (dd == 1)
	{
		return 1;
	}
	else if (dd == 0)
	{
		return 0;
	}
	else if (dd >= 2 && dd % 2 == 0) {
		return func(dd / 2);
	}
	else if (dd >= 2 && dd % 2 == 1) {
		return func((dd - 1) / 2) + func((dd - 1 / 2) + 1);
	}
};
int main()
{
	int n;
	cin >> n;
	cout << func(n);
};

	
