#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("coin.inp");
ofstream fout("coin.out");

int dp[4][4][4], check[3];

int main() {
	int n, a, b, c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				check[0] = i, check[1] = j, check[2] = k;
				sort(check, check + 3, less<int>());
				if (check[0] == 0) {
					if (check[1] == 0 && check[2] == 1) dp[i][j][k] = -1;
					else if (check[1] == 2 && check[2] == 2) dp[i][j][k] = -1;
					else if (check[1] == 3 && check[2] == 3) dp[i][j][k] = -1;
				}
				else if (check[0] == 1) {
					if (check[1] == 1 && check[2] == 1) dp[i][j][k] = -1;
					if (check[1] == 2 && check[2] == 3) dp[i][j][k] = -1;
				}
				if (dp[i][j][k] != -1) dp[i][j][k] = 1;
			}
		}
	}
	fin >> n;
	while (n--) {
		fin >> a >> b >> c;
		fout << "(" << a << " " << b << " " << c << ") : ";
		fout << dp[a % 4][b % 4][c % 4] << "\n";
	}
}