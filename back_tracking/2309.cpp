#include <iostream>
#include <algorithm>
using namespace std;
int dwarf[9];

int main() {
	int sum = 0, f, s, c;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sum -= 100;
	sort(dwarf, dwarf + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			c = dwarf[i] + dwarf[j];
			if (sum == c) f = i, s = j;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == f || i == s) continue;
		cout << dwarf[i] << "\n";
	}
}