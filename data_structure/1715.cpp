#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	int result = 0;
	while (q.size() != 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		result += a + b;
		q.push(a + b);
	}
	cout << result << endl;
}