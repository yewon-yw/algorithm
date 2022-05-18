#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, t;
	cin >> n;
	while (n--) {
		cin >> t;
		card.push_back(t);
	}
	sort(card.begin(), card.end());
	cin >> m;
	while (m--) {
		cin >> t;
		int lb = lower_bound(card.begin(), card.end(), t) - card.begin();
		int ub = upper_bound(card.begin(), card.end(), t) - card.begin();
		cout << ub - lb << " ";
	}
}