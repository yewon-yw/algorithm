#include <iostream>
using namespace std;
int n, m, s, e, cnt;
int connect[101][101];
int visit[101];

void dfs(int k) {
	for (int i = 1; i <= n; i++) {
		if (connect[k][i] && !visit[i]) {
			visit[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		connect[s][e] = 1;
		connect[e][s] = 1;
	}
	visit[1] = 1;
	dfs(1);
	cout << cnt << "\n";
}