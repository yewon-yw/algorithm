#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
vector < pair<int, int> > a;

int main() {
	int T, N, count = 0;
	int minv = 100001;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			a.push_back(make_pair(tmp1, tmp2));
		}
		sort(a.begin(), a.end());
		for (int j = 0; j < a.size(); j++) {
			if (minv > a[j].second) {
				count++;
				minv = min(minv, a[j].second);
			}
		}
		printf("%d\n", count);
		a.clear();
		minv = 100001;
		count = 0;
	}
}