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
	void GetNums(const string& card_to_get);
	//Создание новой карты
	void EnterNew(const string& new_cardnums, const string& new_cardname);	//21
	//Изменение старых данных карты
	void ChangeNumsFirst(const string& change_cardname);
	void ChangeNumsSecond(const string& change_cardname, const string& change_cardnums);
	//Удаление одной карты пользователя
	void RemoveCard();
	//Удаление всех карт пользователя
	void RemoveCards();
};