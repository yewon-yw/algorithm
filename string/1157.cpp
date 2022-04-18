#include <iostream>
using namespace std;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int aCount[26];

int main() {
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		input[i] = toupper(input[i]);
		aCount[input[i] - 'A']++;
	}
	int maxIndex, maxValue = 0;
	bool isOnly = true;
	for (int i = 0; i < 26; i++) {
		if (aCount[i] > maxValue) {
			maxValue = aCount[i];
			maxIndex = i;
			isOnly = true;
		}
		else if (aCount[i] == maxValue) {
			isOnly = false;
		}
	}
	if (isOnly == false) {
		cout << "?" << endl;
		return 0;
	}
	cout << alphabet[maxIndex] << endl;
}