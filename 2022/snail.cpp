#include <fstream>
using namespace std;

long long N;
long long dx[4] = { 0,1,0,-1 };
long long dy[4] = { 1,0,-1,0 };

ifstream fin("snail.inp");
ofstream fout("snail.out");

pair<long long, long long> find_range(long long a) {
	long long n = N;
	long long cnt = 0;
	while (a >= n) {
		cnt++, a -= n;
		if (n == N) {
			n--;
			continue;
		}
		if (a < n || n <= 0) break;
		cnt++, a -= n;
		n--;
	}
	return make_pair(cnt, a);
}

pair<long long, long long> find_index(pair<long long, long long> sr) {
	pair<long long, long long> result;
	long long s = sr.first / 4;
	long long r = sr.first % 4;
	switch (r) {
	case 0:
		result = make_pair(s + 1, s);
		break;
	case 1:
		result = make_pair(s + 1, N - s);
		break;
	case 2:
		result = make_pair(N - s, N - s);
		break;
	default:
		result = make_pair(N - s, s + 1);
		break;
	}

	for (long long i = 0; i < sr.second; i++) {
		result.first += dx[r];
		result.second += dy[r];
	}
	return result;
}

void snail(long long A, long long B) {
	pair<long long, long long> a, b, res_a, res_b;
	a = find_range(A);
	b = find_range(B);
	res_a = find_index(a);
	res_b = find_index(b);
	long long check = ((res_a.first - res_b.first) == (res_a.second - res_b.second)) ||
		((res_a.first - res_b.first) == (-1) * (res_a.second - res_b.second));
	if (check) fout << "YES" << "\n";
	else fout << "NO" << "\n";
}

int main() {
	int T;
	fin >> T;
	while (T--) {
		long long A, B;
		fin >> N >> A >> B;
		snail(A, B);
	}
	fin.close();
	fout.close();
}