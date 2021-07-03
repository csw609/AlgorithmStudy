//백준 11003 최솟값찾기 - https://www.acmicpc.net/problem/11003

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
	int N, L;

	cin >> N; cin >> L;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  pq;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push(make_pair(tmp, i));
		while (pq.top().second < i - L + 1) {
			pq.pop();	
		}
		cout << pq.top().first << " ";
	}
}