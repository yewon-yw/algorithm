#include <iostream>
using namespace std;
int num[100];
int prime[1001];

int main() {
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 2; i <= 1000; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = i + i; j <= 1000; j += i) {
			prime[j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (num[i] == prime[num[i]]) count++;
	}
	cout << count << endl;
}