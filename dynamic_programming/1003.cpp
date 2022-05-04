#include <iostream>
using namespace std;

int main() {
	pair<int, int> dp[41];
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	for (int i = 2; i < 41; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << dp[N].first << " " << dp[N].second << "\n";
	}
}