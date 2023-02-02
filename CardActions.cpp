#include "CardActions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <direct.h>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

// Показывает данные карты 
void CardActions::GetNums(const string& card_to_get, string& currentUser) {
	//13
	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	fstream file(*path + card_to_get + ".txt", std::ios::in);

	fs::path cardPath(*path + card_to_get + ".txt");
	delete path;
	path = nullptr;
	if (fs::exists(cardPath)) {

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

			cout << decrypt_nums << endl;
		}

		file.close();


		cout << "Above you see the details of card \"" + card_to_get + "\" " << endl;
	}
	else {
		cout << "You haven't got this card. Check entered cardname." << endl;
	
	}
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
		for (size_t j = 0; j < 3 - (to_string((int)new_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += to_string((int)(new_cardnums[i]));
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
		for (size_t j = 0; j < 3 - (to_string((int)change_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += to_string((int)(change_cardnums[i]));
	}

	file << encrypt_cardnums;	//38
	file.close();

	cout << "Actual cardnumbers for " + change_cardname + " was succesfully changed.\n" << endl;
}

// Удаляет данные определённой карты
void CardActions::RemoveCard(string& file_name, string& currentUser) {
	//19
	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "\\";
	fs::path userPath(*path);
	if (!fs::is_empty(userPath)) {
		if (!fs::remove(*path + file_name + ".txt"))
			cout << "Ooops. Something went wrong." << endl;
		else
			cout << "Card " + file_name + " succesfully deleted." << endl;
		delete path;
		path = nullptr;
	}
	else {
		cout << "Your CardHolder is empty. There aren't any card." << endl;
		delete path;
		path = nullptr;
	}
}


// Удаляет все карты
void CardActions::RemoveCards(string& currentUser) {
	//36
	string* path = new string;
	*path = "C:\\Users\\79296\\source\\repos\\RealCardNumHolder11\\" + currentUser + "";
	if(!std::filesystem::remove_all(*path)) // Deletes one or more files recursively.
		cout << "Ooops. Something went wrong." << endl;
	else {
		cout << "All Cards of account \"" + currentUser + "\" succesfully deleted." << endl;
		if (fs::create_directories(*path))
			cout << "Use the updated CardHolder \"na zdorovie!\"" << endl;
		else {
			cout << "Problems with creation of new CardHolder. Create it by yourself." << endl;
		}
	}
	delete path;
	path = nullptr;
}