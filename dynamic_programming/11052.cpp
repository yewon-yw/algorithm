#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	for (int i = 1; i <= n; i++) {
		int maxv = dp[i];
		for (int j = 1; j < i; j++) {
			maxv = max(maxv, dp[j] + dp[i - j]);
		}
		dp[i] = maxv;
	}
	cout << dp[n];
}