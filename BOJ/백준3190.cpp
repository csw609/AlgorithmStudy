#include <iostream>
#include <list>
//#include <set>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <string>

using namespace std;

//��,�� ���� ������, �Ʒ�, ����, ��
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int world[100][100] = { 0, };
int command_time[100];
char command_type[100];

list<pair<int, int>> snake[105]; //<��,��>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int size_of_world;
	int num_of_apple;

	cin >> size_of_world;
	cin >> num_of_apple;

	for (int i = 0; i < num_of_apple; i++) {
		int row;
		int col;

		cin >> row;
		cin >> col;

		world[row - 1][col - 1] = 1; //��� ǥ��
	}

	//�ð�ȭ
	//for (int i = 0; i < size_of_world; i++) {
	//	for (int j = 0; j < size_of_world; j++) {
	//		cout << world[i][j];
	//	}
	//	cout << "\n";
	//}

	int num_of_command;

	cin >> num_of_command;

	for (int i = 0; i < num_of_command; i++) {
		cin >> command_time[i];
		cin >> command_type[i];
	}

	int size_of_snake = 1;
	int direction_of_snake = 0;
	int count_of_command = 0;
	// dr,dc���� D�� +1, L�� -1;

	int time_of_simulation = 1;

	snake->push_front({ 0,0 });

	while (true) {
		
		// �Ӹ� �÷��� �̵��ϱ�
		list<pair<int, int>>::iterator cur = snake->begin();
		int head_row = cur->first + dr[direction_of_snake];
		int head_col = cur->second + dc[direction_of_snake];
		//cout << head_row << " " << head_col << endl;

		// �� �浹
		if (head_row < 0 || head_row > size_of_world - 1 || head_col < 0 || head_col > size_of_world - 1) {
			//cout << "break" << endl;
			break;
		}

		// ���� �浹
		list<pair<int, int>>::iterator crash_checker = snake->begin();
		bool flag_crash = false;
		for (; crash_checker != snake->end(); crash_checker++) {
			//cout << "body : " << crash_checker->first << " " << crash_checker->second << endl;
			if (crash_checker->first == head_row && crash_checker->second == head_col) {
				flag_crash = true;
				break;
			}
		}
		if (flag_crash) {
			break;
		}

		snake->push_front({ head_row, head_col });

		//��� Ȯ��
		if (world[head_row][head_col] != 1) {
			//����� ���ٸ�
			snake->pop_back();
		}
		else {
			//����� �ִٸ�
			world[head_row][head_col] = 0;
		}


		// ���� ��ȯ
		if (time_of_simulation == command_time[count_of_command]) {
			//��ȯ
			if (command_type[count_of_command] == 'D') {
				//cout << "D" << endl;
				direction_of_snake = (direction_of_snake + 1) % 4;
			}
			else if (command_type[count_of_command] == 'L') {
				//cout << "L" << endl;
				direction_of_snake = ((direction_of_snake - 1) + 4) % 4;
			}

			count_of_command++;
		}

		
		// �ð�ȭ
		/*cout << "time : " << time_of_simulation << endl;
		for (int i = 0; i < size_of_world; i++) {
			for (int j = 0; j < size_of_world; j++) {
				if (world[i][j] == 3) {
					world[i][j] = 0;
				}
			}
		}
		list<pair<int, int>>::iterator visualize = snake->begin();
		for (; visualize != snake->end(); visualize++) {
			world[visualize->first][visualize->second] = 3;
		}
		for (int i = 0; i < size_of_world; i++) {
			for (int j = 0; j < size_of_world; j++) {
				cout << world[i][j];
			}
			cout << "\n";
		}*/
		//////

		time_of_simulation++;
	}

	cout << time_of_simulation;
}
