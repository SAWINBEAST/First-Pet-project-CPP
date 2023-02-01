#pragma once
#include <iostream>
#include <string>
using namespace std;

class CardActions {
private:

public:
	CardActions()
	{}
	~CardActions()
	{
		std::cout << "Thank's for using our services.\n" << std::endl; //
	}
	//Вывод данных карты
	void GetNums(const string&, string&);

	//Создание новой карты
	void EnterNew(const string&, const string& , string&);	//21

	//Изменение старых данных карты
	void ChangeNumsFirst(const string&, string&);
	void ChangeNumsSecond(const string&, const string&, string&);

	//Удаление одной карты пользователя
	void RemoveCard(string&, string&);

	//Удаление всех карт пользователя
	void RemoveCards(string&);
};