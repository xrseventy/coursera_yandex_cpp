//
// Created by alfa on 14.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	//ifstream input("/home/alfa/coursera_yandex_cpp/white/4_week/input.txt");
	ifstream input("input.txt");
	string line;
		while (getline(input, line))
		{
			cout << line << endl;
		}


return(0);

}
