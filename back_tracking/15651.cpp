#include <iostream>
using namespace std;
int arr[7];
int N, M;

void print() {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void rec(int m) {
	if (m == M) {
		print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[m] = i;
		rec(m + 1);
	}
}

int main() {
	cin >> N >> M;
	rec(0);
}