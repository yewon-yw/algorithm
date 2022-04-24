#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}	
		}
		else if (cmd == "size") {
			cout << q.size() << endl;
		}
		else if (cmd == "empty") {
			cout << (int)q.empty() << endl;
		}
		else if (cmd == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else { // back
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
}