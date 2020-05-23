//
// Created by alfa on 10.05.2020.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class SortedStrings {
public:
	void AddString(const string& s) {
		// добавить строку s в набор
		str.push_back(s);


	}
	vector<string> GetSortedStrings() {
		// получить набор из всех добавленных строк в отсортированном порядке
		str.sort();
	}
private:
	vector <string> str;
	// приватные поля
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}