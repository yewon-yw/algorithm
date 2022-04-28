#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int check = 0, exist = 0;
	string inp;
	cin >> inp;
	for (int i = 0; i < inp.size(); i++) {
		int tmp = (int)inp[i] - 48;
		if (!tmp) exist = 1;
		check += tmp;
	}
	if (!exist || check % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}
	sort(inp.begin(), inp.end(), greater<>());
	cout << inp << endl;
}