#include <iostream>
#include <algorithm>
using namespace std;
int dp[301], stair[301];

int fun(int n) {
	if (n == 1) return stair[1];
	else if (n == 2) return stair[1] + stair[2];
	else if (n == 3) return max(stair[2] + stair[3], stair[1] + stair[3]);
	else return max(dp[n - 2] + stair[n], dp[n - 3] + stair[n - 1] + stair[n]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = fun(i);
	}
	cout << dp[n];
}