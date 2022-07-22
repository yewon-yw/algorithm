#include <iostream>
#include <algorithm>
using namespace std;
int T[17], P[17], dp[17];

int main() {
	int N, maxv = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N+1; i++) {
		maxv = max(dp[i], maxv);
		if (i + T[i] <= N + 1) dp[i + T[i]] = max(dp[i + T[i]], maxv + P[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N + 1] << "\n";
}