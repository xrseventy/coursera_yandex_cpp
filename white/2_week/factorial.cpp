//
// Created by alfa on 22.04.2020.
//

#include <iostream>
using namespace std;
//int Factorial(int x) {
//	if (x <= 1) {
//		return 1;
//	} else {
//		return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
//	}
//}


int Factorial(int a)
{
	int fact;
	if (a < 0 || a == 0 || a == 1)
	{
		return (1);
	}
	else
		fact = a * Factorial (a - 1);


	return(fact);

}

//int main ()
//{
//	int n;
//	cin >> n;
//
//	cout << Factorial(n);
//	return(0);
//}