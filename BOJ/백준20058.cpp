#include <iostream>
#include <cmath>
using namespace std;

int A[65][65];
int A_tmp[65][65];
bool visited[65][65];
int L[1000];
int max_ice = 0;
int tmp_ice = 0;
int sizeN;

int dr[4] = { 0, 0, -1 , 1 };
int dc[4] = { 1, -1, 0, 0 };

void DFS(int r, int c) {
	visited[r][c] = true;
	if (A[r][c] > 0) {
		tmp_ice++;

		for (int i = 0; i < 4; i++) {
			int r_c = r + dr[i];
			int c_c = c + dc[i];
			if (r_c > -1 && r_c < sizeN && c_c > -1 && c_c < sizeN) {
				if (!visited[r_c][c_c]) {
					if (A[r_c][c_c] > 0) {
						DFS(r_c, c_c);
					}
				}
			}
		}
	}

	return;
}

void ice(int r, int c) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int r_c = r + dr[i];
		int c_c = c + dc[i];
		if (r_c > -1 && r_c < sizeN && c_c > -1 && c_c < sizeN) {
			if (A[r_c][c_c] > 0) {
				count++;
			}
		}
	}

	if (count < 3 && A[r][c] > 0) {
		A_tmp[r][c]--;
	}

	return;
}

int main() {
	int N;
	int Q;

	cin >> N; cin >> Q;

	sizeN = static_cast<int>(pow(2, N));
	//cout << "size : " << sizeN << endl;

	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) {
			cin >> A[i][j];
			A_tmp[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
	}

	for (int i = 0; i < Q; i++) {

		if (L[i] != 0) {
			int step_size = static_cast<int>(pow(2, L[i]));
			int rep = sizeN / step_size;
			//cout << "step_size : " << step_size << endl;
			//cout << "rep : " << rep << endl;

			for (int j = 0; j < rep; j++) {
				for (int k = 0; k < rep; k++) {
					int r_o = j * step_size;
					int c_o = k * step_size;
					for (int r = 0; r < step_size; r++) {
						for (int c = 0; c < step_size; c++) {
							A_tmp[r + r_o][c + c_o] = A[step_size - c - 1 + r_o][r + c_o];
						}
					}

				}
			}

			for (int r = 0; r < sizeN; r++) {
				for (int c = 0; c < sizeN; c++) {
					A[r][c] = A_tmp[r][c];
				}
			}
		}

		for (int r = 0; r < sizeN; r++) {
			for (int c = 0; c < sizeN; c++) {
				ice(r, c);
			}
		}

		for (int r = 0; r < sizeN; r++) {
			for (int c = 0; c < sizeN; c++) {
				A[r][c] = A_tmp[r][c];
			}
		}

		//for (int i = 0; i < sizeN; i++) {
		//	for (int j = 0; j < sizeN; j++) {
		//		cout.width(3);
		//		cout << A[i][j];
		//	}
		//	cout << "\n";
		//}
	}

	int sumOfIce = 0;
	for (int r = 0; r < sizeN; r++) {
		for (int c = 0; c < sizeN; c++) {
			sumOfIce += A[r][c];
			if (!visited[r][c]) {
				tmp_ice = 0;
				DFS(r, c);
				if (tmp_ice > max_ice) {
					max_ice = tmp_ice;
				}
			}
		}
	}

	cout << sumOfIce << endl;
	cout << max_ice << endl;

	/*for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << "\n";
	}
	for (int i = 0; i < Q; i++) {
		cout << L[i] << " ";
	}*/

	return 0;
}