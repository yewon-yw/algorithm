#include <iostream>
#include <string>
using namespace std;

void cal(string big, string small) {
	for (int i = big.size() - 1; i >= 0; i--) {
		int c = (big[i] - 48) + (small[i] - 48);
		big[i] = (c % 10) + 48;
		if (i == 0) {
			if (c / 10 != 0) big = to_string(c / 10) + big;
			break;
		}
		big[i - 1] += (c / 10);
	}
	cout << big << endl;
}

int main() {
	string a, b;
	cin >> a >> b;
	if (a.size() > b.size()) {
		for (int i = b.size(); i < a.size(); i++) {
			b = "0" + b;
		}
		cal(a,b);
	}
	else {
		for (int i = a.size(); i < b.size(); i++) {
			a = "0" + a;
		}
		cal(b,a);
	}
}