#include <iostream>
#include <algorithm>
using namespace std;
int minv[2] = { 10000,10000 };
int price[2];

int main() {
	int n, m, result;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> price[0] >> price[1];
		minv[0] = min(minv[0], price[0]);
		minv[1] = min(minv[1], price[1]);
	}
	result = min({ (n / 6 + 1)*minv[0], (n / 6)*minv[0] + (n % 6)*minv[1], n*minv[1] });
	cout << result;
}