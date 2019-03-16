// lvl4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
	using namespace std;
	int funt(int n)
	{
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		if (n >= 2 && n % 2 == 0) {
			return funt(n / 2);
		}
		if (n >= 2 && n % 2 == 1) {
			return funt(n / 2) + funt(n / 2 + 1);
		}
	};
	int main()
{
		int n;
		cin >> n;
		cout << funt(n);
}

