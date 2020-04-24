//
// Created by alfa on 23.04.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
	reverse(v.begin(),v.end());

}

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> nums;

Reverse(numbers);

	for(int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << ' ';
// numbers должен оказаться равен {2, 4, 3, 5, 1}
	return(0);
}