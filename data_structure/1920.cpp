#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int n, m;

void bin(int t) {
	int start = 0;
	int end = n - 1;
	int mid = (start + end) / 2;
	while (start <= end) {
		if (arr[mid] == t) {
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] < t) start = mid + 1;
		else end = mid - 1;
		mid = (start + end) / 2;
	}
	cout << 0 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		bin(t);
	}
}