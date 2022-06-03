#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		if (str[i] == ')') {
			s.pop();
			if (str[i - 1] == '(') cnt += s.size();
			else cnt++;
		}
	}
	cout << cnt;
}