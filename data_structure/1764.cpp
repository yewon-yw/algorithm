#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> p;
vector<string> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	string t;
	while (n--) {
		cin >> t;
		p[t] = 1;
	}
	while (m--) {
		cin >> t;
		if (p[t]) {
			cnt++;
			result.push_back(t);
		}
	}
	sort(result.begin(), result.end());
	cout << cnt << "\n";
	for (auto i : result) {
		cout << i << "\n";
	}
}
