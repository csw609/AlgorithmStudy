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
		sum = new int[num]; //�ڸ����� �ڿ����� ��
		mask = new bool[num]; //Ž���� ��Ʈ����ũ
		check = new int[num]; //�׷� ǥ��
		stack<int> search; //Ž���� ����
		int tmp;

		int groups = 1; //�׷� 1���� ����

		for (int i = 0; i < num; i++) {
			check[i] = 0;
			mask[i] = true;
			cin >> tmp;
			sum[i] = i + 1 + tmp;
		}


		for (int i = 0; i < num; i++) {
			if (mask[i] == true) {
				search.push(i + 1);	//Ž���� ���ÿ� ����
				mask[i] = false; // ���Ŀ� ù��°�� Ž�� �� �ʿ䰡 �����Ƿ� ȿ������ ó���� ���� ��Ʈ ����ũ ���
				tmp = sum[search.top() - 1];

				while (tmp - 1 < num) {//�������� ����� ģ���� stack�� ����
					search.push(tmp);
					mask[tmp-1] = false;
					tmp = sum[search.top() - 1];
				}
				//cout << "debug" << endl;

				if(check[search.top() - 1] == 0) { // ���� ģ������ ���� 0�̶�� => ���±��� ģ�� �׷� ���� �ȵ� ���Ӱ� ����
					//cout << "debug" << endl;
					while (!search.empty()) {
						check[search.top() - 1] = groups;
						search.pop();
					}
					groups++;
				}
				else {	//�̹� ������ �׷��� �ִٸ� ���ÿ� �ִ� ģ������ ���� �ش� �׷����� ����
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