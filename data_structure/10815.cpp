#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
vector<int> arr;
int main() {
	int N, M, t;
	cin >> N;
	while (N--) {
		scanf("%d", &t);
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	while (M--) {
		scanf("%d", &t);
		int start = 0;
		int end = arr.size() - 1;
		int mid = (start + end) / 2;
		while (1) {
			if (arr.at(mid) == t) {
				printf("1 ");
				break;
			}
			if (arr.at(mid) < t) {
				start = mid;
				mid += (end - mid + 1) / 2;
			}
			else {
				end = mid;
				mid -= (mid - start + 1) / 2;
			}
			if (mid == end || mid == start) {
				printf("0 ");
				break;
			}
		}
	}
}