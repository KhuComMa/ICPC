//#include <iostream>
//#include <vector>
//
//using namespace std;
//
////����
////M��, N�� ���� �׸��忡�� ���� ���� ������ ġ��
////��Ģ 3����
////1. s(0,0)�������� t(N-1, M-1)�������� ����(�� ������ ���� �Ʒ� == �� �Ʒ� ���� ��)
////2. ������������ ������ ��� ��߰���(�ð� ���x)
////3. ���� �Ʒ��� ��� �ð��� ���������� ��� �ð��� ���� �� ĭ�� L�� ����
////4. ������ �ٲٴ� �� �ɸ��� �ð��� �׻� 1
////5. ���� ���� �� G��ŭ�� ���� ����(G������ ���Ḧ ��뿩 t�� �����ؾ���)
////6. ������ �׸��� �鿡�� �Ҹ�Ǵ� ���ᷮ�� �־��� ����
////7. ������ �ٲ� �� ����� ������ ����
//
////�Է�:�׸����� ���¿� G,L
////M N L G (�� ��, �� ��, �� ���ڸ� ���� ���� �� �ɸ��� �ð�, ���ᷮ)
////M�ٿ� N-1���� ���� ��� ��� ���ᷮ, M-1�ٿ� N���� ���� ��� ��� ���ᷮ 
////���:���� ������ ������ t�� �����ϴ� �ð�
//
////Ǯ��
////������ ���ᷮ�� ����Ͽ� �ȿ� ������ ����� �ð��� ���� ���� �ɸ��� ��� ���
//
//int Length[101][101];//���� �̵� ���ᷮ
//int Width[101][101];//���� �̵� ���ᷮ
//#define INF 1000000000;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int T;//�׽�Ʈ ���̽� ��
//	
//	cin >> T;
//
//	while (T--) {
//		vector<pair<pair<int, int>, char>> dp[101][101];//������ȹ�� ��� ������ ���� <<���� �ð�, ���� ����>, ���� �̵�����>
//		int M, N, L, G;//M:�� ��(2-100), N:�� ��(2-100), L:�����ϴµ� �ɸ��� �ð�(1-10), G:���ᷮ(1-1,000,000)
//		cin >> M >> N >> L >> G;
//
//		//���� �̵� �� ���ᷮ
//		for (int i = 0; i < M; i++) {
//			for (int j = 1; j < N; j++) {
//				cin >> Width[i][j];
//			}
//		}
//
//		//���� �̵� �� ���ᷮ
//		for (int i = 1; i < M; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> Length[i][j];
//			}
//		}
//
//		for (int i = 1; i < N; i++)
//			dp[0][i].push_back({ { i * L, dp[0][i - 1][0].first.second + Width[0][i] }, 'w'});
//
//		for (int i = 1; i < N; i++)
//			dp[i][0].push_back({ { i * L, dp[i - 1][0][0].first.second + Length[i][0] },'l' });
//
//		for (int i = 1; i < M; i++) {
//			for (int j = 1; j < N; j++) {
//				int f = INF;
//				int s = INF;
//				for (int k = 0; k < dp[i - 1][j].size(); k++) {//���� �̵�
//					if (dp[i - 1][j][k].first.second + Length[i][j] <= G) {//���ᷮ Ȯ��
//						if (dp[i - 1][j][k].second == 'w') {//���� ����
//							if (f <= dp[i - 1][j][k].first.first + L + 1 && s <= dp[i - 1][j][k].first.second + Length[i][j]);
//							else {
//								f = dp[i - 1][j][k].first.first + L + 1;
//								s = dp[i - 1][j][k].first.second + Length[i][j];
//								dp[i][j].push_back({ { dp[i - 1][j][k].first.first + L + 1, dp[i - 1][j][k].first.second + Length[i][j]}, 'l' });
//							}
//						}
//						else {//���� ���� �̵�
//							if (f <= dp[i - 1][j][k].first.first + L && s <= dp[i - 1][j][k].first.second + Length[i][j]);
//							else {
//								f = dp[i - 1][j][k].first.first + L;
//								s = dp[i - 1][j][k].first.second + Length[i][j];
//								dp[i][j].push_back({ { dp[i - 1][j][k].first.first + L, dp[i - 1][j][k].first.second + Length[i][j]}, 'l' });
//							}
//						}
//					}
//				}
//
//				for (int k = 0; k < dp[i][j - 1].size(); k++) {//������ �̵�
//					if (dp[i][j - 1][k].first.second + Width[i][j] <= G) {//���ᷮ Ȯ��
//						if (dp[i][j - 1][k].second == 'l') {//���� ����
//							if (f <= dp[i][j - 1][k].first.first + L + 1 && s <= dp[i][j - 1][k].first.second + Width[i][j]);
//							else {
//								f = dp[i][j - 1][k].first.first + L + 1;
//								s = dp[i][j - 1][k].first.second + Width[i][j];
//								dp[i][j].push_back({ { dp[i][j - 1][k].first.first + L + 1, dp[i][j - 1][k].first.second + Width[i][j]}, 'w' });
//							}
//						}
//						else {//���� ���� �̵�
//							if (f <= dp[i][j - 1][k].first.first + L && s <= dp[i][j - 1][k].first.second + Width[i][j]);
//							else {
//								f = dp[i][j - 1][k].first.first + L ;
//								s = dp[i][j - 1][k].first.second + Width[i][j];
//								dp[i][j].push_back({ { dp[i][j - 1][k].first.first + L , dp[i][j - 1][k].first.second + Width[i][j]}, 'w' });
//							}
//						}
//					}
//				}
//				//�޸� �ʰ��� �����ϱ� ����(���� ���͸� ����ݴϴ�.)
//				dp[i - 1][j].erase(dp[i - 1][j].begin(), dp[i - 1][j].end());
//			}
//		}
//
//		if (dp[M - 1][N - 1].size() == 0)
//			cout << -1 << '\n';
//		else {
//			int min = INF;//���� ���� �����ϴ� ���
//			for (int i = 0; i < dp[M - 1][N - 1].size(); i++) {
//				if (min > dp[M - 1][N - 1][i].first.first)
//					min = dp[M - 1][N - 1][i].first.first;
//			}
//			cout << min << '\n';
//		}
//	}
//
//	return 0;
//}

