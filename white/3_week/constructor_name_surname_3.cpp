//
// Created by alfa on 11.05.2020.
//
#include "iostream"
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> find_history(const map<int, string>& names_by_year,
								int year) {
	vector<string> name;
	for (const auto& item : names_by_year) {
		if (item.first <= year && (name.empty() || name.back() != item.second)) {
			name.push_back(item.second);
		}
	}
	return name;
}

string join_name( vector<string> name){
	reverse(begin(name), end(name));
	string all_name  = name[0];
	for (int i = 1; i < name.size(); ++i) {
		if (i == 1) {
			all_name += " (";
		} else {
			all_name += ", ";
		}
		all_name += name[i];
	}
	if (name.size() > 1) {
		all_name += ")";
	}
	return all_name;
}

class Person {
public:
	// конструктор
	Person(const string& first_name, const string& last_name,
		   int new_birth_year) {
		birth_year = new_birth_year;
		name[birth_year] = first_name;
		surname[birth_year] = last_name;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year >= birth_year) {
			name[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= birth_year) {
			surname[year] = last_name;
		}
	}
	string GetFullName(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		const vector<string> first_names = FindFirstNamesHistory(year);
		const vector<string> last_names = FindLastNamesHistory(year);
		// объединяем имя и фамилию через пробел
		return first_names.back() + " " + last_names.back();
	}
	string GetFullNameWithHistory(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		const string first_name = join_name(FindFirstNamesHistory(year));
		const string last_name = join_name(FindLastNamesHistory(year));
		return first_name + " " + last_name;
	}
private:
	vector<string> FindFirstNamesHistory(int year) const {
		return find_history(name, year);
	}
	vector<string> FindLastNamesHistory(int year) const {
		return find_history(surname, year);
	}

	int birth_year;
	map<int, string> name;
	map<int, string> surname;
};

//int main()
//{
//	Person person("Polina", "Sergeeva", 1960);
//	for (int year : {1959, 1960})
//	{
//		cout << person.GetFullNameWithHistory(year) << '\n';
//	}
//
//	person.ChangeFirstName(1965, "Appolinaria");
//	person.ChangeLastName(1967, "Ivanova");
//	for (int year : {1965, 1967})
//	{
//		cout << person.GetFullNameWithHistory(year) << '\n';
//	}
//	return 0;
//}