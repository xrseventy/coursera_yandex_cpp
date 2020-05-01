//
// Created by alfa on 23.04.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temperatures(n);
	int sum = 0;
	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	int average = sum / n;
	vector<int> result_indices;
	for (int i = 0; i < n; ++i) {
		if (temperatures[i] > average) {
			result_indices.push_back(i);
		}
	}

	cout << result_indices.size() << endl;
	for (int result_index : result_indices) {
		cout << result_index << " ";
	}
	cout << endl;

	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//void PrintVector (const vector<int>& v)
//{
//	cout << v.size() << "\n";
//	for(auto s : v)
//	{
//		cout << s << " ";
//	}
//}
//vector<int> Average(int sum, int count, vector<int> days)
//{
//	int avg = sum / count;
//	vector<int> ok_days;
//
//	for(int i = 0; i <= days.size(); i++)
//	{
//		if (days[i] >= avg) {
//			ok_days.push_back(i);
//		}
//
//	}
//	return(ok_days);
//}
//
//int main() {
//	int n;
//	int sum = 0;
//	cin >> n;
//
//	vector <int> v(n);
//	for(auto &s : v)
//	{
//		cin >> s;
//		sum += s;
//	}
//	PrintVector(Average(sum,n,v));
//	return(0);
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//void PrintVector (const vector<int>& v)
//{
//	cout << v.size() << "\n";
//	for(auto s : v)
//	{
//		cout << s << " ";
//	}
//}
//vector<int> Average(int sum, int count, vector<int> days)
//{
//	int avg = sum / count;
//	vector<int> ok_days;
////cout << "vec days \n";
////	for(auto s : days)
////	{
////		cout << s << endl;
////	}
//	//cout << sum << " sum   count " << count << " \n";
//	//cout << "avg=" << avg << "\n";
//
//	for(int i = 0; i <= days.size(); i++)
//	{
//		if (days[i] >= avg) {
//			//cout << "days[i] " << days[i] << ">" << avg << "\n";
//			ok_days.push_back(i);
//		}
//
//
//		//cout << "place=" << place << "\n";
//
//
//		//++place;
//
//	}
//
//
//	//for(auto s : ok_days)
//	//{
////		cout << s << " ";
////	}
//	return(ok_days);
//
//}
//
//
//int main() {
//	int n;
//	int sum = 0;
//	cin >> n;
//
//	vector <int> v(n);
//	for(auto &s : v)
//	{
//		cin >> s;
//		sum += s;
//	}
//	//cout << "\n";
//	PrintVector(Average(sum,n,v));
//	return(0);
//}