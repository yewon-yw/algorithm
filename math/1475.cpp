#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int cnt[10];

int main() {
	int maxv = 0;
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		cnt[n[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		maxv = max(maxv, cnt[i]);
	}
	maxv = max(maxv, (cnt[6] + cnt[9] + 1) / 2);
	cout << maxv << "\n";
}