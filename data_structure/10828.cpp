#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	string cmd;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << endl;
		}
		else if (cmd == "empty") {
			cout << (int)s.empty() << endl;
		}
		else { //top
			if (s.empty()) cout << -1 << endl;
			else cout << s.top() << endl;
		}
	}
}
