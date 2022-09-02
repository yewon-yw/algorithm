#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

ifstream fin("test.inp");
ofstream fout("test.out");

map<string, int> last_name;
tuple<string, string, string> person[1000];

bool compare(tuple<string, string, string> a, tuple<string, string, string> b) {
	return get<0>(a) < get<0>(b);
}

int main() {
	int n, max_length = 0;
	string sid, first, last;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> sid >> first >> last;
		person[i] = make_tuple(sid, first, last);
		max_length = max(max_length, (int)first.size());
		last_name[last]++;
	}
	sort(person, person + n, compare);
	for (int i = 0; i < n; i++) {
		fout << get<0>(person[i]) << " " << get<1>(person[i]) << " ";
		for (int j = get<1>(person[i]).size(); j < max_length; j++) {
			fout << " ";
		}
		fout << get<2>(person[i]) << "\n";
	}

	fout << "\n";
	for (auto ln : last_name) {
		if (ln.second != 1) {
			fout << ln.first << " " << ln.second << "\n";
		}
	}
}