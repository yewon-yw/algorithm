#include <iostream>
#include <string>
using namespace std;

void rec(int cnt, string x) {
	int itm = 0;
	if (x.size() <= 1) {
		cout << cnt << "\n";
		if (x == "3" || x == "6" || x == "9") cout << "YES\n";
		else cout << "NO\n";
		return;
	}
	for (int i = 0; i < x.size(); i++) {
		itm += x[i] - 48;
	}
	rec(cnt + 1, to_string(itm));
}

int main() {
	string num;
	cin >> num;
	rec(0, num);
}