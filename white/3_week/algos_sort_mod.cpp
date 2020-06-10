//
// Created by alfa on 06.05.2020.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int> v)
{
	//cout << title << ": ";
	for (auto i : v)
	{
		cout << i << ' ';
	}
}
int main ()
{
	int N;
	cin >> N;
	vector<int> a;

	while (N)
	{
		int num;
		cin >> num;
		//num = abs(num); // var 1
		a.push_back(num);
		N--;
	}

	sort(a.begin(), a.end(), [] (int& a, int& b) {return abs(a) < abs(b);}); //using lambda functions


	//  sort(begin(v), end(v),
	//       // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r
	//       [](int l, int r) {
	//         return abs(l) < abs(r);
	//       }
	//  );

	//sort(a.begin(), a.end()); //var 1
	Print(a);


	return(0);
}