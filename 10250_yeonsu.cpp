#include <iostream>
#include <string>
using namespace std;

int H, W, N;
void solve() {
	cin >> H >> W >> N;

	int floor = 0, room = 0;
	if (N % H == 0) {
		room = N / H;
		floor = H;
	}
	else {
		room = N / H + 1;
		floor = N - (room - 1) * H;
	}

	string str_floor = to_string(floor);
	string str_room = to_string(room);
	if (str_room.size() == 1) {
		str_room = "0" + str_room;
	}
	cout << str_floor + str_room << "\n";
}

int main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}