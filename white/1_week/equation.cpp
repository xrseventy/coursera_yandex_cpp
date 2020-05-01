//
// Created by alfa on 20.04.2020.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
double a, b, c, x, d, x1, x2;
cin >> a >> b >> c;

if((a == 0 && b != 0 && c != 0) || (a != 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0) || (a == 0 && b == 0 && c != 0))
{
	if (a == 0 && b != 0 && c != 0)
	{
		x = -c / b;
		cout << x << endl;
	}
	//if (a != 0 && b == 0 && c != 0)
	//{
//		if ((a > 0 && c < 0) || (a < 0 && c > 0))
//		{
//			x = sqrt(-c / a);
//			cout << x << endl;
//		}
//	}

	if ((a != 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0))
	{
		x = 0;
		cout << x << endl;
	}

	if (a == 0 && b == 0 && c != 0)
	{
		cout << "" << endl;
	}

}

else
	{
	d = pow(b, 2) - 4 * a * c;

	if (d > 0) {
		x1 = ((b * (-1)) + sqrt(d)) / (2 * a);
		x2 = ((b * (-1)) - sqrt(d)) / (2 * a);
		if (x1 < x2)
			cout << x1 << " " << x2;
		else
			cout << x2 << " " << x1;
	} else if (d == 0) {
		x = -(b / (2 * a));
		cout << x;
	} else
		cout << "";

}
	return 0;
}