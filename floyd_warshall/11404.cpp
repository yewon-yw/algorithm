#include <iostream>
using namespace std;
#define INF 987654321
int n, m, s, e, v;
int route[101][101];

void fw() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				route[i][j] = min(route[i][k] + route[k][j], route [i][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			route[i][j] = INF;
		}
		route[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> v;
		if (route[s][e] > v) route[s][e] = v;
	}
	
	for (int i = 0; i < n; i++) {
		fw();
	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (route[i][j] >= INF) {
				route[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << route[i][j] << " ";
		}
		cout << endl;
	}
}