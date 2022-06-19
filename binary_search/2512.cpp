#include <iostream>
#include <algorithm>
using namespace std;
int req[10000];
int n, m, result, sum;

int cal(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (mid < req[i]) sum += mid;
		else sum += req[i];
	}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> req[i];
		sum += req[i];
	}
	sort(req, req + n);
	cin >> m;
	if (sum > m) {
		int start = 1;
		int end = req[n - 1];
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			int s = cal(mid);
			if (s <= m) {
				result = mid;
				start = mid + 1;
			}
			else end = mid - 1;
		}
		cout << result;
		return 0;
	}
	else cout << req[n - 1];
}