#include <iostream>
using namespace std;
long long N, B;
long long mat[5][5]; // �Է¹��� ��� �� ����
long long res[5][5]; // ����� ���� ���
long long temp[5][5]; // �߰� ��� �� ���� ���

void mul_mat(long long x[5][5], long long y[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++) {
				temp[i][j] += x[i][k] * y[k][j]; // ��� �� ���
			}
			temp[i][j] %= 1000; // 1000���� ���� ������ ����
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
			res[i][i] = 1; // ������ķ� �ʱ�ȭ
		}
	}
	while (B != 0) { 
		if (B % 2 == 1) { // �����ؾ� �ϴ� ���� Ȧ����
			mul_mat(res, mat); // {mat^(2n)}*mat -> 2n�� ���� ����ϰ� mat�� �ϴ� ��� ��Ŀ� ���� ����
		}
		mul_mat(mat, mat); // 2n�� n�� ����ؼ� ����(^2)���ָ� �Ǳ� ������
		B /= 2; // n���� ����ϱ� ����? ����� ���� �����ϰ� 2�� ����ؼ� ������
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}