#include <iostream>
#include <algorithm>
using namespace std;
int dp[500][500];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, maxv = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + dp[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
		}
	}
	for (int j = 0; j < n; j++) {
		maxv = maxv < dp[n - 1][j] ? dp[n - 1][j] : maxv;
	}
	cout << maxv;
}