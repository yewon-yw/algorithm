#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("spinslide.inp");
ofstream fout("spinslide.out");

char board[100][100];
char spin[100][100];

void spin_slide(int N, int M) {
	while (M--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				spin[i][j] = board[N - j - 1][i];
			}
		}
		for (int i = 0; i < N; i++) {
			deque<char> slide;
			for (int j = 0; j < N; j++) {
				char input = spin[j][i];
				if (input == '.') slide.push_front(input);
				else slide.push_back(input);
			}
			for (int j = 0; j < N; j++) {
				board[j][i] = slide.at(j);
			}
		}
	}
}

int main() {
	int T, N, M;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fin >> board[i][j];
			}
		}
		spin_slide(N, M);
		fout << "Case #" << t << ":" << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fout << board[i][j];
			}
			fout << "\n";
		}
		fout << "\n";
	}
}