#include <fstream>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

ifstream fin("drive.inp");
ofstream fout("drive.out");

int dp[101][101][202][2]; // [r][c][rotation time][direction] => (r,c) 위치에서 회전수가 rotation time 일 때 최소 fuel
int hor[101][101]; // fuel of horizontal segment
int ver[101][101]; // fuel of vertical segment

// hor, ver 배열 입력받음
void input(int m, int n) { 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			fin >> hor[i][j];
		}
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			fin >> ver[i][j];
		}
	}
}

// dp INF 값으로 초기화 및 1번이라도 회전하면 갈 수 없는 부분 초기화
void init(int m, int n) { 
	int max_turn = max(m, n) * 2; // 회전 수 상한 값
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < max_turn; k++) {
				dp[i][j][k][0] = dp[i][j][k][1] = INF;
			}
		}
	}
	dp[0][0][0][0] = dp[0][0][0][1] = 0; // (0,0)
	for (int i = 1; i < n; i++) { // [0][~]
		dp[0][i][0][0] = dp[0][i - 1][0][0] + hor[0][i - 1];
	}
	for (int i = 1; i < m; i++) { // [~][0]
		dp[i][0][0][1] = dp[i - 1][0][0][1] + ver[i - 1][0];
	}
}

void make_dp(int m, int n) {
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			int max_turn = max(i, j) * 2;
			for (int k = 1; k < max_turn; k++) {
				// [i][j][k][0](오른쪽) : ㄴ, ㅡ 방향 (회전하는 경우, 회전하지 않는 경우)
				dp[i][j][k][0] = min(dp[i][j - 1][k - 1][1], dp[i][j - 1][k][0]) + hor[i][j - 1];
				// [i][j][k][1](아래) : ㄱ, ㅣ 방향
				dp[i][j][k][1] = min(dp[i - 1][j][k - 1][0], dp[i - 1][j][k][1]) + ver[i - 1][j];
			}
		}
	}
}

// 주어진 fuel 값을 만족하는 최소 회전 수를 찾음
int find(int m, int n, int fuel, int time) {
	int max_turn = max(n, m) * 2;
	for (int k = 0; k < max_turn; k++) {
		if (dp[m - 1][n - 1][k][0] <= fuel || dp[m - 1][n - 1][k][1] <= fuel) {
			return time * (m - 1 + n - 1) + k;
		}
	}
	return -1;
}

int main() {
	int T, M, N, L, G;
	fin >> T;
	while (T--) {
		fin >> M >> N >> L >> G;
		input(M, N);
		init(M, N);
		make_dp(M, N);
		int result = find(M, N, G, L);
		fout << result << "\n";
	}
}