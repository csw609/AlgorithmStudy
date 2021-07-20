#include <iostream>
//#include <vector>
//#include <queue>
#include<stack>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int num;
		int* sum;
		bool* mask;
		int* check;
		cin >> num;
		sum = new int[num]; //자리수와 자연수의 합
		mask = new bool[num]; //탐색용 비트마스크
		check = new int[num]; //그룹 표시
		stack<int> search; //탐색용 스택
		int tmp;

		int groups = 1; //그룹 1부터 시작

		for (int i = 0; i < num; i++) {
			check[i] = 0;
			mask[i] = true;
			cin >> tmp;
			sum[i] = i + 1 + tmp;
		}


		for (int i = 0; i < num; i++) {
			if (mask[i] == true) {
				search.push(i + 1);	//탐색용 스택에 삽입
				mask[i] = false; // 이후에 첫번째로 탐색 될 필요가 없으므로 효율적인 처리를 위해 비트 마스크 사용
				tmp = sum[search.top() - 1];

				while (tmp - 1 < num) {//선형으로 연결된 친구들 stack에 삽입
					search.push(tmp);
					mask[tmp-1] = false;
					tmp = sum[search.top() - 1];
				}
				//cout << "debug" << endl;

				if(check[search.top() - 1] == 0) { // 선형 친구들의 끝이 0이라면 => 여태까지 친구 그룹 배정 안됨 새롭게 배정
					//cout << "debug" << endl;
					while (!search.empty()) {
						check[search.top() - 1] = groups;
						search.pop();
					}
					groups++;
				}
				else {	//이미 배정된 그룹이 있다면 스택에 있는 친구들을 전부 해당 그룹으로 배정
					tmp = check[search.top() - 1];
					while (!search.empty()) {
						check[search.top() - 1] = tmp;
						search.pop();
					}
				}
			}
		}
		/*for (int i = 0; i < num; i++) {
			cout << check[i];
		}
		cout << "\n";*/
		
		Answer = groups-1;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}