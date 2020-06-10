//
// Created by alfa on 08.06.2020.
//

#include <iostream>
#include <exception>
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
		if (denominator == 0)
		{
			throw invalid_argument("invalid_argument");
		}
		for_numerator = numerator;
		for_denuminator = denominator;
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

Rational operator*(const Rational& a, const Rational& b)
{
	return Rational(a.Numerator() * b.Numerator(),
					a.Denominator() * b.Denominator());
}

Rational operator/(const Rational& a, const Rational& b)
{
	if (b.Numerator() == 0)
	{
		throw domain_error("domain_error");
	}
	return Rational(a.Numerator() * b.Denominator(),
					a.Denominator() * b.Numerator());
}

bool operator<(const Rational& a, const Rational& b)
{
	return (double(a.Numerator()) / (double)a.Denominator()) < double(b.Numerator() / (double)b.Denominator());
}

bool operator>(const Rational& a, const Rational& b)
{
	return (double(a.Numerator()) / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}

ostream& operator<<(ostream& os, const Rational& a)
{
	return os << a.Numerator() <<'/' << a.Denominator();
}

istream& operator>>(istream& is, Rational& r)
{
	int a;
	int b;
	if (is >> a && is.ignore(1) && is >> b)
	{
		r = {a, b};
	}
	return is;
}


int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	} catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}