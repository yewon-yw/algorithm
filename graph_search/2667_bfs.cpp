#include <iostream>
#include <queue>
#pragma warning (disable:4996)

using namespace std;
int map[27][27];
int visit[27][27];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> count_home;
int N, x, y, address = 0, home = 1;

void find() {
	int stop = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] && !visit[i][j]) {
				x = i, y = j;
				stop = 1;
				break;
			}
			else {
				x = -1, y = -1;
			}
		}
		if (stop) break;
	}
	return;
}

void bfs() {
	while (!q.empty()) {
		int nx, ny;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (map[nx][ny] && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				home++;
			}
		}
		if (q.empty()) address++;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	while (1) {
		find();
		if (x == -1 && y == -1) break;
		q.push(make_pair(x, y));
		visit[x][y] = 1;
		home = 1;
		bfs();
		count_home.push(home);
	}
	cout << address << "\n";
	while (!count_home.empty()) {
		cout << count_home.top() << "\n";
		count_home.pop();
	}
}