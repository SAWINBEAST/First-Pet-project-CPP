#pragma once
#include <iostream>
#include <string>
using namespace std;

// Шаблон Класса 
/* Шаблон Класса

template <typename T, typename V>

class Transaction
{
public:

	Transaction(T fromAcc, T toAcc, V code, int sum):
		fromAccount(fromAcc), toAccount(toAcc), code(code), sum(sum)		// Прямая Инициализация - тут
	{ 
	 name = autoName; 
        price = autoPrice;		// Присвоение - это
	}

	~Transaction()
	{}

	// Геттеры :



	// Сеттеры :



	// Методы :



private:

	// Поля :

	T fromAccount;  // с какого счета
	T toAccount;    // на какой счет
	V code;         // код операции
	int sum;        // сумма перевода

protected:


};

*/



class General_Functions {
private:

public:
	void show_menu();
	void registration();
	bool IsLoggedIn();


	General_Functions()
	{}
	~General_Functions()
	{}

protected:

};

class CardNumActions {
private:
	string cardnums;
	string cardname;

public:
	void enter_new();		//(int cardnums, string cardname );

	
	
	CardNumActions(string new_cardnums, string new_cardname)		// : cardnums(new_cardnums), card_name(new_cardname) // Инициализация почему-то не работает. Нужно присваивать в теле конструктора
	{
	cardnums = new_cardnums;
	cardname = new_cardname;
	}
	
	~CardNumActions() {
		std::cout << "Destructor called for CardNumActions " <<  std::endl;
	}
	
	/*
	CardNumActions()
	{}
	~CardNumActions() 
	{}
	*/

};

class ChangeCardNums {
private:
	string change_name;
	string changing_nums;
public:
	ChangeCardNums(string change_cardname, string change_cardnums)		//:change_name(change_cardname), change_nums(change_cardnums) 
	{
		change_name = change_cardname;
		changing_nums = change_cardnums;
	}

	~ChangeCardNums()
	{}

	void change_nums();
	void change_nums_seclev();


protected:

};

class GetCardNums {
private:
	string received_card;
public:
	GetCardNums(string card_to_get)
	{
		received_card = card_to_get;
	}

	void get_nums();
};

class RemoveOneCard {
private:
	//string removable_card;
	//char removable_card[];
public:
	RemoveOneCard()	//(string removable_cardname)
	{
		//removable_card = removable_cardname;
	}

	void removecard();

protected:

};

class RemoveAllCards : public RemoveOneCard {

public:
	RemoveAllCards() :RemoveOneCard()
	{

	}

	void removecards();
};





/*
CardNumActions::CardNumActions(int new_cardnums, string new_cardname)
{
	cardnums = new_cardnums;
	cardname = new_cardname;
}
*/
