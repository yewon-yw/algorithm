#include <iostream>
#include <string>
using namespace std;
int N;

string repeat[5] = {
	"\"����Լ��� ������?\"\n",
	"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
	"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
	"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
	"��� �亯�Ͽ���.\n"
};
string last[2] = {
	"\"����Լ��� ������?\"\n",
	"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n"
};

void bot(int n) {
	string t = "";
	for (int i = N; i > n; i--) t += "____";
	if (n == 0) {
		cout << t + last[0] << t + last[1] << t + repeat[4];
		return;
	}
	for (int i = 0; i < 4; i++) {
		cout << t + repeat[i];
	}
	bot(n - 1);
	cout << t + repeat[4];
}

int main() {
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	bot(N);
}