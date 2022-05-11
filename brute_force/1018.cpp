#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string chess[50];

string w[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string b[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int wb(int x, int y) { // 흰색으로 시작하는 배열로 변경
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[x + i][y + j] != w[i][j]) count++;
		}
	}
	return count;
}

int bw(int x, int y) { // 검은색으로 시작하는 배열로 변경
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[x + i][y + j] != b[i][j]) count++;
		}
	}
	return count;
}

int main() {
	int m, n, minv = 64;
	cin >> m >> n;
	string tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		chess[i] = tmp;
	}
	for (int i = 0; i + 8 <= m; i++) {
		for (int j = 0; j + 8 <= n; j++) {
			minv = min({ minv, wb(i,j), bw(i,j) });
		}
	}
	cout << minv;
}