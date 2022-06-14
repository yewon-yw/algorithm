#include <iostream>
using namespace std;
int land[52][52];
int visit[52][52];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { -1,-1,-1,0,1,1,1,0 };

void dfs(int x,int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny] && land[nx][ny]) dfs(nx, ny);
	}
}

void clear() {
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			visit[i][j] = 0;
			land[i][j] = 0;
		}
	}
}

int main() {
	int w, h;
	while (1) {
		int cnt = 0;
		cin >> w >> h;
		if (!w && !h) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> land[i][j];
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!visit[i][j] && land[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		clear();
		cout << cnt << "\n";
	}
}