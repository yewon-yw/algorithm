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
		sort(graph[i].begin(), graph[i].end(), less<>());
	}
	s.push(r);
	while (!s.empty()) {
		int k = s.top();
		s.pop();
		if (visit[k]) continue;
		visit[k] = 1;
		order[k] = cnt++;
		for (int i = 0; i < graph[k].size(); i++) {
			s.push(graph[k].at(i));
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << order[i] << "\n";
	}
}