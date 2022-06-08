#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int visit[9];
int N, M;

void print() {
	for (int i = 0; i < p.size(); i++) {
		cout << p.at(i) << " ";
	}
	cout << "\n";
}

void dfs(int n,int k) {
	if (n == M) {
		print();
		return;
	}
	for (int i = k + 1; i <= N; i++) {
		if (!visit[i]) {
			p.push_back(i);
			visit[i] = 1;
			dfs(n + 1, i);
			p.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0, 0);
}