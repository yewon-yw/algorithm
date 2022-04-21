#include <iostream>
using namespace std;
int tree[26][2];

// 전위
void preorder(int node) {
	if (node == -1) return;
	cout << char('A' + node);
	preorder(tree[node][0]);
	preorder(tree[node][1]);
}

// 중위
void inorder(int node) {
	if (node == -1) return;
	inorder(tree[node][0]);
	cout << char('A' + node);
	inorder(tree[node][1]);
}

// 후위
void postorder(int node) {
	if (node == -1) return;
	postorder(tree[node][0]);
	postorder(tree[node][1]);
	cout << char('A' + node);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.') tree[a - 'A'][0] = -1;
		else tree[a - 'A'][0] = b - 'A';
		if (c == '.') tree[a - 'A'][1] = -1;
		else tree[a - 'A'][1] = c - 'A';
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}