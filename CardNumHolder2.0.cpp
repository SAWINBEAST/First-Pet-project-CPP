#include "CardActions.h"
#include "ClientInterface.h"
#include "LoginProcess.h"

#include <iostream>
#include <stdio.h>
#include <istream>
#include <string>

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
	// Регистрация и вход
	LoginProcess login;
	int choice1 = 0;		//1
	cout << "1:Register\n2:Login\nYour choice: "; cin >> choice1;
	if (choice1 == 1)	//1
	{
		login.Registration();
		main();
	}

	else if (choice1 == 2)
	{
		bool status = false;	//2			
		status = login.IsLoggedIn();

		if (status == 0)
		{
			cout << "False Login! Try again. \n " << endl;
			system("PAUSE");
			main();
		}

		else
		{
			cout << "Succesfully logged in! \n " << endl;
		}

	}

	else
	{
		cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;
		main();
	}


	// Выполнение задач КардХолдера 
	while (true)  //3 
	{
		ClientInterface first;
		first.ShowMenu();
		cout << "Your choice: ";	//4
		int choice;     //5
		cin >> choice;

		CardActions user;

		//Вывод данных карты 
		if (choice == GET_CARD) {
			system("cls");

			string card_to_get;
			getline(cin, card_to_get);	//6
			cout << "Nickname of card: ";
			getline(cin, card_to_get);
			//7
			user.GetNums(card_to_get);

			system("pause");
		}

		//Создание новой карты
		else if (choice == ENTER_NEW) {
			system("cls");

			string new_cardnums; //8
			string new_cardname;

			cout << "Card nums to add: ";
			cin >> new_cardnums;	//9
			cout << "\nLet's come up with nickname of this card: ";
			cin >> new_cardname;

			user.EnterNew(new_cardnums, new_cardname);

			system("pause");
		}

		//Изменение старых данных карты
		else if (choice == CHANGE_OLD) {
			system("cls");

			string change_cardname;
			string change_cardnums;

			cout << "Which card would you like to edit?\nEnter the nickname of your card: ";
			cin >> change_cardname;
			cout << "Enter new numbers for this card: ";
			cin >> change_cardnums;

			user.ChangeNumsFirst(change_cardname);	//27
			user.ChangeNumsSecond(change_cardname, change_cardnums);

			system("pause");
		}

		//Удаление одной карты пользователя
		else if (choice == REMOVE_ONE) {
			system("cls");
			//10!
			user.RemoveCard();

			system("pause");
		}

		//Удаление всех карт пользователя
		else if (choice == REMOVE_ALL) { //in progress
			system("cls");

			user.RemoveCards();
			//12
			system("pause");
		}

		//Выход из программы
		else if (choice == EXIT) {
			system("cls");
			cout << " thats all for today. goodbye " << endl;
			//28
			system("pause");
			break;
		}

		else
			cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;

	}

	return 168;
}