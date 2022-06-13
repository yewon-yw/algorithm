#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		else return a > b;
	}
};

int main() {
	priority_queue<int, vector<int>, cmp> q;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (!x) {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else q.push(x);
	}
}