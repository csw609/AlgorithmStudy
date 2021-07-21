//���� 1250 DFS�� BFS https://www.acmicpc.net/problem/1260
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
	int n, m, v; // ������ ����, ������ ����, Ž���� ������ ����
	set<int>* graph; // set���� graph�� �����ϹǷν� �ߺ� ���� ���� �� Ž�� ���� ����
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

		graph[tmp1 - 1].insert(tmp2-1);  // 0�� index�� 1�� ����ִٸ� 1���� 2���� ����Ǿ� �ִٴ� ��
		graph[tmp2 - 1].insert(tmp1 - 1); //�׷����� ������̹Ƿ� ����� ���� ó��
	}

	DFS(graph, visited_dfs, v-1);
	cout << "\n";
	BFS(graph, visited_bfs, v - 1);

	return 0;
}