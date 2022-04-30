#include <iostream>
#include <string>
using namespace std;

int main() {
	string inp, num = "";
	int result = 0, isMinus = 0;
	cin >> inp;
	for (int i = 0; i <= inp.size(); i++) {
		if (inp[i] == '+' || inp[i] == '-' || i == inp.size()) {
			if (isMinus) {
				result -= stoi(num);
				num = "";
			}
			else {
				result += stoi(num);
				num = "";
			}
		}
		else num += inp[i];
		if (inp[i] == '-') isMinus = 1;
	}
	cout << result << endl;
}