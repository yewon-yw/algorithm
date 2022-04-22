#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<int> s;
		string ps;
		int isVPS = 1;
		cin >> ps;
		for (int j = 0; j < ps.size(); j++) {
			if (ps[j] == '(') s.push(0);
			else {
				if (s.empty()) isVPS = 0;
				else s.pop();
			}
		}
		if (s.empty()) {
			if (isVPS) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
}