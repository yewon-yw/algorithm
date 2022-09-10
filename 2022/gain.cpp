#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("gain.inp");
ofstream fout("gain.out");

int main() {
	int t, n, gain;
	int arr[100001];
	fin >> t;
	while (t--) {
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> arr[i];
		}
		sort(arr, arr + n);
		gain = arr[n - 1] + arr[n - 2] - arr[0] - arr[1];
		fout << gain << "\n";
	}
}