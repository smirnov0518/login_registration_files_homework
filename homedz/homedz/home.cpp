#include<iostream>
#include <math.h>
#include <ctime>
#include <string>
#include<fstream>
#include <list>
#include "init.h"

using namespace std;

void registration(list<users> &datas);

int main()
{
	srand(time(0));

	list<users> datas;
	string pass = "", login = "";

	init(datas);

	int choise = 0;
	do {
		bool chek = 0;
		cout << "1. Log in\n2. Registration\n0. Exit\n";
		cin >> choise;
		switch (choise) {
		case 1: {
			cout << "Enter your login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> pass;
			for (users item : datas) {
				if (login == item.name&&pass == item.pass) {
					cout << "Hello, " << item.name << " !" << endl;
					chek = 1;
				}
			}
			if (!chek)cout << "Wrong data!" << endl;
			break;
		}
		case 2: {
			registration(datas);
		}
		}
	} while (choise != 0);

	system("pause");
	return 0;
}

void registration(list<users> &datas) {
	string bufer;
	char s = 0;
	fstream ff("data.txt", ios::app);
	users foradd;
	cout << "Enter name: ";
	cin >> bufer;
	foradd.name = bufer;
	coding(bufer);
	ff << endl;
	cout << "Enter password: ";
	cin >> bufer;
	foradd.pass = bufer;
	coding(bufer);

	datas.push_back(foradd);


	ff << endl;
	ff.close();
}
