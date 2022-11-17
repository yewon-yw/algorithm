#include <fstream>
#include <algorithm>
#define INF -987654321
using namespace std;

ifstream fin("card.inp");
ofstream fout("card.out");

int a[1001], dp[4][1001];

int main() {
	int T, n;
	fin >> T;
	while (T--) {
		fin >> n;
		for (int i = 1; i <= n; i++) {
			fin >> a[i];
		}
		for (int i = 1; i <= 3; i++) {
			dp[i][1] = a[1];
			dp[i][2] = a[2];
			dp[i][3] = a[3];
		}
		dp[1][4] = INF, dp[2][4] = a[1] + a[4], dp[3][4] = a[2] + a[4];
		for (int i = 5; i <= n; i++) {
			dp[1][i] = a[i] + max({ dp[1][i - 4],dp[2][i - 4],dp[3][i - 4] });
			dp[2][i] = a[i] + max({ dp[1][i - 3],dp[2][i - 3],dp[3][i - 3] });
			dp[3][i] = a[i] + max({ dp[1][i - 2],dp[2][i - 2] });
		}
		fout << max({ dp[1][n],dp[2][n],dp[3][n] }) << "\n";
	}
}