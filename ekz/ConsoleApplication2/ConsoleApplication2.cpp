// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <openssl/conf.h> //функции,
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <fstream>
#pragma comment (lib, "libcrypto.lib")
using namespace std;

int main()
{
	unsigned char *key = (unsigned char *)"019283745"; //пароль (ключ)
	unsigned char *iv = (unsigned char *)"987654321054321"; //инициализирующий вектор
	char buffer[256] = { 0 }; // буфер для перегонки.
	char * out_buf[256] = { 0 }; // второй буфер для перегонки на выход. 
	unsigned int number_of_bytes = 0; // это то, сколько он уже перегнал.  
	int len = 0; //это длинна шифра
	fstream filecry, filedecry;// файлы для шифра и дешифра

	filecry.open("filecry.txt", std::fstream::in | std::fstream::binary); // открываем их бинарными
	filedecry.open("filedecry.txt", std::fstream::out | std::fstream::binary);

	EVP_CIPHER_CTX *ctx; //объявляем ссылку на структуру с настройками
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	filecry.read(buffer, 256);
	while (filecry.gcount() > 0) // дешифровка до момента пока в файле не останется ничего
	{
		// расшифровка 
		EVP_DecryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, filecry.gcount());

		// запись расшифровки в файл 
		filedecry.write((const char *)out_buf, len);

		// чтение следующей порции 
		filecry.read(buffer, 256);
	}

	EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len); //финализация дешифрования
	filedecry.write((const char *)out_buf, len);

	filedecry.close();
	filecry.close();
}

