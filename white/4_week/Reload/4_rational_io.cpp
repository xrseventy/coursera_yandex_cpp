#include <iostream>
#include <sstream>
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

Rational operator*(const Rational& a, const Rational& b)
{
	return Rational(a.Numerator() * b.Numerator(),
					a.Denominator() * b.Denominator());
}

Rational operator/(const Rational& a, const Rational& b)
{
	return Rational(a.Numerator() * b.Denominator(),
					a.Denominator() * b.Numerator());
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
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}