#include <iostream>
#include "ClientInterface.h"
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>

// Показывает меню в консоли
void ClientInterface::ShowMenu() {
	cout << "[1] Get card details. " << endl;
	cout << "[2] Enter new card. " << endl;
	cout << "[3] Change old card details. " << endl;
	cout << "[4] Remove one card. " << endl;
	cout << "[5] Remove all cards. " << endl;
	cout << "[6] Exit. " << endl;
}