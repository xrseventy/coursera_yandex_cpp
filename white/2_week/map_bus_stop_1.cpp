//
// Created by alfa on 27.04.2020.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
//Print vector
//			for (auto i : stops)
//			{
//				cout << i << " ";
//			}
//cout << "\n";

void buses_for_stop(const map<string, vector<string>>& buses_and_stops, string find_stop)
{
	for (const auto& item : buses_and_stops)
	{
		for (const auto& stop : item.second)
		{
			if (find_stop == stop)
				cout << item.first;
		}
		cout << "\n";
	}

}

void stops_for_buses(const map<string, vector<string>>& buses_and_stops, string find_bus)
{
	if (buses_and_stops.count(find_bus) == 0)
		cout << "No bus" << endl;

	for (const auto &item : buses_and_stops)
	{
		if (find_bus == item.first)
		{
			cout << "Stop " ;
			for (const auto &stop : item.second)
			{
				cout << stop << ":";
				string needs_stops;
				for (const auto& item : buses_and_stops)
				{
					for (const auto& this_stop : item.second)
					{
						if (stop == this_stop)
							needs_stops = item.first;
					}
					if (needs_stops == find_bus)
						cout << "no interchange";
					else
						cout << needs_stops << " ";
				}
				cout << "\n";

			}
			//if (.size() == 1)
				//	cout << "no interchange";
			//cout << "\n";
		}

	}
}
//                          BUSES_FOR_STOP

//3
//NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//BUSES_FOR_STOP Rumyantsevo

//6
//NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//BUSES_FOR_STOP Vnukovo
//NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//STOPS_FOR_BUS 272

//3
//NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//STOPS_FOR_BUS 32K
int main() {
	int q;
	cin >> q;

	map<string, vector<string>> buses_and_stops;

	for (int i = 0; i < q; i++)
	{
		string operation_code;
		cin >> operation_code;

		if (operation_code == "NEW_BUS")
		{
			string bus;
			int stop_count;

			cin >> bus >> stop_count;
			vector<string> stops;
			stops.resize(stop_count);
			cout << "SIZE STOPS" << stops.size();

			for (auto stop : stops)
			{
				cin >> stop;
				stops.push_back(stop);
			}
			buses_and_stops.emplace(bus,stops);
		}

		else if (operation_code == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			buses_for_stop(buses_and_stops,stop);

		}


		else if (operation_code == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			stops_for_buses(buses_and_stops, bus);

		}

	}

	return(0);
	}

//Печать словаря
//	for (const auto& item : buses_and_stops)
//	{
//		cout << item.first;
//		for (const auto& stop : item.second)
//		{
//			cout << stop << " ";
//		}
//		cout << "\n";
//	}

