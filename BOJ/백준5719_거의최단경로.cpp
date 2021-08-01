//백준 5719 https://www.acmicpc.net/problem/5719
#include <iostream>
#include <set>
//#include <stack>
#include <queue>
#include <vector>
//#include <algorithm>
//#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cost[500]{};
	bool visited[500]{};
	int ways[500][500]{};
	vector<pair<int, int>> path[500];
	int n, m;
	int s, d;
	
	while (1) {
		
		cin >> n; cin >> m;
		

		if (n == 0 && m == 0) {
			break; //종료조건
		}
		cin >> s; cin >> d;
		
		for (int i = 0; i < n; i++) {
			path[i].clear();
			//graph[i].clear();
			for (int j = 0; j < n; j++) {
				ways[i][j] = 0;
			}
			cost[i] = 99999999;
			visited[i] = false;
		}

		int tmp1, tmp2, tmp3;
		for (int i = 0; i < m; i++) {
			cin >> tmp1; cin >> tmp2; cin >> tmp3;
			ways[tmp1][tmp2] = tmp3;//[출발][도착] = 비용
		}

		priority_queue<int,vector<int>,greater<int>> search;

		int tmp, cur;

		cost[s] = 0; //시작 지점 비용 0으로 설정
		search.push(s);// 시작 지점 탐색 큐에 삽입

		while (!search.empty()) {// 큐가 다 비워지면 종료
			tmp = search.top(); // 현재 노드
			search.pop();

			for(int i = 0; i < n; i++) {
				if (ways[tmp][i] == 0) continue; //간선이 없는 경우
				cur = i;

				if (cost[cur] > cost[tmp] + ways[tmp][i]) { //알려진 도착노드까지의 최소 비용 > 현재노드까지의 비용 + 도착 노드까지의 비용

					cost[cur] = cost[tmp] + ways[tmp][i]; //비용 갱신
					search.push(cur); //갱신되었으므로 탐색 목록에 추가
					path[cur].clear();//경로 저장 공간 초기화
					path[cur].push_back({ ways[tmp][i],tmp });//경로 저장
				}
				else if (cost[cur] == cost[tmp] + ways[tmp][i]) {
					path[cur].push_back({ ways[tmp][i],tmp });//경로 저장
				}
			}

		}
		
		queue<int> close;
		close.push(d);

		while (!close.empty()) {
			tmp = close.front(); //도착 지점
			visited[tmp] = true;
			auto iter = path[tmp].begin();
			while (iter != path[tmp].end()) {
				tmp1 = (*iter).second; //출발 지점
				tmp2 = (*iter).first; // 비용

				ways[tmp1][tmp] = 0; //경로 삭제
				if (visited[tmp1] == false) {	//순환 방지
					close.push(tmp1); //탐색 큐에 삽입
				}
				iter++;
			}
			close.pop();
		}
		//최단 경로 제거 완료


		for (int i = 0; i < n; i++) {
			cost[i] = 99999999;
		}

		cost[s] = 0; //시작 지점 비용 0으로 설정
		search.push(s);// 시작 지점 탐색 큐에 삽입

		while (!search.empty()) {// 큐가 비거나 
			tmp = search.top(); // 현재 노드
			search.pop();

			for (int i = 0; i < n; i++) {
				if (ways[tmp][i] == 0) continue;
				cur = i;

				if (cost[cur] > cost[tmp] + ways[tmp][cur]) {//알려진 도착노드까지의 최소 비용 > 현재노드까지의 비용 + 도착 노드까지의 비용
					cost[cur] = cost[tmp] + ways[tmp][cur];//비용 갱신
					search.push(cur);//갱신되었으므로 탐색 목록에 추가
				}
			}
		}

		if (cost[d] == 99999999) {//길이 없는 경우
			cout << -1 << endl;;
			continue;
		}
		else {
			cout << cost[d] << endl;
		}
	}
	return 0;
}