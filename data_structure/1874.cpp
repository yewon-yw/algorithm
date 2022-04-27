#pragma warning (disable:4996)
#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<int> s;
string op;

int main() {
	int n, index = 0, num = 1, inp;
	scanf("%d", &n);
	while (index < n) {
		scanf("%d", &inp);
		while (inp >= num) {
			s.push(num);
			op += "+\n";
			num++;
		}
		if (s.top() == inp) {
			s.pop();
			op += "-\n";
			index++;
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	cout << op;
}