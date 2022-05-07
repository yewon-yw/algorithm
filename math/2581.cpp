#include <iostream>
#include <vector>
using namespace std;
int prime[10001] = { -1,-1, };

int main() {
	for (int i = 2; i < 10001; i++) {
		prime[i] = i;
	}
	for (int i = 2; i < 10001; i++) {
		for (int j = i + i; j < 10001; j += i) {
			prime[j] = -1;
		}
	}
	int m, n, sum = 0, min;
	cin >> m >> n;
	vector<int> p;
	for (int i = m; i <= n; i++) {
		if (prime[i] != -1) p.push_back(prime[i]);
	}
	if (p.empty()) {
		cout << -1 << endl;
		return 0;
	}
	min = p.front();
	while (!p.empty()) {
		sum += p.front();
		p.erase(p.begin());
	}
	cout << sum << "\n" << min << "\n";
	return 0;
}