#include <iostream>
using namespace std;
int card[100];

int main() {
	int n, m, sum = 0, maxv = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i+1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= m) maxv = maxv > sum ? maxv : sum;
			}
		}
	}
	cout << maxv << "\n";
}