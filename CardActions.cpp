#include "CardActions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <direct.h>


// Показывает данные карты 
void CardActions::GetNums(const string& card_to_get, string& currentUser) {
	//13
	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	fstream file(*path + card_to_get + ".txt", std::ios::in);
	delete path;
	path = nullptr;

	if (!file.is_open()) {
		cout << "[-] File is not opened! 1 level of get_nums() ";
		exit(EXIT_FAILURE);
	}
	string desired_card_nums;	//32!
	while (getline(file, desired_card_nums))
	{
		string decrypt_nums;	//32!
		std::string tempStr;	//14
		for (size_t i = 0; i < desired_card_nums.size(); i += 3)
		{
			tempStr.push_back(desired_card_nums[i]);
			tempStr.push_back(desired_card_nums[i + 1]);
			tempStr.push_back(desired_card_nums[i + 2]);
			decrypt_nums.push_back(char(std::stoi(tempStr)));
			tempStr.clear();
		}

		std::cout << decrypt_nums << std::endl;
	}

	file.close();
	

	cout << "Above you see the details of card \"" + card_to_get + "\" " << endl;
}

// Записывает новые данные карты 
void CardActions::EnterNew(const string& new_cardnums, const string& new_cardname, string& currentUser) {

	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	ofstream file(*path + new_cardname + ".txt", std::ios::app);
	delete path;
	path = nullptr;

	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = ""; //32!
	for (size_t i = 0; i < new_cardnums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)new_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(new_cardnums[i]));
	}

	file << encrypt_cardnums;	//16
	file.close();

	cout << "New cardnumbers was succesfully recorded.\n " << endl;
}

// Удаляет данные существующей карты 
void CardActions::ChangeNumsFirst(const string& change_cardname, string& currentUser) {//17

	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	fstream file(*path + change_cardname + ".txt", std::ios::out | std::ios::trunc);	//18 
	delete path;
	path = nullptr;
	 
	if (!file.is_open()) {
		cout << "[-] File is not openned! 1 level of change_nums() ";
		exit(EXIT_FAILURE);
	}
	file.close();

}

// Меняет(обновляет) данные существующей карты
void CardActions::ChangeNumsSecond(const string& change_cardname, const string& change_cardnums, string& currentUser) {

	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	fstream file(*path + change_cardname + ".txt", std::ios::app);	//18 
	delete path;
	path = nullptr;

	if (!file.is_open()) {
		cout << "[-] File is not opened! 2 level of change_nums() ";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = "";

	for (size_t i = 0; i < change_cardnums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)change_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(change_cardnums[i]));
	}

	file << encrypt_cardnums;			// Тут нужно как-то поаккуратнее ввести данные
	file.close();

	cout << "Actual cardnumbers for " + change_cardname + " was succesfully changed.\n" << endl;
}

// Удаляет данные определённой карты
void CardActions::RemoveCard(string& file_name, string& currentUser) {
	//19

	// Нерабочие варианты
	// 
	//1 вариант
	// 
	//string* path = new string;
	//*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	//fstream file(*path + file_name + ".txt", std::ios::out | std::ios::trunc);	//18 
	//delete path;
	//path = nullptr;
	//if (!file.is_open()) {
	//	cout << "[-] File is not openned! 1 level of change_nums() ";
	//	exit(EXIT_FAILURE);
	//}
	//cout << "Succes. Card\""+ file_name +"\" has been removed.\n";
	//file.close();
	

	//2 вариант 
	//
	/*int size = file_name.size();
	char* currentFile = new char[size];
	for (int i = 0; i < size; i++) {
		currentFile[i] = (char)file_name[i];
	}
	(const char*)currentFile;
	cout << currentFile;*/
	/*if (remove(currentFile) != 0)
		cout << "huita. file has NOT been removed \n";
	else
		cout << "succes. file has been removed\n";

	delete[] currentFile;
	currentFile = nullptr;*/


	// Заметки
	// 
	//cout << file_name.size() << endl;;
	//for (int i = 0; i < size; i++) {
	//	cout << currentFile[i] << endl;;
	//}
	//cout << currentFile;
	/*const char* currentFileReal = new char[size];
	*currentFileReal = *currentFile;*/

}


// Удаляет все карты
void CardActions::RemoveCards(string& currentUser) {
	//36



	// Нерабочие варианты
	// 
	// 1 вариант
	/*size_t* size = new size_t;
	*size = currentUser.size();
	char* currentFolder = new char[*size];
	for (int i = 0; i < *size; i++) {
		currentFolder[i] = (char)currentUser[i];
	}
	(const char*)currentFolder;

	if (_rmdir(currentFolder)==-1) 
		cout << "Error: ?" << endl;
	else 
		cout << "succesfully deleted" << endl;*/


	//2 вариант
	/*string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "";
	fstream folder(*path, std::ios::trunc );	//18 
	delete path;
	path = nullptr;

	if (!folder.is_open()) {
		cout << "[-] Folder is not openned!";
		exit(EXIT_FAILURE);
	}
	folder.close();
	cout << "Succes. All cards of Account \"" + currentUser + "\" has been removed.\n";*/


	// 3 variant 
	//#include <conio.h>
	//#include <Windows.h>
	//BOOL DeleteFolder(string* szPath);	// type : LPCSTR
	//string* path = new string;
	//*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "";
	//if (DeleteFolder(*path) == TRUE)
	//	cout << "Папка ВПО удалена!\n";
}