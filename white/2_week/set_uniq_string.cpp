//
// Created by alfa on 05.05.2020.
//

#include <set>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int Q;
	cin >> Q;
	set <string> str;
	while (Q)
	{
		string stroke;
		cin >> stroke;
		str.insert(stroke);
		Q--;
	}
	cout << str.size();
	return (0);
}