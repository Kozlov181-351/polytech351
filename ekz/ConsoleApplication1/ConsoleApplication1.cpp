
#include "pch.h"
#include <iostream>
#include <openssl/conf.h> //функции,
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <fstream>
#pragma comment (lib, "libcrypto.lib")
using namespace std;

int main() // программка на зашифровку
{
	
	ifstream fileopen; // чистый который зашифровываем
	ofstream filecry;// в который скидываем зашифрованное
	fileopen.open("text.txt", std::fstream::in | std::fstream::binary); // открытие в бинарном виде для последующего шифра
	filecry.open("filecry.txt", std::fstream::out | std::fstream::binary); // открытие файла для последующей записи тож бинарка
	if (!fileopen) {
		std::cout << "ошибка открытия изначального файла" << std::endl;//Обработка ошибки открытия файла
	}
	if (!filecry) {
		std::cout << "ошибка открытия файла для шифровки" << std::endl;//Обработка ошибки открытия файла
	}
	unsigned char *key = (unsigned char *)"019283745"; //пароль (ключ)
	unsigned char *iv = (unsigned char *)"987654321054321"; //инициализирующий вектор
	char buffer[256] = { 0 }; // буфер для перегонки.
	char * out_buf[256] = { 0 }; // второй буфер для перегонки на выход. 
	unsigned int number_of_bytes = 0; // это то, сколько он уже перегнал.  
	int len = 0; //это длинна шифра
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new(); // 
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); //забиваем нашу структуру настроечками
	fileopen.read(buffer, 256); // оно считывает в буфер

	while (fileopen.gcount() > 0)//бесконечный цикл считывания порций файла, шифрования и
		//записи в другой файл или пока из файла что-то считывается пока размер считанной порции > 0 
	{
		//шифруем
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, fileopen.gcount()); //последний входной параметр: длина входных данных
		//запись порцайки в фаил
		filecry.write((const char *)out_buf, len); //записываем все в фаил 
		fileopen.read(buffer, 256); // оно считывает опять в буфер
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len); // финализация шифрования
	filecry.write((const char*)out_buf, len);// записали это в фаил
	filecry.close();
	fileopen.close();
	memset(buffer, 0, sizeof(char) * 256); 
	memset(out_buf, 0, sizeof(char) * 256);


}


