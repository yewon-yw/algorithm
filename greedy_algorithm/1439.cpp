#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int zcnt = 0, ocnt = 0;
	if (str[0] == '0') zcnt++;
	else ocnt++;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			if (str[i] == '0') zcnt++;
			else ocnt++;
		}
	}
	cout << (zcnt < ocnt ? zcnt : ocnt) << "\n";
}