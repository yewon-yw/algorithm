#include <iostream>
using namespace std;
int pay = 1000;
int change[] = { 500, 100, 50, 10, 5, 1 };

int main() {
	int price, index = 0, count = 0;
	cin >> price;
	pay -= price;
	while (pay > 0) {
		if (pay >= change[index]) {
			pay -= change[index];
			count++;
		}
		else {
			index++;
		}
	}
	cout << count;
}