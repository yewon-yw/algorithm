#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int color[1001][3];

int main() {
	int n, r, g, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		color[i][0] = min(color[i - 1][1] + r, color[i - 1][2] + r);
		color[i][1] = min(color[i - 1][0] + g, color[i - 1][2] + g);
		color[i][2] = min(color[i - 1][0] + b, color[i - 1][1] + b);
	}
	cout << min({ color[n][0], color[n][1], color[n][2] }) << "\n";
}