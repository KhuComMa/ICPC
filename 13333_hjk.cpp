#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

//����
//q-�ε��� ��
//�л��� ��ǥ�� ���� Ƚ�� n�� ���� k�� �̻� �ο�� ���� k�̻��̰�
//������ n-k���� ���� �ο�ȸ���� ���� k�����϶�� �ش� �л��� q-�ε��� ���� k
//�Է�: ���� ��, �� ���� �ο�Ƚ��
//���: q-�ε��� ���

//Ǯ��
//�������� ������ k�� 0�������� 1�� ������Ű�� �ش� ���ǿ� �����ϴ� �ִ밪 ���

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k = 0, t;
	vector<int>v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= k && n - i >= k) {
			k++;
			i--;
		}
		else if (v[i] < k && n - i < k) {
			k--;
			break;
		}
		else if (v[i] < k) {
			if (i == v.size() - 1)
				k--;
			continue;
		}
		else if (n - i < k) {
			k--;
			break;
		}
	}

	cout << k;

	return 0;
}