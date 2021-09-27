#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

//조건
//q-인덱스 값
//학생이 발표한 논문의 횟수 n번 이중 k번 이상 인용된 논문이 k이상이고
//나머지 n-k편의 논문들 인용회수가 각각 k번이하라면 해당 학생의 q-인덱스 값은 k
//입력: 논문의 수, 각 논문별 인용횟수
//출력: q-인덱스 출력

//풀이
//오름차순 정렬후 k를 0에서부터 1씩 증가시키며 해당 조건에 부합하는 최대값 출력

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