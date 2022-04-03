#include <iostream>
using namespace std;

int main() {
	int n, k, product[101][2] = { 0 }, bag[101][100001] = { 0 };
	int weight, value;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> product[i][0] >> product[i][1];
	}
	for (int i = 1; i <= n; i++) {
		weight = product[i][0];
		value = product[i][1];
		for (int j = 0; j <= k; j++) {
			if (j < weight) {
				bag[i][j] = bag[i - 1][j];
			}
			else {
				bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - weight] + value);
			}
		}
	}
	cout << bag[n][k];
}