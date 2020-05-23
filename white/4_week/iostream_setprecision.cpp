//
// Created by alfa on 14.05.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
	//ifstream input("/home/alfa/coursera_yandex_cpp/white/4_week/input.txt");
	ifstream input("input.txt");
	double num;
	cout << fixed << setprecision(3);
	while (input >> num)
	{
		cout << num << endl;
	}


	return(0);

}
