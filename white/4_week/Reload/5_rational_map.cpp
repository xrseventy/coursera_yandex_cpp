#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
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
	int gcd(int a, int b)
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

int main()
{
	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3)
		{
			cout << "Wrong amount of items in the set" << '\n';
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs)
		{
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
		{
			cout << "Rationals comparison works incorrectly" << '\n';
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2)
		{
			cout << "Wrong amount of items in the map" << '\n';
			return 3;
		}
	}

	cout << "OK" << '\n';
	return 0;
}