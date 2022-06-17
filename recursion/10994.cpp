#include <iostream>
using namespace std;

void rec(int i, int j, int k, int s) {
	if (i == s && j >= s && j <= s + k - 3) cout << " ";
	else if (i >= s && i <= s + k - 3 && j == s) cout << " ";
	else if (i == s + k - 3 && j >= s && j <= s + k - 3) cout << " ";
	else if (i >= s && i <= s + k - 3 && j == s + k - 3) cout << " ";
	else if (k != 1) rec(i, j, k - 4, s + 2);
	else cout << "*";
}

int main() {
	int n, k = 1;
	cin >> n;
	for (int i = 1; i < n; i++) k += 4;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			rec(i, j, k, 1);
		}
		cout << "\n";
	}
}
