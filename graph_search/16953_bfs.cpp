#include <iostream>
#include <queue>
using namespace std;
queue<pair<long long, long long>> q;

int main() {
	long long a, b;
	cin >> a >> b;
	q.push(make_pair(a, 1));
	while (!q.empty()) {
		pair < long long, long long > node = q.front();
		q.pop();
		if (node.first == b) {
			cout << node.second;
			return 0;
		}
		if (b >= node.first * 2) q.push(make_pair(node.first * 2, node.second + 1));
		if (b >= node.first * 10 + 1) q.push(make_pair(node.first * 10 + 1, node.second + 1));
	}
	cout << -1;
	return 0;
}