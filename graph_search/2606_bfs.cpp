#include <iostream>
#include <queue>
using namespace std;
int connect[101][101];
int visit[101];
queue<int> q;

int main() {
	int n, m, s, e, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		connect[s][e] = 1;
		connect[e][s] = 1;
	}
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int t = q.front();
		for (int i = 1; i <= n; i++) {
			if (connect[t][i] && !visit[i]) {
				cnt++;
				q.push(i);
				visit[i] = 1;
			}
		}
		q.pop();
	}
	cout << cnt << "\n";
}