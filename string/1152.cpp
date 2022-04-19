#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int count = 0;
	stringstream ss;
	string input;
	getline(cin, input);
	ss.str(input);
	while (ss >> input) count++;
	cout << count;
}