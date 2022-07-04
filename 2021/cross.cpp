#include <iostream>
#include <fstream>
using namespace std;

int first[10000];
int second[10000];

ifstream fin("cross.inp");
ofstream fout("cross.out");

int main() {
	int T, N, num;
	fin >> T;
	for (int i = 1; i <= T; i++) {
		int cnt = 0;
		int visit[10000] = { 0, };
		fin >> N;
		for (int j = 0; j < N; j++) fin >> first[j];
		for (int j = 0; j < N; j++) fin >> second[j];
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				num = second[k];
				if (first[j] == num) {
					visit[num - 1] = 1;
					break;
				}
				else if (!visit[num - 1]) cnt++;
			}
		}
		fout << "Case " << i << ": " << cnt << "\n";
	}
}
