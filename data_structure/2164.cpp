#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> card;
	for (int i = 1; i <= n; i++) {
		card.push(i);
	}
	if (n == 1) cout << card.front() << endl;
	else {
		while (!card.empty()) {
			card.pop();
			if (card.size() == 1) {
				cout << card.front() << endl;
				break;
			}
			else {
				int tmp = card.front();
				card.pop();
				card.push(tmp);
			}
		}
	}
}