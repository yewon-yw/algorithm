#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> mp;
int main() {
	int n, m, cnt = 0;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp.insert({ s,true }); // mp[s]=true;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (mp[s]) cnt++;
	}
	cout << cnt << "\n";
}
