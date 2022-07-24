#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;

int main() {
	int n, max = 0;
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		m[str]++;
		max = max < m[str] ? m[str] : max;
	}
	for (auto t : m) {
		if (t.second == max) {
			cout << t.first << "\n";
			break;
		}
	}
}