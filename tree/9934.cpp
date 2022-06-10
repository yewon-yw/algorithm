#include <iostream>
using namespace std;
int b[1024];
int k, m = 1;

void print(int n) {
	if (n == 0) return;
	int tmp = n / 2;
	while (tmp < m - 1) {
		cout << b[tmp] << " ";
		tmp += n + 1;
	}
	cout << "\n";
	print(n / 2);
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) m *= 2;
	for (int i = 0; i < m - 1; i++) cin >> b[i];
	print(m - 1);
}