//
// Created by alfa on 20.04.2020.
//
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string a;
	int count_f = 0;
	int i;
	cin >> a;

	for ( i = 0; i < a.length(); i++)
	{
	   if (count_f == 2)
			break;
	   if (a[i] == 'f')
			count_f++;
	}
		if (count_f == 0)
			cout << "-2";
		else if (count_f == 1)
			cout << "-1";
		else if (count_f == 2)
			cout << i - 1;
	return(0);
}
