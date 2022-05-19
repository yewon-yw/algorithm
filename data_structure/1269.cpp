#include <iostream>
#include <map>
using namespace std;
map<int, pair<int, int>> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b, t;
	cin >> a >> b;
	while (a--) {
		cin >> t;
		m[t].first = 1;
	}
	while (b--) {
		cin >> t;
		m[t].second = 1;
		if (m[t].first) m.erase(t);
	}
	cout << m.size() << "\n";
}