#include <iostream>
using namespace std;
int prime[10001];
int main() {
	for (int i = 2; i < 10001; i++) prime[i] = i;
	for (int i = 2; i < 10001; i++) {
		for (int j = i + i; j < 10001; j += i) {
			prime[j] = 0;
		}
	}
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int k = n / 2;
		while (1) {
			if (prime[k] && prime[n - k]) {
				cout << k << " " << n - k << "\n";
				break;
			}
			k--;
		}
	}
}