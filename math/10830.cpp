#include <iostream>
using namespace std;
long long N, B;
long long mat[5][5]; // 입력받은 행렬 값 저장
long long res[5][5]; // 결과값 저장 행렬
long long temp[5][5]; // 중간 계산 값 저장 행렬

void mul_mat(long long x[5][5], long long y[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++) {
				temp[i][j] += x[i][k] * y[k][j]; // 행렬 곱 계산
			}
			temp[i][j] %= 1000; // 1000으로 나눈 나머지 저장
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x[i][j] = temp[i][j];
		}
	}
}

int main(){
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
			res[i][i] = 1; // 단위행렬로 초기화
		}
	}
	while (B != 0) { 
		if (B % 2 == 1) { // 제곱해야 하는 수가 홀수면
			mul_mat(res, mat); // {mat^(2n)}*mat -> 2n은 따로 계산하고 mat만 일단 결과 행렬에 곱셈 진행
		}
		mul_mat(mat, mat); // 2n은 n번 계산해서 제곱(^2)해주면 되기 때문에
		B /= 2; // n번만 계산하기 위해? 행렬은 곱셈 진행하고 2를 계속해서 나눠줌
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}