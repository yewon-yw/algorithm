#include <iostream>
using namespace std;
int lotto[6];
int s[13];
int k;

void print() {
	for (int i = 0; i < 6; i++) {
		cout << lotto[i] << " ";
	}
	cout << "\n";
}

void rec(int num, int size,int start) {
	lotto[size] = num;
	if (size == 5) {
		print();
		return;
	}
	for (int i = start; i < k; i++) {
		rec(s[i], size + 1, i + 1);
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		for (int i = 0; i <= k - 6; i++) {
			rec(s[i], 0, i + 1);
		}
		cout << "\n";
	}
}