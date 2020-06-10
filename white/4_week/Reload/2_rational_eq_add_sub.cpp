//
// Created by alfa on 07.06.2020.
//


#include <iostream>
using namespace std;

class Rational
{
public:
	Rational()
	{
		for_numerator = 0;
		for_denuminator = 1;
	}

	Rational(int numerator, int denominator)
	{
		for_numerator = numerator;
		for_denuminator= denominator;
		its_normal();
	}

	int Numerator() const
	{
		return for_numerator;
	}

	int Denominator() const
	{
		return for_denuminator;
	}
private:
	int for_numerator;
	int for_denuminator;
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
		if (for_denuminator < 0)
		{
			if (for_numerator < 0)
			{
				for_denuminator = abs(for_denuminator);
				for_numerator = abs(for_numerator);
			}
			else
			{
				for_denuminator = abs(for_denuminator);
				for_numerator = for_numerator - 2 * for_numerator;
			}
		}
		if (for_numerator == 0)
		{
			for_denuminator = 1;
		}
		int nod = NOD(abs(for_denuminator), abs(for_numerator));
		for_numerator = for_numerator / nod;
		for_denuminator = for_denuminator / nod;
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

bool operator==(const Rational& a, const Rational& b)
{
	if (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Rational operator+(const Rational& a, const Rational& b)
{
	return Rational(a.Numerator() * b.Denominator() + a.Denominator() * b.Numerator(),
					a.Denominator() * b.Denominator());
}

Rational operator-(const Rational& a, const Rational& b)
{
	return Rational(a.Numerator() * b.Denominator() - a.Denominator() * b.Numerator(),
					a.Denominator() * b.Denominator());
}

int main()
{
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal)
		{
			cout << "4/6 != 2/3" << '\n';
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal)
		{
			cout << "2/3 + 4/3 != 2" << '\n';
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal)
		{
			cout << "5/7 - 2/9 != 31/63" << '\n';
			return 3;
		}
	}

	cout << "OK" << '\n';
	return 0;
}