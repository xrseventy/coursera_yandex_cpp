//
// Created by alfa on 25.04.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int Q = 0;
	cin >> Q;
	vector<int> people;
	vector<int> worrypeople ;
	string s;
	int num = 0;
	for (int i = 0; i < Q; ++i) {
		cin >> s;
		if (s!= "WORRY_COUNT") {
			cin >> num ;
			if (s == "COME") {
				int new_people_come = people.size() + num;
				people.resize(new_people_come);
			}
			if (s == "WORRY") {
				people[num] = 1;
			}
			if (s == "QUIET") {
				people[num] = 0;
			}
		} else	if  (s == "WORRY_COUNT") {
			int w = count(begin(people), end(people), 1);
			worrypeople.push_back(w);
		}

	}
	for (auto wp: worrypeople) {
		cout << wp << endl;
	}

	return 0;
}