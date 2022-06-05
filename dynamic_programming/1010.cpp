#include <iostream>
using namespace std;
int dp[30][30];

int main() {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) dp[1][i] = i;
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}
		cout << dp[n][m] << "\n";
	}
}