//���� ������ �޸� �ʰ� �߻�


#include <iostream>

using namespace std;

//����
//M��, N�� ���� �׸��忡�� ���� ���� ������ ġ��
//��Ģ 3����
//1. s(0,0)�������� t(N-1, M-1)�������� ����(�� ������ ���� �Ʒ� == �� �Ʒ� ���� ��)
//2. ������������ ������ ��� ��߰���(�ð� ���x)
//3. ���� �Ʒ��� ��� �ð��� ���������� ��� �ð��� ���� �� ĭ�� L�� ����
//4. ������ �ٲٴ� �� �ɸ��� �ð��� �׻� 1
//5. ���� ���� �� G��ŭ�� ���� ����(G������ ���Ḧ ��뿩 t�� �����ؾ���)
//6. ������ �׸��� �鿡�� �Ҹ�Ǵ� ���ᷮ�� �־��� ����
//7. ������ �ٲ� �� ����� ������ ����

//�Է�:�׸����� ���¿� G,L
//M N L G (�� ��, �� ��, �� ���ڸ� ���� ���� �� �ɸ��� �ð�, ���ᷮ)
//M�ٿ� N-1���� ���� ��� ��� ���ᷮ, M-1�ٿ� N���� ���� ��� ��� ���ᷮ 
//���:���� ������ ������ t�� �����ϴ� �ð�

//Ǯ��
//������ ���ᷮ�� ����Ͽ� �ȿ� ������ ����� �ð��� ���� ���� �ɸ��� ��� ���

int Length[101][101];//���� �̵� ���ᷮ
int Width[101][101];//���� �̵� ���ᷮ
int dp[101][101][200][2];//������ȹ�� ��� ������ ���� y�� ��ġ, x�� ��ġ, ���� ��ȯ��,���� ����(0-����,1-����) = ���� ���ᷮ

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int INF = 2000000000;

	int T;//�׽�Ʈ ���̽� ��
	
	cin >> T;

	while (T--) {
		int M, N, L, G;//M:�� ��(2-100), N:�� ��(2-100), L:�����ϴµ� �ɸ��� �ð�(1-10), G:���ᷮ(1-1,000,000)
		cin >> M >> N >> L >> G;

		//������ �̵� �� ���ᷮ
		for (int i = 0; i < M; i++) {
			for (int j = 1; j < N; j++) {
				cin >> Width[i][j];
			}
		}

		//���� �̵� �� ���ᷮ
		for (int i = 1; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Length[i][j];
			}
		}

		//dp�迭 �ʱ�ȭ(INF)
		for (int y = 0; y < 101; y++) {
			for (int x = 0; x < 101; x++) {
				for (int t = 0; t < 200; t++) {
					for (int d = 0; d < 2; d++)
						dp[y][x][t][d] = INF;
				}
			}
		}

		//������
		dp[0][0][0][0] = 0;
		dp[0][0][0][1] = 0;

		//�ٱ������� ���� ó�����ݴϴ�.
		for (int i = 1; i < 101; i++) {
			dp[0][i][0][0] = dp[0][i - 1][0][0] + Width[0][i];
			dp[i][0][0][1] = dp[i - 1][0][0][1] + Length[i][0];
		}

		//���� ���� ���� ���� ���� (x,y)�������� �� ��Ȳ�� �м���.
		for (int y = 1; y < M; y++) {
			for (int x = 1; x < N; x++) {
				for (int t = 0; t <= 200; t++) {
					dp[y][x][t][0] = dp[y][x - 1][t][0] < dp[y][x - 1][t - 1][1] ? dp[y][x - 1][t][0] + Width[y][x] : dp[y][x - 1][t - 1][1] + Width[y][x];
					dp[y][x][t][1] = dp[y - 1][x][t - 1][0] < dp[y - 1][x][t][1] ? dp[y - 1][x][t - 1][0] + Length[y][x] : dp[y - 1][x][t][1] + Length[y][x];
				}
			}
		}


		int min = 201;

		for (int t = 1; t < 200; t++) {
			if (dp[M - 1][N - 1][t][0] <= G || dp[M - 1][N - 1][t][1] <= G)
				min = min > t ? t : min;
		}

		if (min == 201)
			cout << -1 << '\n';
		else
			cout << (M + N - 2) * L + min << '\n';
	}

	return 0;
}
