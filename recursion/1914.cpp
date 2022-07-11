#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void hanoi(int start,int mid, int end, int n) {
	if (n == 0) return;
	hanoi(start, end, mid, n - 1);
	cout << start << " " << end << "\n";
	hanoi(mid, start, end, n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s = to_string(pow(2, n));
	s = s.substr(0, s.find('.'));
	cout << s << "\n";
	if (n <= 20) hanoi(1, 2, 3, n);
}