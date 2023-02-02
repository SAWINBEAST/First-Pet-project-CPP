#include "CardActions.h"
#include "ClientInterface.h"
#include "LoginProcess.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;


enum CHOICE {	//26
	GET_CARD = 1,
	ENTER_NEW,
	CHANGE_OLD,
	REMOVE_ONE,
	REMOVE_ALL,
	EXIT
};

int main() // Ниже присутствуют числа в комментах. Это ключи для поиска развёрнутого комментария в файле CommentsKeys.txt
{
	setlocale(LC_ALL, "Russian");

	// Регистрация и вход
	LoginProcess login;
	//string* currentUser = new string;	//34
	string* currentUser = new string ;

	unsigned short* choiceLog = new unsigned short;		//1
	*choiceLog = 0;
	cout << "1:Register\n2:Login\nYour choice: "; cin >> *choiceLog;
	if (typeid(*choiceLog) == typeid(unsigned short)) {	//38
		if (*choiceLog == 1)	//1
		{
			login.Registration();
			main();
		}

		else if (*choiceLog == 2)
		{
			unsigned char* status = new unsigned char;	//35
			*status = 1;		//2			
			*status = login.IsLoggedIn(currentUser);	//35


			if (*status == 2)
			{
				cout << "False Login! Try again. \n " << endl;

				delete status;
				status = nullptr;

				system("PAUSE");
				main();
			}

			else if (*status == 1)
			{
				cout << "Succesfully logged in! \n " << endl;
			}

			else
			{
				cout << "error on LogIn level" << endl;
			}

			delete status;
			status = nullptr;
		}

		else
		{
			cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;
			delete choiceLog;
			choiceLog = nullptr;
			main();
		}

		delete choiceLog;
		choiceLog = nullptr;
	}
	else
	{
		cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;
		delete choiceLog;
		choiceLog = nullptr;
		main();
	}
	

	// Выполнение задач КардХолдера 
	while (true)  //3 
	{
		ClientInterface first;
		first.ShowMenu();
		cout << "Your choice: ";	//4
		unsigned short* choice = new unsigned short;	//5    
		cin >> *choice;

		CardActions user;

		//Вывод данных карты 
		if (*choice == GET_CARD) {		//31
			system("cls");

			string* card_to_get = new string;		
			getline(cin, *card_to_get);	//6
			cout << "Nickname of card: ";
			getline(cin, *card_to_get);
			//7
			user.GetNums(*card_to_get, *currentUser);

			delete card_to_get;
			card_to_get = nullptr;
			system("pause");
		}

		//Создание новой карты
		else if (*choice == ENTER_NEW) {
			system("cls");

			string* new_cardnums = new string; //8
			string* new_cardname = new string;

			cout << "Card nums to add: ";
			cin >> *new_cardnums;	//9
			cout << "\nLet's come up with nickname of this card: ";
			cin >> *new_cardname;

			user.EnterNew(*new_cardnums, *new_cardname, *currentUser);

			delete new_cardnums;
			delete new_cardname;
			new_cardnums = nullptr;
			new_cardname = nullptr;
			system("pause");
		}

		//Изменение старых данных карты
		else if (*choice == CHANGE_OLD) {
			system("cls");

			string* change_cardname = new string;
			string* change_cardnums = new string;

			cout << "Which card would you like to edit?\nEnter the nickname of your card: ";
			cin >> *change_cardname;
			cout << "Enter new numbers for this card: ";
			cin >> *change_cardnums;

			user.ChangeNumsFirst(*change_cardname, *currentUser);	//27
			user.ChangeNumsSecond(*change_cardname, *change_cardnums, *currentUser);

			delete change_cardname;
			delete change_cardnums;
			change_cardname = nullptr;
			change_cardnums = nullptr;
			system("pause");
		}

		//Удаление одной карты пользователя
		else if (*choice == REMOVE_ONE) {
			system("cls");
			//10!
			string* file_name = new string;
			cout << "Which card would you like to remove?\nEnter the nickname of your card: ";
			cin >> *file_name;

			user.RemoveCard(*file_name, *currentUser);

			system("pause");
		}

		//Удаление всех карт пользователя
		else if (*choice == REMOVE_ALL) { //in progress
			system("cls");

			user.RemoveCards(*currentUser);
			//12
			system("pause");
		}

		//Выход из программы
		else if (*choice == EXIT) {
			system("cls");
			cout << " thats all for today. goodbye " << endl;
			break;	//28
			system("pause");
			
		}

		else
			cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;

		delete choice;
		choice = nullptr;
	}

	delete currentUser;
	currentUser = nullptr;

	return 168;
}