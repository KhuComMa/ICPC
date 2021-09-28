#include <iostream>
#include <cmath>

using namespace std;

//조건
//n자리 이진 문자열의 0과 1의 개수 차이가 1이하인 문자열을 균형잡힌 문자열이라고 함
//n(1~100,000)
//입력: n
//출력: 균형잡힌 문자열의 수
//짝수일 경우 그냥 나눠줌, 홀수일 경우 하나 올려줌

int main() {
	int n, answer = 1;
	cin >> n;

	n = (n + 1) / 2;

	for (int i = 0; i < n; i++)
		answer = (answer * 2) % 16769023;

	cout << answer;

	return 0;
}