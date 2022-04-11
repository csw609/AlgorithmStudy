//백준 11003 마법사 상어와 파이어볼 - https://www.acmicpc.net/problem/20056
class table {
public:
	table() { numOfFireball = 0; mass = 0; speed = 0; dir = -1; odd = false; even = false; }
	void erase() { numOfFireball = 0; mass = 0; speed = 0; dir = -1; odd = false; even = false; };

	int numOfFireball;

	int mass;
	int speed;
	int dir;

	bool odd;
	bool even;
};

class shark {

public:

	int r;
	int c;

	int m;
	int s;
	int d;
};

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


table t[51][51];

int dr[8] = { -1, -1,  0, +1, +1, +1,  0, -1 };
int dc[8] = { 0, +1, +1, +1,  0, -1, -1, -1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

	int N, M, K;
	cin >> N; cin >> M; cin >> K;

	queue<shark> qShark;
	for (int i = 0; i < M; i++) {
		shark shkTmp;

		cin >> shkTmp.r;
		shkTmp.r -= 1;
		cin >> shkTmp.c;
		shkTmp.c -= 1;

		cin >> shkTmp.m;
		cin >> shkTmp.s;
		cin >> shkTmp.d;

		qShark.push(shkTmp);
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			t[r][c].erase();
		}
	}

	for (int qwe = 0; qwe < K; qwe++) {
		while (!qShark.empty()) {
			shark shkTmp = qShark.front();
			qShark.pop();

			int r = shkTmp.r;
			int c = shkTmp.c;

			r += dr[shkTmp.d] * shkTmp.s;
			c += dc[shkTmp.d] * shkTmp.s;
			while (r < 0) {
				r += N;
			}
			while (c < 0) {
				c += N;
			}
			r = r % N;
			c = c % N;

			t[r][c].numOfFireball++;
			t[r][c].mass += shkTmp.m;
			t[r][c].dir = shkTmp.d;
			t[r][c].speed += shkTmp.s;

			if (shkTmp.d % 2 == 0) {
				t[r][c].even = true;
			}
			else {
				t[r][c].odd = true;
			}
		}
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (t[r][c].numOfFireball < 1) continue;

				if (t[r][c].numOfFireball == 1) {
					shark shkTmp;
					shkTmp.d = t[r][c].dir;
					shkTmp.m = t[r][c].mass;
					shkTmp.s = t[r][c].speed;
					shkTmp.r = r;
					shkTmp.c = c;

					qShark.push(shkTmp);
				}
				else if (t[r][c].numOfFireball > 1) {
					int mass = t[r][c].mass / 5;
					int speed = t[r][c].speed / t[r][c].numOfFireball;
					if (mass > 0) { // consider about mass interger 
						shark shkTmp;

						shkTmp.r = r;
						shkTmp.c = c;
						shkTmp.m = mass;
						shkTmp.s = speed;

						if (t[r][c].odd && t[r][c].even) {
							shkTmp.d = 1;
							qShark.push(shkTmp);

							shkTmp.d = 3;
							qShark.push(shkTmp);

							shkTmp.d = 5;
							qShark.push(shkTmp);

							shkTmp.d = 7;
							qShark.push(shkTmp);
						}
						else {
							shkTmp.d = 0;
							qShark.push(shkTmp);

							shkTmp.d = 2;
							qShark.push(shkTmp);

							shkTmp.d = 4;
							qShark.push(shkTmp);

							shkTmp.d = 6;
							qShark.push(shkTmp);
						}
					}
				}
				t[r][c].erase();
			}
		}
	}

	int massSum = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			while (!qShark.empty()) {

				massSum += qShark.front().m;
				//cout << qShark.front().m << endl;
				//cout << qShark.front().d << endl;
				qShark.pop();
			}
		}
	}

	cout << massSum << endl;
	return 0;
}

