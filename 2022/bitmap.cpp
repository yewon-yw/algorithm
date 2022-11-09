#pragma warning(disable:4996)
#include <cstdio>
#include <string>
using namespace std;

FILE* fcin = fopen("bitmap.inp", "r");
FILE* fcout = fopen("bitmap.out", "w");

char bitmap[200][200];
int N, M, index, cnt;
string dstr;

void btod(int sx, int sy, int ex, int ey) {
	bool zero, one;
	zero = one = true;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (bitmap[i][j] == '1') zero = false;
			if (bitmap[i][j] == '0') one = false;
		}
	}
	if (cnt >= 50) { fprintf(fcout, "\n"); cnt = 0; }
	cnt++;
	if (zero == true) { fprintf(fcout, "0"); }
	else if (one == true) { fprintf(fcout, "1"); }
	else {
		fprintf(fcout, "D");
		int xmid = (sx + ex + 1) / 2 + (ex - sx + 1) % 2;
		int ymid = (sy + ey + 1) / 2 + (ey - sy + 1) % 2;
		if (xmid - 1 <= ex && ymid - 1 <= ey) btod(sx, sy, xmid - 1, ymid - 1);
		if (xmid - 1 <= ex && ymid <= ey) btod(sx, ymid, xmid - 1, ey);
		if (xmid <= ex && ymid - 1 <= ey) btod(xmid, sy, ex, ymid - 1);
		if (xmid <= ex && ymid <= ey) btod(xmid, ymid, ex, ey);
	}
}

void dtob(int sx, int sy, int ex, int ey) {
	char c = dstr[index];
	index++;
	if (c == 'D') {
		int xmid = (sx + ex + 1) / 2 + (ex - sx + 1) % 2;
		int ymid = (sy + ey + 1) / 2 + (ey - sy + 1) % 2;
		if (xmid - 1 <= ex && ymid - 1 <= ey) dtob(sx, sy, xmid - 1, ymid - 1);
		if (xmid - 1 <= ex && ymid <= ey) dtob(sx, ymid, xmid - 1, ey);
		if (xmid <= ex && ymid - 1 <= ey) dtob(xmid, sy, ex, ymid - 1);
		if (xmid <= ex && ymid <= ey) dtob(xmid, ymid, ex, ey);
	}
	else {
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				bitmap[i][j] = c;
			}
		}
		return;
	}
}

void input_btype() {
	int check = 0, count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (count >= 50) {
				check = 1;
				count = 0;
				fscanf(fcin, "\n");
			}
			count++, check = 0;
			fscanf(fcin, "%c", &bitmap[i][j]);
		}
	}
	if (check != 1) fscanf(fcin, "\n");
	fprintf(fcout, "D%4d%4d\n", N, M);
}

char input_dtype() {
	char f;
	while (true) {
		fscanf(fcin, "%c", &f);
		if (f == '\n') continue;
		else if (f == '0' || f == '1' || f == 'D') {
			dstr += f;
		}
		else break;
	}
	fprintf(fcout, "B%4d%4d\n", N, M);
	return f;
}

void print_btype() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cnt >= 50) {
				fprintf(fcout, "\n");
				cnt = 0;
			}
			fprintf(fcout, "%c", bitmap[i][j]);
			cnt++;
		}
	}
}

int main() {
	char format;
	int check = 0;
	while (true) {
		cnt = 0, index = 0, dstr = "";
		if (check == 0) {
			fscanf(fcin, "%c", &format);
		}
		if (format == '#') break;
		fscanf(fcin, "%d %d\n", &N, &M);
		if (format == 'B') {
			check = 0;
			input_btype();
			btod(0, 0, N - 1, M - 1);
		}
		else {
			check = 1;
			format = input_dtype();
			dtob(0, 0, N - 1, M - 1);
			print_btype();
		}
		fprintf(fcout, "\n");
	}
}