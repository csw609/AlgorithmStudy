//���� 5719 https://www.acmicpc.net/problem/5719
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
			break; //��������
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
			ways[tmp1][tmp2] = tmp3;//[���][����] = ���
		}

		priority_queue<int,vector<int>,greater<int>> search;

		int tmp, cur;

		cost[s] = 0; //���� ���� ��� 0���� ����
		search.push(s);// ���� ���� Ž�� ť�� ����

		while (!search.empty()) {// ť�� �� ������� ����
			tmp = search.top(); // ���� ���
			search.pop();

			for(int i = 0; i < n; i++) {
				if (ways[tmp][i] == 0) continue; //������ ���� ���
				cur = i;

				if (cost[cur] > cost[tmp] + ways[tmp][i]) { //�˷��� ������������ �ּ� ��� > ����������� ��� + ���� �������� ���

					cost[cur] = cost[tmp] + ways[tmp][i]; //��� ����
					search.push(cur); //���ŵǾ����Ƿ� Ž�� ��Ͽ� �߰�
					path[cur].clear();//��� ���� ���� �ʱ�ȭ
					path[cur].push_back({ ways[tmp][i],tmp });//��� ����
				}
				else if (cost[cur] == cost[tmp] + ways[tmp][i]) {
					path[cur].push_back({ ways[tmp][i],tmp });//��� ����
				}
			}

		}
		
		queue<int> close;
		close.push(d);

		while (!close.empty()) {
			tmp = close.front(); //���� ����
			visited[tmp] = true;
			auto iter = path[tmp].begin();
			while (iter != path[tmp].end()) {
				tmp1 = (*iter).second; //��� ����
				tmp2 = (*iter).first; // ���

				ways[tmp1][tmp] = 0; //��� ����
				if (visited[tmp1] == false) {	//��ȯ ����
					close.push(tmp1); //Ž�� ť�� ����
				}
				iter++;
			}
			close.pop();
		}
		//�ִ� ��� ���� �Ϸ�


		for (int i = 0; i < n; i++) {
			cost[i] = 99999999;
		}

		cost[s] = 0; //���� ���� ��� 0���� ����
		search.push(s);// ���� ���� Ž�� ť�� ����

		while (!search.empty()) {// ť�� ��ų� 
			tmp = search.top(); // ���� ���
			search.pop();

			for (int i = 0; i < n; i++) {
				if (ways[tmp][i] == 0) continue;
				cur = i;

				if (cost[cur] > cost[tmp] + ways[tmp][cur]) {//�˷��� ������������ �ּ� ��� > ����������� ��� + ���� �������� ���
					cost[cur] = cost[tmp] + ways[tmp][cur];//��� ����
					search.push(cur);//���ŵǾ����Ƿ� Ž�� ��Ͽ� �߰�
				}
			}
		}

		if (cost[d] == 99999999) {//���� ���� ���
			cout << -1 << endl;;
			continue;
		}
		else {
			cout << cost[d] << endl;
		}
	}
	return 0;
}