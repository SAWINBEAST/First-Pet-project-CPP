#include "Header.h"
#include <iostream>
#include <stdio.h>
#include <istream>
#include <string>
using namespace std;

// Крайние нерешённые задачи:
// - не могу удалить все карты (найти) в REMOVE_ALL
// - я специально поменял int на string в переменных данных карт.( enter_new() , chang_nums_seclev() )
//...


// Нужно добавить больше:
// - SOLID принципов (например, сделать для каждой задачи свой личный класс)
// - Динамической памяти (+чистки)				// https://www.bestprog.net/ru/2018/09/25/dynamic-and-static-allocation-of-memory-advantages-and-disadvantages-allocating-memory-for-single-variables-by-the-operators-new-and-delete-possible-critical-situations-when-allocating-memory-init_ru/#q02
// - Указателей
// - Констант
// - Ссылок
// - Переопределений операторов ввода\вывода
// - Шаблонов класса 
// - Контейнеров (Последовательных и Ассоциативных)
// - Исключений (и ее правильной обработки)
// - Абстрактных классов
// - Наследовательности $
// - Перегрузки операторов
// - Преобразования типов
// - Статических методов и полей(переменных)
// - this
// - Дружественных функций и Классов
//...


// Исправить и добавить:
// - проверку на существование такого файла (никнейма карты), в случае GET_CARD (чтобы выдавать подсказку, что такой карты нет, и клиент совершил ошибку при вводе никнэйма)
// - вход после login в ту область, где доступны только те карты, которые создал этот пользователь (путем создания новой папки, при создании аккаунта, куда и будут записываться все данные?)
// - сделать безопасность просмотра файлов на компе. Защита от посторонних
// - разделить все задачи из методов классов на личные методы. чтобы для каждой микрозадачи был свой метод.
// 
// - ?? добавить возможность моментального копирования данных из консоли (Нужно ли ?)
// - добавить " std:: " ко всем элементам of namespace std, требующим это. // Так как это признак хорошего тона И ускоряет работу программы.
// - можно добавить новые задачи. Например: 1) Показать все карты
//...


enum CHOICE {
	GET_CARD = 1,
	ENTER_NEW,
	CHANGE_OLD,
	REMOVE_ONE,
	REMOVE_ALL,
	EXIT
};

