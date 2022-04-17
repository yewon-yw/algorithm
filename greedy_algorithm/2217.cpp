#include <iostream>
#include <algorithm>
using namespace std;
int rope[100000];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N, maxv = 0, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + N, compare);
	for (int i = 0; i < N; i++) {
		count++;
		maxv = max(rope[i] * count, maxv);
	}
	cout << maxv;
}