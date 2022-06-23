#include <iostream>
using namespace std;
int sq[50][50];
int N, M, len;

void input() {
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			sq[i][j] = c - 48;
		}
	}
}

bool check(int x, int y) {
	bool c = true;
	if (sq[x][y] != sq[x][y + len]) c = false;
	if (sq[x][y] != sq[x + len][y]) c = false;
	if (sq[x][y] != sq[x + len][y + len]) c = false;
	return c;
}

int main() {
	cin >> N >> M;
	input();
	len = N < M ? N : M;
	while (--len) {
		for (int i = 0; i < N - len; i++) {
			for (int j = 0; j < M - len; j++) {
				if (check(i, j)) {
					cout << (len + 1)*(len + 1) << "\n";
					return 0;
				}
			}
		}
	}
	cout << 1 << "\n";
	return 0;
}