#include <iostream>
using namespace std;

int gcd(int first, int r) {
	int b, s, mod;
	if (first < r) b = r, s = first;
	else b = first, s = r;
	while (1) {
		mod = b % s;
		if (!mod) break;
		b = s;
		s = mod;
	}
	return s;
}

int main() {
	int n, first, r;
	cin >> n >> first;
	for (int i = 0; i < n - 1; i++) {
		cin >> r;
		int mod = gcd(first, r);
		cout << first / mod << "/" << r / mod << "\n";
	}
}