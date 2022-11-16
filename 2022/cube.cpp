#include <iostream>
#include <fstream>
#include <algorithm>
#define INF 987654321
#define SIZE 200
using namespace std;

ifstream fin("cube.inp");
ofstream fout("cube.out");

int dp[SIZE + 1][SIZE + 1][SIZE + 1];

void make_dp() {
	for (int i = 1; i <= SIZE; i++) {
		dp[1][1][i] = dp[1][i][1] = dp[i][1][1] = i;
		dp[i][i][i] = 1;
	}
	for (int x = 1; x <= SIZE; x++) {
		for (int y = 1; y <= SIZE; y++) {
			for (int z = 1; z <= SIZE; z++) {
				if (dp[x][y][z] == 0) {
					int result = INF;
					for (int i = 1; i <= x / 2; i++) {
						result = min(result, dp[i][y][z] + dp[x - i][y][z]);
					}
					for (int i = 1; i <= y / 2; i++) {
						result = min(result, dp[x][i][z] + dp[x][y - i][z]);
					}
					for (int i = 1; i <= z / 2; i++) {
						result = min(result, dp[x][y][i] + dp[x][y][z - i]);
					}
					dp[x][y][z] = dp[x][z][y] = dp[y][x][z] = dp[y][z][x] = dp[z][x][y] = dp[z][y][x] = result;
				}
			}
		}
	}
}

int main() {
	make_dp();
	int T, x, y, z;
	fin >> T;
	while (T--) {
		fin >> x >> y >> z;
		fout << dp[x][y][z] << "\n";
	}
}