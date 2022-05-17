#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> num;
map<int, string> name;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		name[i] = s;
		num[s] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (isdigit(s[0])) cout << name[stoi(s)] << "\n";
		else cout << num[s] << "\n";
	}
}