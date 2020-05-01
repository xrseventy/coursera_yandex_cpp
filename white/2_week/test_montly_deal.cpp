

#include "iostream"
#include "vector"
#include "string"
using namespace std;

void Next(int& count_month, const vector<int>& day_of_month, vector<vector<string>>& task)
{
	count_month++;
	if (count_month > 11)
	{
		count_month = 0;
	}
	vector<vector<string>> new_month = task;
	int days_old = task.size();
	int days_new = day_of_month[count_month];
	task.resize(days_new);
	const int key = days_new - 1;
	if (days_old > days_new)
	{
		for (days_new; days_old > days_new; days_new++)
		{
			task[key].insert(end(task[key]), begin(new_month[days_new]), end(new_month[days_new]));
		}
	}
	new_month.clear();
}

void PrintTasks(int day, const vector<vector<string>>& task)
{
	cout << task[day - 1].size();
	for (auto i : task[day - 1])
	{
		cout << " " << i;
	}
	cout << '\n';
}

int main()
{
	int Q;
	cin >> Q;
	vector<int> day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> task_day;
	int count_month = 0;
	task_day.resize(day_of_month[count_month], {});
	for (int i = 0; Q > i; i++)
	{
		string action;
		int day;
		string task;
		cin >> action;
		if (action == "NEXT")
		{
			Next(count_month, day_of_month, task_day);
		}
		else
		if (action == "DUMP")
		{
			cin >> day;
			PrintTasks(day, task_day);
		}
		else
		if (action == "ADD")
		{
			cin >> day >> task;
			task_day[day - 1].push_back(task);
		}
	}
	return 0;
}

