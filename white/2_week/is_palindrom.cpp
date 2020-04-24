//
// Created by alfa on 22.04.2020.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//bool IsPalindrom(string s) {
//    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
//    // О причинах Вы узнаете на Жёлтом поясе
//    for (int i = 0; i < s.size() / 2; ++i) {
//        if (s[i] != s[s.size() - i - 1]) {
//            return false;
//        }
//    }
//    return true;
//}
bool IsPalindrom (string str)
{
	string rev;

	rev = str;
	reverse(rev.begin(),rev.end());
	if (rev == str)
		return (true);
	else
		return (false);

}

//int main()
//{
//	string str;
//	cin >> str;
//
//	cout << boolalpha <<  IsPalindrom(str);
//	return(0);
//}


