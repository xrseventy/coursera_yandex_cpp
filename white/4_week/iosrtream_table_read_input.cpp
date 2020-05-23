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
	int n, m;
	int i = 0;
	if (input)
	{
		input >> n >> m;
	}
	double num;
	while (n)
	{
		for (i = 0; i < m; i++)
		{
			if(input)
			{
				input >> num;
				input.ignore(1);
				cout << fixed << setprecision(0);
				cout << setw(10);
				//cout << setfill(' ');
				cout << num;
				if (i != m - 1)
					cout << " ";

			}

		}
		if (n == 1)
			break;
		else
			cout << "\n";
		n--;
	}
return(0);

}