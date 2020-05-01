//
// Created by alfa on 27.04.2020.
//
#include <iostream>
#include <map>

using namespace std;
int main() {
	map<string, int> m = {{"Eight", 8},
						  {"Two", 2}};

	//m.erase("Eight"); //work
	//m.count(8) = 0; //not
	//m.count("Eight") = 0; //not
	//m["Eight"] = 0; // work size 2|  course no
	//m.erase("Eight", 8); // not
	cout << m.size();
	return (0);
}