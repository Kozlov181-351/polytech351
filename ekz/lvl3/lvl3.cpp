// lvl3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <string> 
	using namespace std;
	int main()
	{
		string word;
		cin >> word;
		string temp;
		char t = word[0];
		int count = 1;
		for (int i = 1; i < word.length(); i++)
		{
			if (word[i] == t)
			{
				count++;
			}
			else {
				if (count == 1) {
					temp += t;
					t = word[i];
				}
				else
				{
					temp += to_string(count);
					temp += t;
					t = word[i];
					count = 1;
				}
			}
			if (i == word.length() - 1)
			{
				if (count == 1) {
					temp += t;
					t = word[i];
				}
				else
				{
					temp += to_string(count);
					temp += t;
					t = word[i];
					count = 1;
				}
			}
		}
		cout << temp;
	}

