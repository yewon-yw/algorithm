#include <iostream>
using namespace std;

int main() {
	int N, share, mod;
	cin >> N;

	share = N / 5;
	mod = N % 5;
	if (mod == 0) {
		cout << share << endl;
		return 0;
	}
	while (true) {
		if (mod % 3 == 0) {
			cout << share + mod / 3 << endl;
			return 0;
		}
		else {
			share--;
			mod += 5;
		}
		if (share < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
}