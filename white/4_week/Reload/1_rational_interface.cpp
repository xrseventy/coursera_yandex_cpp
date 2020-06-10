//
// Created by alfa on 07.06.2020.
//

#include <iostream>
using namespace std;

class Rational {
public:
	Rational() {
		for_numerator = 0;
		for_denumirator = 1;
	}

	Rational(int numerator, int denominator) {
		for_numerator = numerator;
		for_denumirator = denominator;
		its_normal();

	}

	int Numerator() const {
		return for_numerator;

	}

	int Denominator() const {
		return for_denumirator;

	}

private:

	int for_numerator;
	int for_denumirator;
	int check(int a, int b)
	{
		while (b != 0)
		{
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	void its_normal()
	{
		if (for_denumirator < 0)
		{
			if (for_numerator < 0)
			{
				for_denumirator = abs(for_denumirator);
				for_numerator = abs(for_numerator);
			}
			else
			{
				for_denumirator = abs(for_denumirator);
				for_numerator = for_numerator - 2 * for_numerator;
			}
		}
		if (for_numerator == 0)
		{
			for_denumirator = 1;
		}
		int nod = NOD(abs(for_denumirator), abs(for_numerator));
		for_numerator = for_numerator / nod;
		for_denumirator = for_denumirator / nod;
	}
	int NOD(int a, int b)
	{
		while (a > 0 && b > 0)
		{
			if (a > b)
			{
				a = a % b;
			}
			else
			{
				b = b % a;
			}
		}
		return a + b;
	}

};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}