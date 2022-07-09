#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("bowling.inp");
ofstream fout("bowling.out");

int input(int frame[10][2]) {
	int bonus = 0;
	for (int i = 0; i < 9; i++) {
		fin >> frame[i][0];
		if (frame[i][0] == 10)continue;
		fin >> frame[i][1];
	}
	fin >> frame[9][0] >> frame[9][1];
	if (frame[9][0] + frame[9][1] >= 10) fin >> bonus;
	return bonus;
}

int strike(int frame[10][2],int n) {
	int bonus = 0;
	bonus += frame[n + 1][0] + frame[n + 1][1];
	if (n + 2 < 10 && frame[n + 1][0] == 10) bonus += frame[n + 2][0];
	return bonus;
}

int spare(int frame[10][2], int n) {
	int bonus = 0;
	bonus += frame[n + 1][0];
	return bonus;
}

int main() {
	int T;
	fin >> T;
	while (T--) {
		int frame[10][2] = { 0, }, bonus = 0, score = 0;
		bonus=input(frame);
		for (int i = 0; i < 9; i++) {
			score += (frame[i][0] + frame[i][1]);
			if (frame[i][0] == 10) score += strike(frame, i);
			else if (frame[i][0] + frame[i][1] == 10) score += spare(frame, i);
		}
		score += (frame[9][0] + frame[9][1] + bonus);
		fout << score << "\n";
	}
	fin.close();
	fout.close();
}