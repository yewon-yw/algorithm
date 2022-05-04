#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, result = 0, no = 0;
	cin >> N;
	string word;
	while (N--) {
		no = 0;
		cin >> word;
		for (int i = 0; i < word.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (word[i-1] != word[i]&&word[j]==word[i]) {
					no = 1;
					break;
				}
			}
			if (no) break;
		}
		if(!no) result++;
	}
	cout << result << endl;
}