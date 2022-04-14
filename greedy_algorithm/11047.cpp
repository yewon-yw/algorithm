#include <iostream>
using namespace std;
int arr[10];

int main() {
	int N, K, count = 0;
	int* pointer = arr;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] <= K) {
			pointer = &arr[i];
		}
	}
	while (K / *pointer >= 0) {
		if (K / *pointer == 0) {
			if (pointer != arr) pointer--;
			else break;
			continue;
		}
		K -= *pointer;
		count++;
	}
	cout << count;
}