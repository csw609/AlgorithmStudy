//softeer 차세대 지능형 교통시스템https://www.acmicpc.net/problem/11657
#include <iostream>
//#include <set>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <string>

using namespace std;

int n, t, count_g;

void search(int ***graph, int simul_t, int cx, int cy, int px, int py, bool **visited) {
	
	if (simul_t <= t && cx > -1 && cx < n && cy > -1 && cy < n) {
		if (!visited[cy][cx])
		{
			visited[cy][cx] = true;
			count_g++;
		}
		
		int dx, dy;
		switch (graph[cy][cx][simul_t % 4]) {
		case 1:
			if (cx - px != 1 || cy - py != 0) {
				break;
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t+1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 2:
			if (cx - px != 0 || cy - py != -1) {
				break;
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 3:
			if (cx - px != -1 || cy - py != 0) {
				break;
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 4:
			if (cx - px != 0 || cy - py != 1) {
				break;
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 5:
			if (cx - px != 1 || cy - py != 0) {
				break;
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 6:
			if (cx - px != 0 || cy - py != -1) {
				break;
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 7:
			if (cx - px != -1 || cy - py != 0) {
				break;
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 8:
			if (cx - px != 0 || cy - py != 1) {
				break;
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 9:
			if (cx - px != 1 || cy - py != 0) {
				break;
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 10:
			if (cx - px != 0 || cy - py != -1) {
				break;
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 11:
			if (cx - px != -1 || cy - py != 0) {
				break;
			}
			dx = 0; dy = -1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		case 12:
			if (cx - px != 0 || cy - py != 1) {
				break;
			}
			dx = -1; dy = 0;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			dx = 0; dy = 1;
			if (cx + dx != px || cy + dy != py) {
				search(graph, simul_t + 1, cx + dx, cy + dy, cx, cy, visited);
			}
			break;
		}

	}
	else {
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	count_g = 0;

	cin >> n; cin >> t;

	int*** graph;
	bool** visited;
	graph = new int** [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int* [n];
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			graph[i][j] = new int[4];
			visited[i][j] = false;
			cin >> graph[i][j][0];
			cin >> graph[i][j][1];
			cin >> graph[i][j][2];
			cin >> graph[i][j][3];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[j][i][0];
			cin >> graph[j][i][1];
			cin >> graph[j][i][2];
			cin >> graph[j][i][3];
		}
	}*/
	

	search(graph, 0, 0, 0, 0, 1, visited);

	cout << count_g << endl;
}