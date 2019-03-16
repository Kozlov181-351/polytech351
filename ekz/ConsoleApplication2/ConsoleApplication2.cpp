// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	fstream filecryingmore, whitebearcoming;// файлы для шифра и дешифра

	filecryingmore.open("filecry.txt", std::fstream::in | std::fstream::binary); // открываем их опять бинарными
	whitebearcoming.open("whitebearcoming.txt", std::fstream::out | std::fstream::binary);


	ctx = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	filecryingmore.read(buffer, 256);
	while (filecryingmore.gcount() > 0) // пошла вторая перегоночка из шифра и буквы
	{
		// расшифровка 
		EVP_DecryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, filecryingmore.gcount());

		// запись расшифровки в файл 
		whitebearcoming.write((const char *)out_buf, len);

		// чтение следующей порции 
		filecryingmore.read(buffer, 256);
	}

	EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len); //если в первый раз у нас была шлифовка пивком, то тут получается зачистка пивком? надо подумать
	whitebearcoming.write((const char *)out_buf, len);

	whitebearcoming.close();
	filecryingmore.close();
}

