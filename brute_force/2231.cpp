#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int result = i;
		int tmp = i;
		while (1) {
			result += tmp % 10;
			if (tmp < 10) break;
			tmp /= 10;
		}
		if (result == n) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}