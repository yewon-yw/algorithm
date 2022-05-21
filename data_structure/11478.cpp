#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> s;
int main() {
	string str;
	cin >> str;
	for (int i = 1; i <= str.size(); i++) {
		for (int j = 0; j < str.size(); j++) {
			s.insert(str.substr(j, i));
		}
	}
	cout << s.size();
}