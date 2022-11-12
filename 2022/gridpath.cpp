#include <fstream>
#include <stack>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

ifstream fin("gridpath.inp");
ofstream fout("gridpath.out");

stack<pair<int, int>> result;
queue<pair<int, int>> q;
int grid[200][200], dp[200][200];
int N, M, noPath = 0;

void find_min_cost() {
	int inp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fin >> inp;
			if (inp == -1) grid[i][j] = MAX;
			else grid[i][j] = inp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int top, left;
			if (grid[i][j] == MAX) {
				dp[i][j] = MAX;
				continue;
			}
			if (i == 0 && j == 0) {
				top = 0;
				left = 0;
			}
			else if (i == 0) {
				top = MAX;
				left = dp[i][j - 1];
			}
			else if (j == 0) {
				left = MAX;
				top = dp[i - 1][j];
			}
			else {
				top = dp[i - 1][j];
				left = dp[i][j - 1];
			}
			if (top == MAX) {
				dp[i][j] = left + grid[i][j];
				if (left == MAX) dp[i][j] = MAX;
			}
			else if (left == MAX) {
				dp[i][j] = top + grid[i][j];
				if (top == MAX) dp[i][j] = MAX;
			}
			else dp[i][j] = min(top, left) + grid[i][j];
		}
	}
}

void find_path() {
	result.push(make_pair(N - 1, M - 1));
	q.push(make_pair(N - 1, M - 1));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int i = p.first, j = p.second;
		int top = MAX, left = MAX;
		if (i == 0 && j == 0) {
			if (!q.empty()) noPath = 1;
			break;
		}
		if (i != 0) top = dp[i - 1][j];
		if (j != 0) left = dp[i][j - 1];
		else if (top == MAX) {
			q.push(make_pair(i, j - 1));
			result.push(make_pair(i, j - 1));
			continue;
		}
		else if (left == MAX) {
			q.push(make_pair(i - 1, j));
			result.push(make_pair(i - 1, j));
			continue;
		}
		if (top <= left && i - 1 >= 0) {
			q.push(make_pair(i - 1, j));
			result.push(make_pair(i - 1, j));
		}
		else if (j - 1 >= 0) {
			q.push(make_pair(i, j - 1));
			result.push(make_pair(i, j - 1));
		}
	}
}

void print() {
	if (dp[N - 1][M - 1] == MAX) {
		fout << "No path.\n";
		return;
	}
	fout << dp[N - 1][M - 1] << "\n";
	while (!result.empty()) {
		fout << "(" << result.top().first << " " << result.top().second << ")\n";
		result.pop();
	}
}

int main() {
	fin >> N >> M;
	find_min_cost();
	find_path();
	print();
}
