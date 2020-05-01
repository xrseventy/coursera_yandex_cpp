//
// Created by alfa on 21.04.2020.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ost;
	int count = 0;
	vector <int>nums;


while (n) {
	ost = n % 2;
	nums.push_back(ost);
	count++;
	n /= 2;
	//cout << "n   "<< n << "\n";
	//cout << "ost "<< ost << "\n";
}
	nums.push_back(ost);

for ( int i = count - 1; i >= 0; i--)
{
	cout << nums[i];
}
	return(0);
}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    vector<int> bits;
//
//    cin >> n;
//    while (n > 0) {
//        bits.push_back(n % 2);
//        n /= 2;
//    }
//
//    for (int i = bits.size() - 1; i >= 0; --i) {
//        cout << bits[i];
//    }
//    return 0;
//}