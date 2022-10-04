#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("permutation.inp");
ofstream fout("permutation.out");

pair<int, int> p[1000];
int visit[1000];
int T, N;

int find_max_idx(int s, int e) {
	int midx = s;
	for (int i = s; i <= e; i++) {
		if (!visit[i] && p[midx].first < p[i].first) {
			midx = i;
		}
	}
	return midx;
}

void rec(int s, int e, int depth) {
	int midx = find_max_idx(s, e);
	if (visit[midx]) return;
	visit[midx] = 1;
	p[midx].second = depth;
	rec(s, midx - 1, depth + 1);
	rec(midx + 1, e, depth + 1);
}

void print() {
	for (int i = 0; i < N; i++) {
		fout << p[i].second << " ";
	}
	fout << "\n";
}

int main() {
	fin >> T;
	while (T--) {
		fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> p[i].first;
			p[i].second = 0;
			visit[i] = 0;
		}
		rec(0, N - 1, 0);
		print();
	}
}