//
// Created by alfa on 05.05.2020.
//
#include <set>
#include <iostream>
#include <string>
#include <map>


using namespace std;

int main() {
	int Q;
	cin >> Q;

	map <string, set <string>> words;

	while (Q)
	{
		string action;
		cin >> action;

		if (action == "ADD") {

			string word1, word2;
			cin >> word1 >> word2;

			words[word2].insert(word1);
			words[word1].insert(word2);

		}
		else if (action == "COUNT") {

			string word;
			cin >> word;
			cout << words[word].size() << "\n";

		} else if (action == "CHECK") {

			string word1, word2;
			cin >> word1 >> word2;

			if(words[word1].count(word2))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";

		}
	Q--;
	}

	return 0;
}