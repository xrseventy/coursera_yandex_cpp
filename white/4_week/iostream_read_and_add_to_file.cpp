//
// Created by alfa on 14.05.2020.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	//ifstream input("/home/alfa/coursera_yandex_cpp/white/4_week/input.txt");
	//ofstream output("/home/alfa/coursera_yandex_cpp/white/4_week/output.txt");
	fstream input("input.txt");
	ofstream output("output.txt");
	string line;
	while (getline(input, line))
	{
		output << line << endl;
	}
	return(0);

}