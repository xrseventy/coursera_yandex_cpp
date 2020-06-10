//
// Created by alfa on 04.05.2020.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void buses_for_stop(map<string, vector<string>>& stops_to_buses,
					const string& stop) {
	if (stops_to_buses.count(stop) == 0) {
		cout << "No stop" << endl;
	} else {
		for (const string& bus : stops_to_buses[stop]) {
			cout << bus << " ";
		}
		cout << endl;
	}
}

void stops_for_bus(map<string, vector<string>>& buses_to_stops,
				   map<string, vector<string>>& stops_to_buses,
				   const string& bus) {
	if (buses_to_stops.count(bus) == 0) {
		cout << "No bus" << endl;
	} else {
		for (const string& stop : buses_to_stops[bus]) {
			cout << "Stop " << stop << ": ";

			if (stops_to_buses[stop].size() == 1) {
				cout << "no interchange";
			} else {
				for (const string& other_bus : stops_to_buses[stop]) {
					if (bus != other_bus) {
						cout << other_bus << " ";
					}
				}
			}
			cout << endl;
		}
	}
}

void all_buses(const map<string, vector<string>>& buses_to_stops) {
	if (buses_to_stops.empty()) {
		cout << "No buses" << endl;
	} else {
		for (const auto& bus_item : buses_to_stops) {
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> buses_to_stops, stops_to_buses;

	for (int i = 0; i < q; ++i) {
		string action;
		cin >> action;

		if (action == "NEW_BUS") {

			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;

			vector<string>& stops = buses_to_stops[bus];
			stops.resize(stop_count);

			for (string& stop : stops) {
				cin >> stop;
				stops_to_buses[stop].push_back(bus);
			}

		} else if (action == "BUSES_FOR_STOP") {

			string stop;
			cin >> stop;
			buses_for_stop(stops_to_buses, stop);

		} else if (action == "STOPS_FOR_BUS") {

			string bus;
			cin >> bus;
			stops_for_bus(buses_to_stops, stops_to_buses, bus);

		} else if (action == "ALL_BUSES") {

			all_buses(buses_to_stops);

		}
	}

	return 0;
}