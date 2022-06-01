#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main() {
	int n, k, t;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i <= k; i++) {
			t = q.front();
			q.pop();
			if (i == k) {
				cout << t;
				if (q.size())cout << ", ";
				break;
			}
			q.push(t);
		}
	}
	cout << ">";
}