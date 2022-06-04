#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int T, N, k;
	cin >> T;
	while (T--) {
		string cmd, str, num = "";
		deque<int> q;
		bool reverse = false, error = false;
		cin >> cmd >> N >> str;
		for (int i = 0; i < str.size(); i++) {
			if (isdigit(str[i])) {
				num += str[i];
			}
			else {
				if (!num.empty()) {
					q.push_back(stoi(num));
					num = "";
				}
			}
		}
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') reverse = !reverse;
			else {
				if (!q.empty()) {
					if (reverse) q.pop_back();
					else q.pop_front();
				}
				else error = true;
			}
		}
		if (error) cout << "error\n";
		else {
			cout << "[";
			while (!q.empty()) {
				if (reverse) {
					k = q.back();
					q.pop_back();
				}
				else {
					k = q.front();
					q.pop_front();
				}
				cout << k;
				if (!q.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
}