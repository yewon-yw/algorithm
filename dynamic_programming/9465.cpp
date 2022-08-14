#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001][3];
int arr[3][100001];

int main() {
	int T, n, res;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 0;
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[1][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[2][i];
		}
		res = max({ dp[n][0],dp[n][1],dp[n][2] });
		cout << res << "\n";
	}
}