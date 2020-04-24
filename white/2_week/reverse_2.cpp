//
// Created by alfa on 23.04.2020.
//

//
// Created by alfa on 23.04.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector<int> t;
	t = v;
		int n = v.size();  // для удобства сохраним размер вектора в переменную n
		for (int i = 0; i < n / 2; ++i) {
			// элемент с индексом i симметричен элементу с индексом n - 1 - i
			// поменяем их местами с помощью временной переменной tmp
			int tmp = t[i];
			t[i] = t[n - 1 - i];
			t[n - 1 - i] = tmp;
		}

	//for(int i = 0; i < t.size(); i++)
	//	cout << t[i] << ' ';
	return(t);
}

//int main()
//{
//	vector<int> numbers = {1, 5, 3, 4, 2};
//	vector<int> nums;
//
//cout << Reverse(numbers);
//
//	//for(int i = 0; i < numbers.size(); i++)
//	//	cout << numbers[i] << ' ';
//// numbers должен оказаться равен {2, 4, 3, 5, 1}
//	return(0);
//}