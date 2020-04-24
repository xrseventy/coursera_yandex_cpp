//
// Created by alfa on 23.04.2020.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
vector<string> PalindromFilter (vector<string> words, int minLength)
{
	vector<string> answer;
	for (auto word : words) {
		if (IsPalindrom(word) && word.length() >= minLength)
			answer.push_back(word);
	}
	return (answer);
}

//int main()
//{
//	vector<string> words = {"weew", "bro", "code"};
//	int minLength = 4;
//	vector<string> final;
//
//final = PalindromFilter(words, minLength);
//	for(int i = 0; i < final.size(); i++)
//		cout << final[i] << ' ';
//
//	return(0);
//}
