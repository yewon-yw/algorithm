#include <iostream>
using namespace std;
int N, r, c, cnt = 0;

void rec(int x, int y, int n) {
	if (x == r && y == c) {
		cout << cnt << "\n";
		return;
	}
	if (x + n > r && x <= r && y + n > c && y <= c) {
		rec(x, y, n / 2);
		rec(x, y + n / 2, n / 2);
		rec(x + n / 2, y, n / 2);
		rec(x + n / 2, y + n / 2, n / 2);
	}
	else {
		cnt += n * n;
	}
}

int main() {
	cin >> N >> r >> c;
	rec(0, 0, (2 << N));
}