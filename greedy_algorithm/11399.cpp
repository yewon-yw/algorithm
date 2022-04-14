#include <iostream>
#include <algorithm>
using namespace std;
int p[1000];

int main() {
	int N, min = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j) min += p[j];
		}
	}
	cout << min;
}