//
// Created by alfa on 19.04.2020.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main ()
{
	std::vector<std::string> vec_string;
	std::string string;

	for(int i = 3; i >= 1; i--)
	{
		//(getline(std::cin, string));
		 std::cin >> string;
		 vec_string.push_back(string);
	}
	sort(begin(vec_string), end(vec_string));
	std::cout << vec_string[0] <<std::endl;

};

