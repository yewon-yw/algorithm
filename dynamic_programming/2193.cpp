#include <iostream>
using namespace std;
long long dp[91] = { 0,1,1, };

int main() {
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];
}