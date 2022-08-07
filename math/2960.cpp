#include <iostream>
using namespace std;
int erase[1001];

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (!erase[j]) {
				erase[j] = 1;
				cnt++;
				if (cnt == k) {
					cout << j << "\n";
					break;
				}
			}
		}
	}
}