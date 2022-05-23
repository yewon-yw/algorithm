#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, s, e, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		arr.push_back(make_pair(e, s));
	}
	sort(arr.begin(), arr.end());
	e = arr.front().first;
	for (int i = 1; i < n; i++) {
		if (e <= arr.at(i).second) {
			cnt++;
			e = arr.at(i).first;
		}
	}
	cout << cnt << "\n";
}