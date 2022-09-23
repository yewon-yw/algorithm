#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("grid.inp");
ofstream fout("grid.out");

bool check(int n, int m, int k, int p[100000]) {
	int line = n;
	int cnt[100000];
	for (int i = 0; i < k; i++) {
		cnt[i] = p[i] / m;
	}
	for (int i = 0; i < k; i++) {
		if (cnt[i] >= 2 && line >= 2) {
			line -= 2;
		}
		if (line == 0) break;
	}
	if (line >= 1) {
		for (int i = 0; i < k; i++) {
			if (cnt[i] >= 3) {
				line -= cnt[i] - 2;
			}
			if (line <= 0) break;
		}
	}
	if (line <= 0) return true;
	else return false;
}

int main() {
	int t, n, m, k;
	fin >> t;
	while (t--) {
		fin >> n >> m >> k;
		int paint[100000];
		for (int i = 0; i < k; i++) {
			fin >> paint[i];
		}
		sort(paint, paint + k, greater<int>());
		bool res = check(n, m, k, paint) || check(m, n, k, paint);
		if (res) fout << "Yes" << "\n";
		else fout << "No" << "\n";
	}
}