#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[100001];
queue<int> q;
int visit[100001];
int order[100001];

int main() {
	int N, M, R, u, v, cnt = 1;
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(g[i].begin(), g[i].end());
	}
	q.push(R);
	visit[R] = 1;
	while (!q.empty()) {
		int n = q.front();
		order[n] = cnt++;
		for (int i = 0; i < g[n].size(); i++) {
			int k = g[n].at(i);
			if (!visit[k]) {
				q.push(k);
				visit[k] = 1;
			}
		}
		q.pop();
	}
	for (int i = 1; i <= N; i++) {
		cout << order[i] << "\n";
	}
}