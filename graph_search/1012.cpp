#include <iostream>
using namespace std;
int visit[52][52];
int field[52][52];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int T, X, Y, K;

void clear() {
	for (int i = 1; i < 51; i++) {
		for (int j = 1; j < 51; j++) {
			visit[i][j] = 0;
			field[i][j] = 0;
		}
	}
}

void dfs(int x,int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xp = x + dx[i]; 
		int yp = y + dy[i]; 
		if (field[xp][yp] && !visit[xp][yp]) dfs(xp, yp);
	}
}

int main() {
	cin >> T;
	while (T--) {
		int a, b, cnt = 0;
		cin >> X >> Y >> K;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			field[a + 1][b + 1] = 1;
		}
		for (int i = 1; i <= X; i++) {
			for (int j = 1; j <= Y; j++) {
				if (field[i][j] && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
		clear();
	}
}