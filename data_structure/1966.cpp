#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T, N, lo, num;
	cin >> T;
	while (T--) {
		priority_queue<int, vector<int>> f;
		queue<pair<int, int>> q;
		int cnt = 1;
		cin >> N >> lo;
		for (int i = 0; i < N; i++) {
			cin >> num;
			f.push(num);
			q.push(make_pair(i, num));
		}
		while (1) {
			if (f.top() == q.front().second) {
				if (q.front().first == lo) break;
				q.pop();
				f.pop();
				cnt++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << "\n";
	}
}