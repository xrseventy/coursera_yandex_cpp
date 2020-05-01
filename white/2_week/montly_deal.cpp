//
// Created by alfa on 26.04.2020.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;
void next(int& count_month, const vector<int>& day_of_month, vector<vector<string>>& task_day)
{
	count_month++;
	if (count_month > 11)
	{
		count_month = 0;
	}
	vector <vector<string>> new_month = task_day;
	int last_day = task_day.size();
	int new_day = day_of_month[count_month];

	task_day.resize(new_day);
	int key = new_day - 1;
	if (last_day > new_day)
	{
		for (new_day; last_day > new_day; new_day++)
		{
			task_day[key].insert(end(task_day[key]), begin(new_month[new_day]), end(new_month[new_day]));
		}

	}
	new_month.clear();
}
void print_dump_day(int day, const vector<vector<string>>& day_task)
{
	cout << day_task[day-1].size();
	for (auto i : day_task[day - 1])
	{
		cout << " " << i;
	}
	cout << '\n';
}
int main()
{
	int Q;
	cin >> Q;

	vector <int> day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector <vector<string>> day_task;
	int count_month = 0;
	day_task.resize(day_of_month[count_month], {});

	for (int i = 0; i <= Q; i++)
	{
		string action;
		int day;
		string task;

		cin >> action;
		if (action == "NEXT")
		{
			next(count_month, day_of_month, day_task);

		}
		if (action == "DUMP")
		{
			cin >> day;
			print_dump_day(day, day_task);
		}
		if (action == "ADD")
		{
			cin >> day >> task;
			day_task[day - 1].push_back(task);
		}
	}
	return (0);
}