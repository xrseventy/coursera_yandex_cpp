//
// Created by alfa on 23.04.2020.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> MoveStrings(vector<string>& src, vector<string>& dst) {
	for (auto str : src) {
		dst.push_back(str);
	}
	src.clear();
// Теперь вектор words пуст
return (dst);
}
//
//int main()
//{
//
//
//	vector<string> source = {"a", "b", "c"};
//
//	cout << "src_before" << "\n";
//	cout << source.size() << " ";
//	for(int i = 0; i < source.size(); i++)
//		cout << source[i] << ' ';
//	cout << "\n";
//
//	vector<string> destination = {"z"};
//	//MoveStrings(source, destination);
//	vector<string> final;
//	vector<string> final_src;
//
//	final = MoveStrings(source, destination);
//	cout << "src_after" << "\n";
//	cout << final_src.size() << " ";
//	for(int i = 0; i < final_src.size(); i++)
//		cout << final_src[i] << ' ';
//
//	cout << "\n";
//
//	cout << "dst" << "\n";
//	cout << final.size() << " ";
//	for(int i = 0; i < final.size(); i++)
//		cout << final[i] << ' ';
//
//// source должен оказаться пустым
//// destination должен
//return (0);
//}