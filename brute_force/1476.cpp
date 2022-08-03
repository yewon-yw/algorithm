#include <iostream>
using namespace std;

int main() {
	int e, s, m, te = 1, ts = 1, tm = 1;
	int year = 1;
	cin >> e >> s >> m;
	while (1) {
		if (te == e && ts == s && tm == m) break;
		year++;
		te = ++te > 15 ? te - 15 : te;
		ts = ++ts > 28 ? ts - 28 : ts;
		tm = ++tm > 19 ? tm - 19 : tm;
	}
	cout << year << "\n";
}