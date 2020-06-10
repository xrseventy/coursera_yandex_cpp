//
// Created by alfa on 11.05.2020.
//


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> find_history(const map<int, string>& names_by_year,
								int year) {
	vector<string> names;
	for (const auto& item : names_by_year) {
		// если очередное имя не относится к будущему и отличается от предыдущего,
		if (item.first <= year && (names.empty() || names.back() != item.second)) {
			// добавляем его в историю
			names.push_back(item.second);
		}
	}
	return names;
}
string join_name(vector<string> name){
	// нет истории — имя неизвестно
	if (name.empty()) {
		return "";
	}
	// меняем прямой хронологический порядок на обратный
	reverse(begin(name), end(name));

	// начинаем строить полное имя с самого последнего
	string all_name = name[0];

	// перебираем все последующие имена
	for (int i = 1; i < name.size(); ++i) {
		if (i == 1) {
			// если это первое «историческое» имя, отделяем его от последнего скобкой
			all_name += " (";
		} else {
			// если это не первое имя, отделяем от предыдущего запятой
			all_name += ", ";
		}
		// и добавляем очередное имя
		all_name += name[i];
	}

	// если в истории было больше одного имени, мы открывали скобку — закроем её
	if (name.size() > 1) {
		all_name += ")";
	}
	// имя со всей историей готово
	return all_name;
}

string join_first_and_last(const string& name, const string& surname)  {
	if (name.empty() && surname.empty()) {
		return "Incognito";
	} else if (name.empty()) {
		return surname + " with unknown first name";
	} else if (surname.empty()) {
		return name + " with unknown last name";
	} else {
		return name + " " + surname;
	}
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
		const vector<string> first_history = history_first_name(year);
		const vector<string> last_history = history_surname(year);

		string nick;
		string family;
		if (!first_history .empty()) {
			nick  = first_history .back();
		}
		if (!last_history.empty()) {
			family = last_history.back();
		}
		return join_first_and_last(nick, family);
	}
	string GetFullNameWithHistory(int year)
	{
		// получим полное имя со всей историей
		const string first = join_name(history_first_name(year));
		// получим полную фамилию со всей историей
		const string last = join_name(history_surname(year));
		// объединим их с помощью готовой функции
		return join_first_and_last(first, last);
		// получить все имена и фамилии по состоянию на конец года year
	}
private:
// приватные поля
	map <int, string> name;
	map <int, string> surname;
	vector<string> history_first_name(int year)
	{
		return find_history(name, year);
	}
	vector<string> history_surname(int year)
	{
		return find_history(surname, year);
	}

};
//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova-Sergeeva");
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1961, "Ivanova");
//	cout << person.GetFullNameWithHistory(1967) << endl;
//
//	return 0;
//}
