#include <iostream>
#include <vector>
using namespace std;
vector<int> answer[11];
int b[1024];
int k, m = 1;

void print() {
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

void rec(int s, int e, int depth) {
	if (s == e) {
		answer[depth].push_back(b[s]);
		return;
	}
	int m = (s + e) / 2;
	answer[depth].push_back(b[m]);
	rec(s, m - 1, depth + 1);
	rec(m + 1, e, depth + 1);
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) m *= 2;
	for (int i = 0; i < m - 1; i++) cin >> b[i];
	rec(0, m - 2, 1);
	print();
}