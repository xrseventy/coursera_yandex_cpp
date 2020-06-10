////
//// Created by alfa on 06.05.2020.
////
//
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//string str_low(string str)
//{
//	string low;
//	for (auto i : str)
//	{
//		low += tolower(i);
//	}
//	return(low);
//}
//
//void Print(vector<string> v)
//{
//	for (auto i : v)
//	{
//		cout << i << ' ';
//	}
//}
//int main ()
//{
//	int N;
//	cin >> N;
//	vector<string> a;
//
//	while (N)
//	{
//		string str;
//		cin >> str;
//		a.push_back(str);
//		N--;
//	}
//
//	sort(a.begin(), a.end(), [] (string& a, string& b) {return str_low(a) < str_low(b);}); //using lambda functions
//
//	//Наиболее нетривиальная часть решения этой задачи — реализовать функцию,
//	// сравнивающую две строки без учёта регистра.
//	//
//	//Это можно сделать, например, с помощью функции lexicographical_compare,
//	// сравнивающей два диапазона элементов (в нашем случае — два набора символов)
//	// с помощью данного компаратора. В компараторе для функции lexicographical_compare
//	// мы используем функцию tolower, возвращающую символ, приведённый к нижнему регистру.
//
//
//	//            ---====SOLUTION FROM TEACHERS====---
////	sort(begin(v), end(v),
////			// компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
////		 [](const string& l, const string& r) {
////			 // сравниваем лексикографически...
////			 return lexicographical_compare(
////					 // ... все символы строки l ...
////					 begin(l), end(l),
////					 // ... со всеми символами строки r ...
////					 begin(r), end(r),
////					 // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
////					 [](char cl, char cr) { return tolower(cl) < tolower(cr); }
////			 );
////		 }
////	);
//	Print(a);
//
//
//	return(0);
//}
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main() {
	{
		vector<string> w;
		w.push_back("One");
		{
			w.push_back("Two");
			{
				w.push_back("Three");
			}
		}
		for (auto s : w) {
			cout << s;
		}
	}
	return (0);
}