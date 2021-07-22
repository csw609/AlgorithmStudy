//백준 2667 https://www.acmicpc.net/problem/2667
//컴퓨터 비전 바이너리 이미지 4 neighbor 라벨링에 사용할 수 있을듯
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
//	visited[y][x] = true; // 재방문 방지
//	group[y][x] = cur_group; //그룹 부여 => 필요한지 고려해보기
//	num++;
//
//	int nx, ny;
//	for (int i = 0; i < 4; i++) {
//		nx = x + dx[i]; ny = y + dy[i];
//		if ( nx > -1 && ny > -1 && nx < size && ny < size && visited[ny][nx] != true && img[ny][nx] == '1') { // 범위를 벗어나지 않는지 먼저 확인 후에 1인지 아닌지 확인하는 순서 중요함
//			//cout << "debug1" << endl;
//			Labeling_DFS(img, visited, nx, ny, size, group, cur_group, num);
//		}
//	}
//
//	return;
//}

void Labeling_DFS(char** img, bool** visited, int x, int y, int size, int& cur_group, int& num) {
	visited[y][x] = true; // 재방문 방지
	num++;// 건물 수 카운트

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i]; ny = y + dy[i];
		if (nx > -1 && ny > -1 && nx < size && ny < size && visited[ny][nx] != true && img[ny][nx] == '1') { // 범위를 벗어나지 않는지 먼저 확인 후에 1인지 아닌지 확인하는 순서 중요함
			//범위 내에서 방문한 적이 없고 '1' 즉 건물이 있다면 재귀 호출
			//cout << "debug1" << endl;
			Labeling_DFS(img, visited, nx, ny, size, cur_group, num);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n; //정사각형 한 변의 길이

	char** img;
	bool** visited;
	
	int cur_group = 0; //그룹의 수
	int num = 0;
	img = new char* [n]; // 입력
	visited = new bool* [n]; //방문 확인
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
	priority_queue<int,vector<int>,greater<int>> g_num;// 그룹별 건물 수 저장, 오름 차순으로 건물 수를 출력해야하므로 우선 순위 큐 사용

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != true && img[i][j] == '1') {
				//방문한 적이 없고 건물이 있다면
				cur_group++; //그룹 수 증가

				//Labeling_DFS(img, visited, j, i, n, group, cur_group, num);
				Labeling_DFS(img, visited, j, i, n, cur_group, num);

				//cout << "debug" << endl;

				g_num.push(num); // 건물 수 우선순위 큐에 삽입
				num = 0; // 건물 수 초기화
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

	// 정답 출력
	cout << cur_group << endl;
	while(!g_num.empty()){
		cout << g_num.top() << endl;
		g_num.pop();
	}	

	return 0;
}