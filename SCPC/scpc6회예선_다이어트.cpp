#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		int num_menu, days, cal_max;

		priority_queue<int, vector<int>, greater<int>> cal_A_up; //A 오름차순
		stack<int> cal_A_down;
		priority_queue<int, vector<int>, greater<int>> cal_B; //B 오름차순
		priority_queue<int, vector<int>, less<int>> cal_total;//합계 내림차순
		cin >> num_menu;
		cin >> days;

		int tmp = 0;
		for (int i = 0; i < num_menu; i++) {
			cin >> tmp;
			cal_A_up.push(tmp)
;		}
		for (int i = 0; i < days; i++) { //A를 내림차순으로 반전 단 날짜 수 만큼만  ( 즉 칼로리 중에서 작은 순으로 날짜 수만큼 추출)
			cal_A_down.push(cal_A_up.top());
			cal_A_up.pop()
;		}
		for (int i = 0; i < num_menu; i++) {
			cin >> tmp;
			cal_B.push(tmp);
		}
		for (int i = 0; i < days; i++) {//A와 B가 각각 내림차순 오름차순으로 더해짐 이중에서 가장 큰 수가 최대값을 최소로 한 값임
			cal_total.push(cal_A_down.top() + cal_B.top());
			cal_A_down.pop();
			cal_B.pop();
		}
		Answer =  cal_total.top();
		/*for (int i = 0; i < num_menu; i++) {
			cout << " A : " << cal_A[i] << " B : " << cal_B[i];
		}*/
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}