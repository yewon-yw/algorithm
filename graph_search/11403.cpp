#include <iostream>
using namespace std;
int graph[100][100];
int visit[100][100];
int n;

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < n; i++) {
		if (graph[y][i]) {
			graph[x][i] = 1;
			if (!visit[x][i]) dfs(x, i);
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] && !visit[i][j]) dfs(i, j);
		}
	}
	print();
}