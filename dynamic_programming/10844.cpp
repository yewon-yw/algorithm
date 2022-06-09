#include <iostream>
#define MOD 1000000000
using namespace std;
int dp[101][10] = { {0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1}, };

int sum(int n) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n][i];
		result %= MOD;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][1] % MOD;
			else if (j == 9) dp[i][j] = dp[i - 1][8] % MOD;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	cout << sum(n);
}