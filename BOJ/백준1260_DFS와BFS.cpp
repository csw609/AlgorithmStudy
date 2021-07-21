//백준 1250 DFS와 BFS https://www.acmicpc.net/problem/1260
#include <iostream>
#include <set>
#include <queue>
using namespace std;

void DFS(set<int> *graph, bool *visited, int search) {
	
	visited[search] = true;
	cout << search + 1 << " ";

	auto iter = graph[search].begin();
	while (iter != graph[search].end()) {
		if (visited[(*iter)] == false) {
			DFS(graph, visited, (*iter));	
		}
		iter++;
	}
}

void BFS(set<int>* graph, bool* visited, int search) {
	queue<int> q;

	q.push(search);
	
	while (!q.empty()) {
		search = q.front();
		visited[search] = true;
		cout << search + 1 << " ";
		q.pop();

		auto iter = graph[search].begin();
		while (iter != graph[search].end()) {
			if (visited[(*iter)] == false) {
				visited[(*iter)] = true;
				q.push((*iter));
			}
			iter++;
		}

	}

}



int main() {
	int n, m, v; // 정점의 개수, 간선의 개수, 탐색을 시작할 정점
	set<int>* graph; // set으로 graph를 구현하므로써 중복 간선 방지 및 탐색 순서 정렬
	bool *visited_dfs;
	bool* visited_bfs;
	cin >> n; cin >> m; cin >> v;
	
	graph = new set<int>[n];
	visited_dfs = new bool[n];
	visited_bfs = new bool[n];
	for (int i = 0; i < n; i++) {
		graph[i].clear();
		visited_dfs[i] = false;
		visited_bfs[i] = false;
	}
	int tmp1, tmp2;
	for (int i = 0; i < m; i++) {
		cin >> tmp1; cin >> tmp2;

		graph[tmp1 - 1].insert(tmp2-1);  // 0번 index에 1이 들어있다면 1번과 2번이 연결되어 있다는 뜻
		graph[tmp2 - 1].insert(tmp1 - 1); //그래프는 양방향이므로 양방향 간선 처리
	}

	DFS(graph, visited_dfs, v-1);
	cout << "\n";
	BFS(graph, visited_bfs, v - 1);

	return 0;
}