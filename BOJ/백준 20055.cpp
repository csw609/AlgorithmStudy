//백준 11003 마법사 상어와 파이어볼 - https://www.acmicpc.net/problem/20056

#include <iostream>

using namespace std;

int belt[200];
bool robot[200];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

	int N, K;

	cin >> N; cin >> K;
	
	int len = N * 2;

	for (int i = 0; i < len; i++) {
		cin >> belt[i];
	}

	int zeroCount = 0;
	int step = 0;
	int raisePos = 0;
	int dropPos = N-1;

	while (zeroCount < K) {

		step++;
		// belt move
		raisePos = (raisePos - 1 + len) % len;
		dropPos = (dropPos - 1 + len) % len;

		// robot drop
		robot[dropPos] = false;

		// robot move
		for (int i = (dropPos-1 + len) % len; i != (raisePos-1 + len) % len; i = (i-1 + len) % len) {
			if (robot[i]) {
				int next_pos = (i + 1) % len;

				if (!robot[next_pos] && belt[next_pos] > 0) {
					robot[i] = false;
					robot[next_pos] = true;
					belt[next_pos]--;
				}
			}
		}

		// robot raise
		if (belt[raisePos] > 0) {
			belt[raisePos]--;
			robot[raisePos] = true;
		}

		
		// robot drop
		robot[dropPos] = false;

		//count
		int tmp = 0;

		for (int i = 0; i < len; i++) {
			if (belt[i] < 1) {
				tmp++;
			}
		}
		//cout << tmp << endl;
		zeroCount = tmp;
	}

	cout << step << endl;

	return 0;
}