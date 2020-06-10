//
// Created by alfa on 10.05.2020.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;
//При этом с течением времени могут открываться всё новые факты
// из прошлого человека, поэтому года́ в последовательных
// вызовах методов ChangeLastName и ChangeFirstName
// не обязаны возрастать.
string name_in_year(map<int, string>& name, int year)
{
	string find_name;

	for (auto& i : name)
	{
		if (i.first <= year)
		{
			find_name = i.second;
		} else
			break;
	}
	return (find_name);
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name)
	{
		name[year] = first_name;
		// добавить факт изменения имени на first_name в год year
		// в один год 1 имя
	}
	void ChangeLastName(int year, const string& last_name) {
		surname[year] = last_name;
		// добавить факт изменения фамилии на last_name в год year
		// в один год 1 фамилия
	}
	string GetFullName(int year)
	{
		string nick = name_in_year(name, year);
		string family = name_in_year(surname, year);

		//Если к данному году не случилось
		// ни одного изменения фамилии
		// и имени, верните строку "Incognito".
		if (nick.empty() && family.empty()) {
			return ("Incognito");
		}

			// Если к данному году случилось
			// изменение фамилии, но не было
			// ни одного изменения имени, верните
			// "last_name with unknown first name".

		else if (nick.empty()) {
			return (family + " " + "with unknown first name");
		}

			//Если к данному году случилось изменение имени,
			// но не было ни одного изменения фамилии,
			// верните "first_name with unknown last name".
		else if (family.empty()) {
			return (nick + " " + "with unknown last name");
		}
			// получить имя и фамилию по состоянию на конец года year
			// Строка, возвращаемая методом GetFullName, должна содержать
			// разделённые одним пробелом имя и фамилию человека
			// по состоянию на конец данного года.

		else {
			return (nick + " " + family);
		}
	}
private:
// приватные поля
	map <int, string> name;
	map <int, string> surname;

};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}

// Output
//Incognito
//Polina with unknown last name
//Polina Sergeeva
//Polina Sergeeva
//Appolinaria Sergeeva
//Polina Volkova
//Appolinaria Volkova