int main()
{	/*
	// Регистрация и вход
	auto choice1 = 0;		// у меня тут бесконечный вызов main происходит, если я ввожу текст. проблема не решена.
	cout << "1:Register\n2:Login\nYour choice: "; cin >> choice1;
	if (choice1 == 1)
	{
		General_Functions inputy;
		inputy.registration();
		main();
	}
	else if (choice1 == 2)
	{
		General_Functions booly;
		bool status = false;					// хз , я сделал это, чтобы работало. Но это не помогло. https://learn.microsoft.com/ru-ru/cpp/ide/lnt-uninitialized-local?f1url=%3FappId%3DDev16IDEF1%26l%3DRU-RU%26k%3Dk(lnt-uninitialized-local)%26rd%3Dtrue&view=msvc-170
		status = booly.IsLoggedIn();

		if (status == 0)
		{
			cout << "False Login! Try again. \n " << endl;
			system("PAUSE");
			main();
		}
		else 
		{
			cout << "Succesfully logged in! \n " << endl;
			//return true;
			
		}
		
	}

	else
	{
		cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;
		main();
	}
	
	*/

		// Выполнение задач кардхолдера 
	while (true)  // Можно было бы сделать switch case
	{

		General_Functions first;
		first.show_menu();
		cout << "Your choice: ";        //исправить ошибку ввода строчного символа
		int choice;     // нужно оптимизировать путем задачи этой переменной через Класс! и через указатели на динамическую память.
		//getline(cin, choice);    // нужно оптимизировать этот момент путем задачи(переопределения) принципов(операторов) ввода и вывода (по типу обьектов)
		cin >> choice;

		if (choice == GET_CARD) {
			system("cls");		
			
			string card_to_get;
			getline(cin, card_to_get);	// Для считывания пробела после cin (choice)
			cout << "Nickname of card: ";
			getline(cin, card_to_get);

			/*
				char path[255];
				gets(path);

				DIR* dir = opendir(path);



				if (dir)
				{
					struct dirent* ent;
					while ((ent = readdir(dir)) != NULL)
					{
						cout << (ent->d_name) << "\n";
					}
				}
				else
				{
					cout << "Error opening directory" << endl;
				}

			/// 

				ifstream iff("hgh.txt");
				if (iff.bad() == true) 
					cout << "file is not present"; 
				else {}
			
			*/

			GetCardNums gety(card_to_get);
			gety.get_nums();
			


			system("pause");
		}

		else if (choice == ENTER_NEW) {
			system("cls");

			string new_cardnums; // здесь я поменял int на string , дабы была возможность шифрования. С int не получается.
			string new_cardname;

			cout << "Card nums to add: ";
			cin >> new_cardnums;		//Потом сделать тут Переопределение операторов ввода путем создания класса ввода с обьектом!!! Обязательно
			cout << "\nLet's come up with nickname of this card: ";
			cin >> new_cardname;

			CardNumActions numy(new_cardnums, new_cardname);			//(99, "try");
			numy.enter_new();

		 
			system("pause");
		}
		
		else if (choice == CHANGE_OLD) {
			system("cls");

			string change_cardname;
			string change_cardnums;

			cout <<"Which card would you like to edit?\nEnter the nickname of your card: ";
			//getline(cin; change_cardname);				// я хз, оно чето не работает тут 
			cin >> change_cardname;
			cout << "Enter new numbers for this card: ";
			cin >> change_cardnums;

			ChangeCardNums changy(change_cardname, change_cardnums);
			changy.change_nums();
			changy.change_nums_seclev();



			system("pause");
		}
		
		else if (choice == REMOVE_ONE) {
			system("cls");

			/* Убрал эту тему, так как не получалось нормально передать в класс char
			string removable_cardname;
			//char removable_cardname[30];
			cout << "Which card would you like to remove?\nEnter the nickname of your card: ";
			//getline(cin; change_cardname);				// я хз, оно чето не работает тут 
			cin >> removable_cardname;
			*/

			RemoveOneCard removy; // (removable_cardname);
			removy.removecard();

			system("pause");
		}

		else if (choice == REMOVE_ALL) {
			system("cls");
			
			RemoveAllCards remally;
			remally.removecards();

			// Здесь я изложил разные варианты поиска файла в папке по заданным параметрам для дальнейшего его удаления.

			/*  #include "stdafx.h"
				#include "windows.h"
				#include "iostream.h"

				void main()
				{
					WIN32_FIND_DATA FindFileData;
					HANDLE hf;
					hf=FindFirstFile("c:\\*", &FindFileData);
					if (hf!=INVALID_HANDLE_VALUE)
					{
						do
						{
							cout << FindFileData.cFileName << endl;
						}
						while (FindNextFile(hf,&FindFileData)!=0);
						FindClose(hf);
					}
				}

			///

			void get_file_list(string DATA_DIR)
			{
				HANDLE hFind;
				WIN32_FIND_DATA data;

				hFind = FindFirstFile(LPCWSTR(DATA_DIR.c_str()), &data);

				if (hFind != INVALID_HANDLE_VALUE) {
					do {
						printf("%s\n", data.cFileName);
					} while (FindNextFile(hFind, &data));
					FindClose(hFind);
					}
			}

			///

				#include <stdlib.h>
				#include <stdio.h>
				#include <sys/stat.h>

				#include <limits>
				#include <cstdio>
				#include <iostream>
				#include <fstream>
				#include <bitset>

				#include <windows.h>
				#include <tchar.h>
				#include <stdio.h>

			///

			 setlocale(LC_ALL, "");

			  WIN32_FIND_DATA MyFile;
			  HANDLE hFind;

			  hFind = FindFirstFile(L"D:\\TestFolder\\*~*.txt", &MyFile);

			  // проверка найден ли файл
			  if (INVALID_HANDLE_VALUE != hFind)
			  {
				do // основная часть алгоритма
				{
				  //         название_файла	  |			 размер			  |		удалить/оставить
				  wcout << MyFile.cFileName << "|" << MyFile.nFileSizeLow<<"|";

				  // проверка файла на удаление
				  if (MyFile.nFileSizeLow == 0)
				  {
					cout << "Этот удалить" << endl;

					if (DeleteFile(MyFile.cFileName) != 0) { // удаление
					  cout << "Deleting Access!" << endl; // вывод сообщения успешном удалении
					}
					else { // вывод сообщения об ошибке удаления
					  cout << "Deleting Failed => " << GetLastError() << endl;
					}

				  }
				  else
				  {
					cout << "Этот оставить" << endl;
				  }

				  cout << endl << endl;


				} while (NULL != FindNextFile(hFind, &MyFile));

			  }
			  else
			  {
				cout << "\n\nФайлы удовлетваряющие условию не найдены!\n\n";
			  }

			  FindClose(hFind);


			*/

			// FindFirstFile("Some/Directory/Some/*.some");	// опять же C++17

			system("pause");
		}

		else if (choice == EXIT) {
			system("cls");
			cout << " thats all for today. goodbye " << endl;
			break;
			system("pause");
		}
		else
			cout << "We have not got this variant. Sorry. \nLet's try again !\n  " << endl;


	}

	return 168;
}
