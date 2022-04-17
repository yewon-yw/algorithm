#include <iostream>
using namespace std;
int btn[3] = { 300,60,10 };
int btnCount[3];

int main() {
	int T, index = 0;
	cin >> T;
	while (T > 0) {
		if (btn[index] <= T) {
			T -= btn[index];
			btnCount[index]++;
		}
		else {
			index++;
			if (index > 2) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << btnCount[i] << " ";
	}
}