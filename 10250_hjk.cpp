#include <iostream>

using namespace std;

//����
//1.������ ���� ���ʿ� ����
//2.������ ���� �Ÿ��� 1
//3.���ʸ鿡�� ���� ����
//(1,2,3 �������� �Ϲ� 2���� ��ǥ�� ��밡��)
//4.���ȣ�� ǥ�� -> Y:����, X:�ش��� �������� �Ÿ�(�׻� ���ڸ� ���·� ǥ��) -> YXX:Y�� �տ� ����
//���� ���, W=12, H=6�̸� ���� ��ȣ�� 101~612���� ������((1,1)~(12,6))
//5.���� �̵��� �̵��Ÿ��� ����x
//6.�Ʒ����� �켱������ ��
//�Է�:H W N���� �� ��, ���� �� ��, N��° ����
//���:N��° ������ �� ��ȣ

//�뷫 ������ ������ ����
//101 201 301 401...H01 102... 612

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;

	cin >> T;//�׽�Ʈ ���̽� ��ȸ��

	while (T--) {
		int W, H, N, answer;//W:���� ���� ��, H:�� ����, N:���� �Խ� ����
		cin >> H >> W >> N;
		
		//�Ʒ��� ���� ���ʺ��� ä������ ������ �� ���� ������ ��ȣ�� �����ִ� �� ���
		//���׿����ڸ� ����Ͽ� �� �������� ���� �׷��� ���� ��� ���� ���̽� �з�
		//���� ������ ���������� ����Ѵٰ� �Ҷ� ���� ������ ����(H)�� ������ �������⿡ ���� �ʿ�
		answer = (N % H == 0 ? H : N % H) * 100 + (N % H == 0 ? N / H : N / H + 1);

		cout << answer << '\n';
	}

	return 0;
}