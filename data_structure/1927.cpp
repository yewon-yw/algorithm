#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, inp;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &inp);
		if (inp == 0) {
			if (q.empty()) printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else q.push(inp);
	}
}