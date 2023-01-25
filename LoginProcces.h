#pragma once
#include <iostream>
#include <string>
using namespace std;

//Процессы входа и регистрации
class LoginProcess {
private:

public:
	LoginProcess()
	{}
	~LoginProcess()
	{}
	// Проводит регистрацию нового пользователя и запись его данных в файл
	void Registration();
	// Осуществляет вход уже зарегистрированного пользователя
	bool IsLoggedIn();

}; 
