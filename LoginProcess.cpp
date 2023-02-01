#include "LoginProcess.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <direct.h>

// Проводит регистрацию нового пользователя и запись его данных в файл
void LoginProcess::Registration() {

	string* username = new string;
	string* password = new string;

	cout << "Select an username: "; cin >> *username;
	cout << "Select a password: "; cin >> *password;

	ofstream file;
	file.open("C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + *username + ".txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	file << *username << endl << *password;
	file.close();
	cout << "New account successfully registered.\n " << endl;

	//Создание индивидуальной папки для клиента
	const string path_s = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + *username + "";
	try {
		string path = path_s;
		//33
		_mkdir(path.c_str()); //34
		cout << "Personal directory - cardholder has been created.\n" << endl;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
		cout << "Ooops. Something went wrong on the \"directory-create\" level.";
	}

	delete username;
	delete password;
	username = nullptr;
	password = nullptr;
}


// Осуществляет вход уже зарегистрированного пользователя
int LoginProcess::IsLoggedIn(string* currentUser) {

	string* username = new string;
	string* password = new string;
	string* un = new string;
	string* pw = new string;

	//string  un, pw;

	cout << "Enter username: "; cin >> *username;
	cout << "Enter password: "; cin >> *password;

	ifstream read("C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + *username + ".txt");
	if (!read.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	getline(read, *un);		// тут можно циклом сделать прочтение (while)
	getline(read, *pw);
	read.close();

	if (*un == *username && *pw == *password)
	{
		*currentUser = *username;
		delete un, pw, username, password;
		username = nullptr;
		password = nullptr;
		un = nullptr;
		pw = nullptr;
		return 1;
	}
	else
	{
		delete un, pw, username, password;
		username = nullptr;
		password = nullptr;
		un = nullptr;
		pw = nullptr;
		return 2;
	}

}