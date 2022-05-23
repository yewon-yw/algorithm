#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string str;
	while (1) {
		stack<char> s;
		int right = 1;
		getline(cin, str);
		if (str == ".") return 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '('|| str[i] == '[') s.push(str[i]);
			if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else right = 0;
			}
			if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else right = 0;
			}
		}
		if (!right || !s.empty()) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}