#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
vector<int> arr;
vector<int> most;
int cnt[8001];

int main() {
	int n, t, sum = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		arr.push_back(t);
		cnt[t + 4000]++;
		sum += t;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 8001; i++) {
		if (cnt[max] < cnt[i]) max = i;
	}
	for (int i = 0; i < 8001; i++) {
		if (cnt[max] == cnt[i]) most.push_back(i);
	}
	if (most.size() >= 2) max = most.at(1);
	printf("%.0f\n", floor((double)sum / n + 0.5));
	printf("%d\n", arr.at(n / 2));
	printf("%d\n", max - 4000);
	printf("%d\n", arr.back() - arr.front());
}