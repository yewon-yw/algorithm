#include <iostream>
using namespace std;
pair<int, int> p[50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 0; j < n; j++) {
			if (p[i].first < p[j].first&&p[i].second < p[j].second) {
				count++;
			}
		}
		cout << count << " ";
	}
}