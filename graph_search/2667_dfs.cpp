#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int map[27][27];
int visit[27][27];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, home, address = 0, x, y;
vector<int> count_home;

void find() {
	int stop = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] && !visit[i][j]) {
				x = i, y = j;
				stop = 1;
				break;
			}
			else x = -1, y = -1;
		}
		if (stop) break;
	}
	return;
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny] && map[nx][ny]) {
			dfs(nx, ny);
			home++;
		}
	}
	return;
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
		home = 1;
		dfs(x, y);
		address++;
		count_home.push_back(home);
	}
	cout << address << "\n";
	sort(count_home.begin(), count_home.end());
	while (!count_home.empty()) {
		cout << count_home.front() << endl;
		count_home.erase(count_home.begin());
	}
}