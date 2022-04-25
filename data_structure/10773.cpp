#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k, result = 0;
	cin >> k;
	stack<int> cash;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) cash.pop();
		else cash.push(tmp);
	}
	while (!cash.empty()) {
		result += cash.top();
		cash.pop();
	}
	cout << result << endl;
}