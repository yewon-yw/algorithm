#include <iostream>
using namespace std;

int main() {
	int l, p, v, res, i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (!l && !p && !v) break;
		res = v / p * l;
		res += v % p > l ? l : v % p;
		cout << "Case " << i++ << ": " << res << "\n";
	}
}