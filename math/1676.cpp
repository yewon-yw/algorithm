#include <iostream>
#include <string>
using namespace std;

string add(string a, string b) {
	int size = a.size() < b.size() ? b.size() : a.size();
	if (a.size() < b.size()) {
		for (int i = a.size(); i < size; i++) a = "0" + a;
	}
	else {
		for (int i = b.size(); i < size; i++) b = "0" + b;
	}
	int c = 0, r = 0;
	string result = "";
	for (int i = size - 1; i >= 0; i--) {
		r = a[i] + b[i] - 96 + c;
		c = r / 10;
		r %= 10;
		result = to_string(r) + result;
	}
	if (c != 0) result = to_string(c) + result;
	return result;
}

string mul(string a, string b) {
	string next = "", op = "";
	for (int i = b.size() - 1; i >= 0; i--) {
		int r = 0, c = 0;
		string result = "";
		for (int j = a.size() - 1; j >= 0; j--) {
			r = (a[j] - 48)*(b[i] - 48) + c;
			c = r / 10;
			r %= 10;
			result = to_string(r) + result;
		}
		if (c != 0) result = to_string(c) + result;
		result += next;
		next += "0";
		op = add(op, result);
	}
	return op;
}

int check(string res) {
	int i = res.size() - 1, cnt = 0;
	while (res[i] == '0') {
		cnt++;
		i--;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	string res = "1";
	for (int i = 2; i <= n; i++) {
		res = mul(res, to_string(i));
	}
	cout << check(res) << "\n";
}
