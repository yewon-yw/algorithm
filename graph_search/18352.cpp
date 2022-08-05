#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> road[300001];
vector<int> res;
queue<pair<int,int>> q;
int visit[300001];

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
	}
	q.push(make_pair(x, 0));
	visit[x] = 1;
	while (!q.empty()) {
		int node = q.front().first;
		int depth = q.front().second;
		q.pop();
		for (auto i : road[node]) {
			if (!visit[i]) {
				if (depth + 1 == k) res.push_back(i);
				q.push(make_pair(i, depth + 1));
				visit[i] = 1;
			}
		}
	}
	sort(res.begin(), res.end());
	if (res.empty()) {
		cout << -1 << "\n";
		return 0;
	}
	for (auto i : res) {
		cout << i << "\n";
	}
}