//
// Created by alfa on 23.04.2020.
//
#include <iostream>
#include <vector>
using namespace std;

void PrintVector (const vector<int>& v)
{
	for(auto s : v)
	{
		cout << s << endl;
	}
}
vector<int> Average(int sum, int count, vector<int> days)
{
	int place = 0;
	int avg = sum / count;


	cout << sum << " sum   count " << count << " \n";
	cout << "avg=" << avg << "\n";

	vector<int> ok_days;

	for(int i : days)
	{

		if (days[i] >= avg) {
			cout << "day[i] " << days[i] << ">" << avg << "\n";
			ok_days.push_back(place);
		}


		//cout << "place=" << place << "\n";


		++place;

	}


	for(auto s : ok_days)
	{
		cout << s << " ";
	}
	return(ok_days);

}


int main() {
	int n = 5;
	int sum = 0;
	//cin >> n;

	vector <int> v = {7, 6, 3, 0, 9};
	for(auto &s : v)
	{
		//cin >> s;
		sum += s;
	}

	PrintVector(Average(sum,n,v));
	return(0);
}