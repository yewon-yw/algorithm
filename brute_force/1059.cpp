#include <iostream>
#include <algorithm>
using namespace std;
int s[51];

int main() {
	int L, n, a, b, cnt;
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> s[i];
	}
	cin >> n;
	sort(s, s + L);
	for (int i = 0; i < L; i++) {
		if (s[i] == n) {
			cout << 0 << "\n";
			return 0;
		}
		if (s[i] < n) continue;
		a = s[i - 1];
		b = s[i];
		break;
	}
	cnt = (n - a - 1) * (b - n - 1);
	cnt += (b - n - 1) + (n - a - 1);
	cout << cnt << "\n";
}