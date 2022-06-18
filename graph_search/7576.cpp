#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int, int, int>> q;
int box[1001][1001];
int visit[1001][1001];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N, M, day = 0;

void check() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0) continue;
			cnt++;
		}
	}
	if (cnt == N * M) cout << day << "\n";
	else cout << -1 << "\n";
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push(make_tuple(i, j, 0));
		}
	}
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (!visit[nx][ny] && box[nx][ny] == 0) {
				visit[nx][ny] = 1;
				box[nx][ny] = 1;
				q.push(make_tuple(nx, ny, d + 1));
			}
		}
		day = d;
	}
	check();
}