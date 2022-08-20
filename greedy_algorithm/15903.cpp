#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<>> q;

int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t;
		q.push(t);
	}
	long long int tmp, sum = 0;
	for (int i = 0; i < m; i++) {
		tmp = q.top();
		q.pop();
		tmp += q.top();
		q.pop();
		q.push(tmp);
		q.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		sum += q.top();
		q.pop();
	}
	cout << sum << "\n";
}