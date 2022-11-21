#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("mst.inp");
ofstream fout("mst.out");

vector<pair<int,pair<int, pair<int, int>>>> e; // (edge number,(w,(u,v)))
vector<pair<int, pair<int, pair<int, int>>>> f;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
vector<pair<int, pair<int, int>>> prim_e[10000]; // (w,(edge number,v))
vector<pair<int, pair<int, int>>> prim_f;
int parent[10001];
int visited[10001];


bool compare(pair<int, pair<int, pair<int, int>>> a, pair<int, pair<int, pair<int, int>>> b) {
	if (a.second.first == b.second.first) { // 가중치가 같으면
		return a.first < b.first; // edge number 작은순
	}
	return a.second.first < b.second.first; // 가중치가 작은순
}

void initial(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int find(int k) {
	if (parent[k] == k) {
		return k;
	}
	return find(parent[k]);
}

void kruskal(int n, int m) {
	initial(n);
	int index = 0, cost = 0;
	while (f.size() < n - 1) {
		pair<int, pair<int, pair<int, int>>> edge = e.at(index); // (edge number,(w,(u,v)))
		index++;
		int i = edge.second.second.first, j = edge.second.second.second;
		int p = find(i), q = find(j);
		if (p != q) {
			parent[q] = p;
			f.push_back(edge);
		}
	}
	for (auto edge : f) {
		cost += edge.second.first;
	}
	fout << "Tree edges by Kruskal algorithm: " << cost << "\n";
	for (auto edge : f) {
		fout << edge.first << "\n";
	}
}

void prim(int v) {
	visited[v] = 1;
	for (auto edge : prim_e[v]) {
		pq.push(edge);
	}
	while (!pq.empty()) {
		auto next = pq.top();
		pq.pop();
		if (!visited[next.second.second]) {
			prim_f.push_back(next);
			prim(next.second.second);
			return;
		}
	}
}

void prim_print(int v) {
	int cost = 0;
	for (auto i : prim_f) {
		cost += i.first;
	}
	fout << "Tree edges by Prim algorithm with starting vertex " << v << ": " << cost << "\n";
	for (auto i : prim_f) {
		fout << i.second.first << "\n";
	}
}

void clear(int n) {
	prim_f.clear();
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
}

int main() {
	int n, m, u, v, w;
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		fin >> u >> v >> w;
		int tu = min(u, v), tv = max(u, v);
		e.push_back(make_pair(i, make_pair(w, make_pair(tu, tv))));
		prim_e[tv].push_back(make_pair(w, make_pair(i, tu)));
		prim_e[tu].push_back(make_pair(w, make_pair(i, tv)));
	}
	sort(e.begin(), e.end(), compare);

	kruskal(n, m);

	clear(n);
	prim(0);
	prim_print(0);

	clear(n);
	prim(n / 2);
	prim_print(n / 2);

	clear(n);
	prim(n - 1);
	prim_print(n - 1);
}