#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

vector<int> arr;
vector<int> nrp;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		arr.push_back(t);
		nrp.push_back(t);
	}
	sort(nrp.begin(), nrp.end());
	nrp.erase(unique(nrp.begin(), nrp.end()), nrp.end());
	for (int i = 0; i < n; i++) {
		int result = lower_bound(nrp.begin(), nrp.end(), arr.at(i)) - nrp.begin();
		printf("%d ", result);
	}
}