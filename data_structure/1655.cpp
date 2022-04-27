#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;

	int n;
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (maxheap.size() == 0) {
			maxheap.push(x);
		}
		else {
			if (maxheap.size() > minheap.size()) {
				minheap.push(x);
			}
			else maxheap.push(x);
			if (maxheap.top() > minheap.top()) {
				int maxtop = maxheap.top();
				int mintop = minheap.top();
				maxheap.pop();
				minheap.pop();
				maxheap.push(mintop);
				minheap.push(maxtop);
			}
		}
		cout << maxheap.top() << '\n';
	}
	return 0;
}