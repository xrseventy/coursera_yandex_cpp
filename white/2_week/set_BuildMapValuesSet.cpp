//
// Created by alfa on 05.05.2020.
//

#include <set>
#include <iostream>
#include <string>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> str;
	for (auto item : m)
	{
		str.insert(item.second);
	}
	return (str);

}
//int main ()
//{
//	set<string> values = BuildMapValuesSet({
//													{1, "odd"},
//													{2, "even"},
//													{3, "odd"},
//													{4, "even"},
//													{5, "odd"}
//											});
//
//	for (const string& value : values) {
//		cout << value << endl;
//	}
//
//	return(0);
//}
