#include <iostream>
using namespace std;

int mc[2][101];
int dp[101][10001];
int N, M;
int result=1000000000;

int main() {
	cin >> N >> M;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mc[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j >= mc[1][i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - mc[1][i]] + mc[0][i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= M)
				result = min(result, j);
		}
	}
	cout << result << endl;
}