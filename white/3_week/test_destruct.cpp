//
// Created by alfa on 11.05.2020.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Weather {
public:
	Weather(const string& new_state, int new_temperature) {
		 state = new_state;
		 temperature = new_temperature;
		cout << 'c';
	}
	~Weather() {
		cout << 'd';
	}
private:
	string state;
	int temperature;
};

int main() {
	cout << 'a';
	Weather weather("snow", -5);
	cout << 'b';
	return 0;
}