#include <iostream>
using namespace std;
int N, M;
int arr[9];

void print() {
	for (int i = 1; i <= M; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void dfs(int j,int depth) {
	arr[depth] = j;
	if (depth == M) {
		print();
		return;
	}
	for (int i = j; i <= N; i++) {
		dfs(i, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dfs(i, 1);
	}
}