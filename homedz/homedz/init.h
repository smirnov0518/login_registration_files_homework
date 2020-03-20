#pragma once
#include<string>
#include <list>
#include<iostream>
#include<fstream>
struct users {
	std::string name;
	std::string pass;
};
void init(std::list<users> &datas);

void coding(std::string bufer) {
	std::fstream ff("data.txt", std::ios::app);
	char s = 0;
	for (int i = 0; i < sizeof(bufer); i++) {
		if (bufer[i] == '\0' ) {
			break;
		}
		s = int(bufer[i]) - 1;
		ff << s;
		
	}
	ff.close();
}

std::string decode(std::string bufer) {
	
		for (int i = 0; i < sizeof(bufer); i++) {
			if ( bufer[i] == '\0') {
				break;
			}
			bufer[i] = int(bufer[i]) + 1;
			
		}
	
	return bufer;
}

void init(std::list<users> &datas) {
	bool stat = 0;
	users for_push;
	std::fstream ff("data.txt");
	std::string bufer;
	while (!ff.eof()) {

		if (!stat) {
			bufer = "";
			ff >> bufer;
			if (bufer == "")break;
			for_push.name = decode(bufer);
			stat = !stat;
			continue;
		}

		bufer = "";
		ff >> bufer;
		for_push.pass = decode(bufer);

		datas.push_back(for_push);
		stat = !stat;
	}

}