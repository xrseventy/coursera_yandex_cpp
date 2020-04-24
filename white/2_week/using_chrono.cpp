//
// Created by alfa on 23.04.2020.
//
//Передача параметров функций по константной ссылке
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Person {
	string name;
	string surname;
	int age;
};

vector<Person> GetMoscowPopulation()
{
};

void PrintPopulationSize(const vector<Person>& p)// создание константной ссылки
{
	cout << "There are " << p.size() << " people in Moscow" << endl;
}
int main()
{
	auto start = steady_clock::now();
	vector<Person> people = GetMoscowPopulation();
	auto finish = steady_clock::now();
	cout << "GetMoscowPopulation " << duration_cast<milliseconds>(finish - start).count() << "ms." << endl;

	 start = steady_clock::now();
	PrintPopulationSize(GetMoscowPopulation());
	 finish = steady_clock::now();
	cout << "PrintPopulationSize " << duration_cast<milliseconds>(finish - start).count() << "ms." << endl;


	return(0);
}