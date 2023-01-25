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
		std::cout << "Destructor called for class CardActions" << std::endl;
	}
	//Вывод данных карты
	void GetNums();
	//Создание новой карты
	void EnterNew();	//21
	//Изменение старых данных карты
	void ChangeNumsFirst();
	void ChangeNumsSecond();
	//Удаление одной карты пользователя
	void RemoveCard();
	//Удаление всех карт пользователя
	void RemoveCards();
};