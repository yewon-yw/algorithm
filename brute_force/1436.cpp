#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, result = 666, index = 0;
	string s;
	cin >> n;
	while (true) {
		s = to_string(result);
		if (s.find("666") != string::npos) {
			index++;
			if (index == n) {
				cout << result;
				return 0;
			}
		}
		result++;
	}
}