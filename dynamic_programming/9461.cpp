#include <iostream>
using namespace std;
long long dp[101];
int main() {
	int t, n;
	cin >> t;
	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
	while (t--) {
		cin >> n;
		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 5] + dp[i - 1];
		}
		cout << dp[n] << "\n";
	}
}