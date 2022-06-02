#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int alpha[26];

int main() {
	int n, sum = 0, num = 9;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int digit = 1;
		for (int j = str.length() - 1; j >= 0; j--) {
			alpha[str[j]-'A'] += digit;
			digit *= 10;
		}
	}
	sort(alpha, alpha + 26, greater<int>());
	for (int i = 0; i < 26; i++) {
		sum += alpha[i] * num;
		num--;
	}
	cout << sum;
}