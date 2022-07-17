#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> graph[100001];
int visit[100001];
int order[100001];
stack<int> s;

int main() {
	int n, m, r, u, v, cnt = 1;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	s.push(r);
	while (!s.empty()) {
		int n = s.top();
		s.pop();
		if (visit[n]) continue;
		visit[n] = 1;
		order[n] = cnt++;
		for (int i = 0; i < graph[n].size(); i++) {
			s.push(graph[n].at(i));
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << order[i] << "\n";
	}
}