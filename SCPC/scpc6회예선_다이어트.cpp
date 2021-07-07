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

		priority_queue<int, vector<int>, greater<int>> cal_A_up; //A ��������
		stack<int> cal_A_down;
		priority_queue<int, vector<int>, greater<int>> cal_B; //B ��������
		priority_queue<int, vector<int>, less<int>> cal_total;//�հ� ��������
		cin >> num_menu;
		cin >> days;

		int tmp = 0;
		for (int i = 0; i < num_menu; i++) {
			cin >> tmp;
			cal_A_up.push(tmp)
;		}
		for (int i = 0; i < days; i++) { //A�� ������������ ���� �� ��¥ �� ��ŭ��  ( �� Į�θ� �߿��� ���� ������ ��¥ ����ŭ ����)
			cal_A_down.push(cal_A_up.top());
			cal_A_up.pop()
;		}
		for (int i = 0; i < num_menu; i++) {
			cin >> tmp;
			cal_B.push(tmp);
		}
		for (int i = 0; i < days; i++) {//A�� B�� ���� �������� ������������ ������ ���߿��� ���� ū ���� �ִ밪�� �ּҷ� �� ����
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