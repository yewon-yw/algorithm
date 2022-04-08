#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num, m;
		cin >> num >> m;
		vector<int> fibo;
		fibo.push_back(0);
		fibo.push_back(1);
		fibo.push_back(1); // �� ��° �Ǻ���ġ�������� �׳� ����

		int n = 3; // �� ��° �Ǻ���ġ�������� ���� �� ���� �����ϴ� ���
		while (true) {
			// �������� 0, 1�� �������� ���� �� ���� ���
			fibo.push_back((fibo.at(n - 1) + fibo.at(n - 2)) % m);
			if (fibo.at(n - 1) % m == 0 && fibo.at(n) % m == 1)
				break;
			n++;
		}
		cout << num << " " << n - 1 << "\n";
	}
}