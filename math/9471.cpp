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
		fibo.push_back(1); // 두 번째 피보나치수열까진 그냥 삽입

		int n = 3; // 세 번째 피보나치수열부턴 앞의 두 수를 덧셈하는 방식
		while (true) {
			// 나머지가 0, 1이 연속으로 나올 때 까지 계산
			fibo.push_back((fibo.at(n - 1) + fibo.at(n - 2)) % m);
			if (fibo.at(n - 1) % m == 0 && fibo.at(n) % m == 1)
				break;
			n++;
		}
		cout << num << " " << n - 1 << "\n";
	}
}