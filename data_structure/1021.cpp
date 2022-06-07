#include <iostream>
#include <deque>
using namespace std;
deque<int> q;

int find_front(int num) {
	for (int i = 0; i < q.size(); i++) {
		if (q.at(i) == num) return i;
	}
	return 0;
}
int find_back(int num) {
	for (int i = q.size() - 1; i >= 0; i--) {
		if (q.at(i) == num) return q.size() - i;
	}
	return 0;
}

int main() {
	int n, m, t, result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push_back(i);
	for (int i = 0; i < m; i++) {
		cin >> t;
		int f = find_front(t);
		int b = find_back(t);
		if (f <= b) {
			result += f;
			while (f--) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			result += b;
			while (b--) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
		q.pop_front();
	}
	cout << result;
}