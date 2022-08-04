#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> pipe;

int main() {
	int n, l, p, cnt = 1;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> p;
		pipe.push_back(p);
	}
	sort(pipe.begin(), pipe.end());
	int tape = pipe.at(0) + l;
	for (int i = 0; i < n; i++) {
		if (pipe.at(i) < tape) continue;
		else {
			tape = pipe.at(i) + l;
			cnt++;
		}
	}
	cout << cnt << "\n";
}