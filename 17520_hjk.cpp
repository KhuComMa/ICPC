#include <iostream>
#include <cmath>

using namespace std;

//����
//n�ڸ� ���� ���ڿ��� 0�� 1�� ���� ���̰� 1������ ���ڿ��� �������� ���ڿ��̶�� ��
//n(1~100,000)
//�Է�: n
//���: �������� ���ڿ��� ��
//¦���� ��� �׳� ������, Ȧ���� ��� �ϳ� �÷���

int main() {
	int n, answer = 1;
	cin >> n;

	n = (n + 1) / 2;

	for (int i = 0; i < n; i++)
		answer = (answer * 2) % 16769023;

	cout << answer;

	return 0;
}