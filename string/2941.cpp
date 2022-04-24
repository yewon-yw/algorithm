#include <iostream>
#include <string>
using namespace std;
string alphabet[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main() {
	string input;
	cin >> input;
	for (int i = 0; i < size(alphabet); i++) {
		while (1) {
			int index = input.find(alphabet[i]);
			if (index == string::npos) break;
			else input.replace(index, alphabet[i].size(), "a");
		}
	}
	cout << input.size() << endl;
}