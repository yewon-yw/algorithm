#include <fstream>
#define MOD 1000000007;
using namespace std;

ifstream fin("addingways.inp");
ofstream fout("addingways.out");
int dp[301][21];

void make_dp() {
	for (int i = 1; i <= 300; i++) {
		for (int j = 1; j <= 20; j++) {
			if (j > i) break;
			if (j == 1 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
		}
	}
}

int main() {
	int n, k;
	make_dp();
	while (1) {
		fin >> n >> k;
		if (!n && !k) break;
		fout << dp[n][k] << "\n";
	}
}