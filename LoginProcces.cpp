#include <iostream>
#include "LoginProcess.h"
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>

// ѕроводит регистрацию нового пользовател€ и запись его данных в файл
void LoginProcess::Registration() {

	string username, password;

	cout << "Select an username: "; cin >> username;
	cout << "Select a password: "; cin >> password;

	ofstream file;
	file.open("C:\\" + username + ".txt");
	//file.open("C:\Users\79296\\hello.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	file << username << endl << password;
	file.close();
	cout << "Successfully registered.\n " << endl;

}

// ќсуществл€ет вход уже зарегистрированного пользовател€
bool LoginProcess::IsLoggedIn() {

	string username, password, un, pw;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read("C:\\" + username + ".txt");
	//ifstream read("C:\Users\79296\\hello.txt");
	if (!read.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	getline(read, un);		// тут можно циклом сделать прочтение (while)
	getline(read, pw);

	read.close();
	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}