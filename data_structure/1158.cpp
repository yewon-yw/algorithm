#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			int t = q.front();
			q.pop();
			if (i == k - 1) {
				cout << t;
				if (q.size() != 0) cout << ", ";
				break;
			}
			q.push(t);
		}
	}
	cout << ">";
}