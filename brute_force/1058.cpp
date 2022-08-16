#include <iostream>
#include <algorithm>
using namespace std;
int f[51][51];
int t[51][51];
int n;

void check(int s, int no) {
	for (int i = 1; i <= n; i++) {
		if (i == no) continue;
		if (f[s][i]) t[no][i] = 1;
	}
}

int find() {
	int m = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (t[i][j]) cnt++;
		}
		m = max(m, cnt);
	}
	return m;
}

int main() {
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == 'N') f[i][j] = 0;
			else f[i][j] = 1;
			t[i][j] = f[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[i][j]) check(j, i);
		}
	}
	cout << find() << "\n";
}