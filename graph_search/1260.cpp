#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int connect[1001][1001];
int visit[1001];
int inQueue[1001];
int n, m, v;

void clear() {
	for (int i = 0; i <= 1000; i++) {
		visit[i] = 0;
	}
}

void dfs(int root) {
	visit[root] = 1;
	cout << root << " ";
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			if (connect[root][i]) {
				dfs(i);
			}
		}
	}
}

void bfs(int root) {
	visit[root] = 1;
	cout << root << " ";
	for (int i = 1; i <= n; i++) {
		int t = 0;
		if (!visit[i]) {
			if (connect[root][i]) {
				if (!inQueue[i]) {
					inQueue[i] = 1;
					q.push(i);
				}	
			}
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		bfs(tmp);
	}
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		connect[s][e] = 1;
		connect[e][s] = 1; // ¾ç¹æÇâ
	}

	dfs(v);
	clear();

	cout << endl;

	bfs(v);
	clear();
}