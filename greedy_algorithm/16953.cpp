#include <iostream>
using namespace std;
int main() {
	int a, b, cnt = 1;
	cin >> a >> b;
	while (1) {
		if (b % 10 == 1) {
			b /= 10;
			cnt++;
		}
		else if (b % 2 == 0) {
			b /= 2;
			cnt++;
		}
		else break;
		if (a > b) break;
		if (a == b) {
			cout << cnt;
			return 0;
		}
	}
	cout << -1;
	return 0;
}