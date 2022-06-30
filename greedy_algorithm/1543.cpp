#include <iostream>
#include <string>
using namespace std;

int main() {
	string doc, word;
	getline(cin, doc);
	getline(cin, word);
	int pos = word.size()*(-1), cnt = 0;
	while (1) {
		pos = doc.find(word, pos + word.size());
		if (pos == string::npos) break;
		cnt++;
	}
	cout << cnt;
}