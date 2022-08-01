#include <iostream>
using namespace std;
int cnt[5];
int field[8][2]; 

int main() {
	int N = 6;
	int k, d, l, area = 1, minus = 1;
	cin >> k;
	for (int i = 0; i < N; i++) {
		cin >> d >> l;
		field[i][0] = d, field[i][1] = l;
		cnt[d]++;
	}
	for (int i = 0; i < N; i++) {
		d = field[i][0], l = field[i][1];
		if (cnt[d] == 1) area *= l;
	}
	for (int i = 0; i < N; i++) {
		int n = (i + 1) % 6;
		int m = (i + 2) % 6;
		if (field[i][0] == field[m][0]) minus *= field[n][1];
	}
	cout << (area - minus)*k << "\n";
}