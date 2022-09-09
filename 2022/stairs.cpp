#include <fstream>
using namespace std;

ifstream fin("stairs.inp");
ofstream fout("stairs.out");

int main() {
	int t, m, f, n;
	fin >> t;
	while (t--) {
		fin >> m >> f >> n;
		int cnt = 0, remain = 0;
		n -= (f - 1);
		cnt = n / (m - 1);
		remain = n % (m - 1);
		if (!remain&& f != 1) cnt++;
		if (remain) {
			cnt++;
			if (f + remain > m) cnt++;
		}
		fout << cnt << "\n";
	}
}