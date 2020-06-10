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
	if (buses_and_stops.count(find_stop) == 0)
		cout << "No stop" << endl;
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

void stops_for_buses(const map<string, vector<string>>& buses_and_stops, string find_bus) {

	int l = 0;
	if (buses_and_stops.count(find_bus) == 0)
		cout << "No bus" << endl;

	else
		{
		for (const auto item : buses_and_stops)
		{
			//cout << "          TEST FIND" << item.first.find(find_bus) << "\n";
			if (item.first == find_bus)
			{
				for (auto stop : item.second)
				{
					cout << "Stop " << stop << ":";
					int l2 = 0;
					vector<string> v;
					//cout << "item.first =" << item.first << "\n";
					//cout << "need_bus" << need_bus << "\n";

					//cout << "find bus =" << find_bus << "\n";
					//cout << "item.first =" << item.first << "\n";

					for (auto item2 : buses_and_stops) {
						for (auto need_stop : item2.second) {
							if (need_stop == stop) {
								v.push_back(item2.first);
								l2++;
							}
						}
					}
					if (l2 == 0)
						cout << "no interchange";
					else if (l2 > 0)
					{
						for (const auto &bus : item.second)
						{
							for (auto fit_bus : v)
							{
								if (fit_bus == bus)
								{
									cout << " " << bus;
								}
							}
						}
					}
					cout << "\n";
				}
				l++;

			}

		}
		}
}



void all_buses(const map<string, vector<string>>& buses_to_stops)
{
	if (buses_to_stops.empty())
	{
		cout << "No buses" << endl;
	} else
		{
		for (const auto& bus_item : buses_to_stops)
		{
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second)
			{
				cout << stop << " ";
			}
			cout << endl;
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

int main()
{
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

		else if (operation_code == "ALL_BUSES")
		{
			all_buses(buses_and_stops);
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