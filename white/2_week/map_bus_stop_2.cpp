//
// Created by alfa on 05.05.2020.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
int main()

{
	int Q;
	cin >> Q;
	map <vector<string>, int> stops_and_buses;
	string stop;

	while (Q) {
		int N;
		cin >> N;

		vector<string> stops;
		for (int i = 0; i < N; i++) {
			cin >> stop;
			stops.push_back(stop);
		}
		if (stops_and_buses.count(stops)) //возращает кол-во автобусов с этим же набором остановок
		{
			cout << "Already exists for " << stops_and_buses[stops] << '\n';
		} else
		{
			stops_and_buses[stops];
			int size = stops_and_buses.size();
			stops_and_buses[stops] = size;
			cout << "New bus " << stops_and_buses[stops] << '\n';
		}

		Q--;
	}
	return (0);
}