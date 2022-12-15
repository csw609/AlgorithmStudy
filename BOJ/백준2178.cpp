#include <iostream>
//#include <set>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
#include <string>

#define BIAS 3

using namespace std;

int dr[4] = { 0, 1, 0, -1};
int dc[4] = { 1, 0, -1, 0 };


int maze[100][100] = {0,};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int row, col;
	string maze_tmp[100];

	cin >> row;
	cin >> col;

	for (int i = 0; i < row; i++) {
		cin >> maze_tmp[i];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze_tmp[i][j] == '1') {
				maze[i][j] = 1;
			}
			else {
				maze[i][j] = 0;
			}
		}
	}
	
	maze[0][0] = 2;
	int checker = BIAS;

	while (true) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < 4; k++) {
					int move_row = i + dr[k];
					int move_col = j + dc[k];

					if (move_row > -1 && move_row < row && move_col > -1 && move_col < col) {
						if (maze[move_row][move_col] != 1 && maze[move_row][move_col] != 0 && maze[move_row][move_col] < checker && maze[i][j] == 1) {
							maze[i][j] = checker;
						}
					}

				}
			

			}
		}
		
		//for (int i = 0; i < row; i++) {
		//	for (int j = 0; j < col; j++) {
		//		cout << maze[i][j];
		//	}
		//	cout << "\n";
		//}

		checker++;
		if (maze[row-1][col-1] != 1) {
			//cout << "break";
			break;
		}
	}

	cout << checker - BIAS + 1 << endl;
}