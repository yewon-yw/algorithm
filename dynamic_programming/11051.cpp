#include <iostream>
using namespace std;
int com[1001][1001];
// nCr = n-1Cr + n-1Cr-1
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		com[i][0] = 1;
		com[i][i] = 1;
		for (int j = 1; j < i; j++) {
			com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % 10007;
		}
	}
	cout << com[n][k];
}