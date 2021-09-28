#include <iostream>

using namespace std;

//조건
//양과 염소는 같은 사료를 먹는다.
//양 한 마리는 하루에 사료를 a만큼 먹음, 염소는 하루에 b만큼 먹음
//양과 염소가 몇 마리인지 확인 작업
//양과 염소의 전체 수와 소비한 사료 양을 가지고 양과 염소 각각이 몇마리인지 알기
//입력: a(1~1,000) b(1~1,000) n(전체 마리수2~1,000) w(전체 사료 양, 2~1,000,000)
//출력: 해가 하나라면 양과 염소의 수 각각 출력, 해가 여러 개이거나 없으면 -1출력
//공식 w = a*x + b*(n-x), x는 양의 수
//x = (w-b*n)/(a-b)

int main() {
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int ta = 0, tb = 0, count = 0;;

	for (int i = 1; i < n; i++) {
		if (a * i + b * (n - i) == w) {
			ta = i;
			tb = n - i;
			count++;
		}
	}
	
	if (count == 1)
		cout << ta << ' ' << tb;
	else
		cout << -1;

	return 0;
}