#include <iostream>
using namespace std;

int main() {
	long long s, i = 1;
	cin >> s;
	while (1) {
		s -= i;
		if (s <= i) break;
		i++;
	}
	cout << i;
}