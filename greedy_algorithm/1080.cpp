#include <iostream>
using namespace std;
int A[50][50], B[50][50];
int n, m, cnt;

void input() {
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			A[i][j] = c - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			B[i][j] = c - 48;
		}
	}
}

void change(int x, int y) {
	if (x + 3 > n || y + 3 > m) return;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] = !A[i][j];
		}
	}
}

bool check() {
	bool av = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) av = false;
		}
	}
	return av;
}

int main() {
	cin >> n >> m;
	input();
	if ((n < 3 || m < 3) && !check()) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				change(i, j);
				cnt++;
			}
		}
	}
	if (check()) cout << cnt << "\n";
	else cout << -1 << "\n";
}