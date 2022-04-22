#include <iostream>
using namespace std;
#define INF 987654321;
long long dis[100000];
long long price[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	long long minv = INF;
	long long result = 0;
	for (int i = 0; i < n - 1; i++) {
		minv = min(minv, price[i]);
		result += minv * dis[i];
	}
	cout << result;
}