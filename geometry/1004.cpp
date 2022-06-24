#include <iostream>
using namespace std;

int main() {
	int T, x1, x2, y1, y2, n, cx, cy, r;
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		while (n--) {
			cin >> cx >> cy >> r;
			int de = (x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy);
			int ar = (x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy);
			if (de < r*r && ar < r*r) continue; 
			if (de < r*r && ar > r*r) cnt++;
			else if (de > r*r && ar < r*r) cnt++;
		}
		cout << cnt << "\n";
	}
}