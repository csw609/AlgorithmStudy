//���� 2667 https://www.acmicpc.net/problem/2667
//��ǻ�� ���� ���̳ʸ� �̹��� 4 neighbor �󺧸��� ����� �� ������
#include <iostream>
//#include <set>
//#include <stack>
#include <queue>
//#include <algorithm>
//#include <string>

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

using namespace std;

//void Labeling_DFS(char** img, bool** visited, int x, int y, int size, int** group, int& cur_group, int &num) {
//	visited[y][x] = true; // ��湮 ����
//	group[y][x] = cur_group; //�׷� �ο� => �ʿ����� ����غ���
//	num++;
//
//	int nx, ny;
//	for (int i = 0; i < 4; i++) {
//		nx = x + dx[i]; ny = y + dy[i];
//		if ( nx > -1 && ny > -1 && nx < size && ny < size && visited[ny][nx] != true && img[ny][nx] == '1') { // ������ ����� �ʴ��� ���� Ȯ�� �Ŀ� 1���� �ƴ��� Ȯ���ϴ� ���� �߿���
//			//cout << "debug1" << endl;
//			Labeling_DFS(img, visited, nx, ny, size, group, cur_group, num);
//		}
//	}
//
//	return;
//}

void Labeling_DFS(char** img, bool** visited, int x, int y, int size, int& cur_group, int& num) {
	visited[y][x] = true; // ��湮 ����
	num++;// �ǹ� �� ī��Ʈ

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i]; ny = y + dy[i];
		if (nx > -1 && ny > -1 && nx < size && ny < size && visited[ny][nx] != true && img[ny][nx] == '1') { // ������ ����� �ʴ��� ���� Ȯ�� �Ŀ� 1���� �ƴ��� Ȯ���ϴ� ���� �߿���
			//���� ������ �湮�� ���� ���� '1' �� �ǹ��� �ִٸ� ��� ȣ��
			//cout << "debug1" << endl;
			Labeling_DFS(img, visited, nx, ny, size, cur_group, num);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n; //���簢�� �� ���� ����

	char** img;
	bool** visited;
	
	int cur_group = 0; //�׷��� ��
	int num = 0;
	img = new char* [n]; // �Է�
	visited = new bool* [n]; //�湮 Ȯ��
	//int** group;
	//group = new int* [n];


	for (int i = 0; i < n; i++) {
		img[i] = new char[n + 1];
		visited[i] = new bool[n];
		//group[i] = new int[n];
		cin >> img[i];

		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			//group[i][j] = 0;
		}
	}
	priority_queue<int,vector<int>,greater<int>> g_num;// �׷캰 �ǹ� �� ����, ���� �������� �ǹ� ���� ����ؾ��ϹǷ� �켱 ���� ť ���

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != true && img[i][j] == '1') {
				//�湮�� ���� ���� �ǹ��� �ִٸ�
				cur_group++; //�׷� �� ����

				//Labeling_DFS(img, visited, j, i, n, group, cur_group, num);
				Labeling_DFS(img, visited, j, i, n, cur_group, num);

				//cout << "debug" << endl;

				g_num.push(num); // �ǹ� �� �켱���� ť�� ����
				num = 0; // �ǹ� �� �ʱ�ȭ
			}
		}
	}

	//debug
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				cout << group[i][j];
		}
		cout << endl;
	}*/

	// ���� ���
	cout << cur_group << endl;
	while(!g_num.empty()){
		cout << g_num.top() << endl;
		g_num.pop();
	}	

	return 0;
}