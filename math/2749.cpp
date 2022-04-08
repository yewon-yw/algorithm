#include <iostream>
#include <vector>
using namespace std;
int len = 1500000;

int main() {
	long long n;
	cin >> n;
	vector<long long> remainder;
	remainder.push_back(0); remainder.push_back(1); remainder.push_back(1);
	for (int i = 3; i < len; i++) {
		remainder.push_back((remainder.at(i - 1) + remainder.at(i - 2)) % 1000000);
	}
	cout << remainder.at(n % len);
}