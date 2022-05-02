#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
int miro[102][102];
int dis[102][102];
int visit[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}
	dis[1][1] = 1;
	visit[1][1] = 1;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visit[nx][ny] && miro[nx][ny]) {
				visit[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
	cout << dis[N][M] << "\n";
}