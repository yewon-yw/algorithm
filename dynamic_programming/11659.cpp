#include <iostream>
using namespace std;
int acc[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		acc[i] = acc[i - 1] + t;
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << acc[e] - acc[s - 1] << "\n";
	}
}
