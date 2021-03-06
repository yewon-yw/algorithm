#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int arr[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max({ dp[i - 1],dp[i - 2] + arr[i],dp[i - 3] + arr[i - 1] + arr[i] });
	}
	cout << dp[n];
}