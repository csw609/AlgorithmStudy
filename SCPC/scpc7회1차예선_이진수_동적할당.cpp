#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, t;
		char* A;
		char* B;

		cin >> n; cin >> t;
		A = new char[n + 1]{};
		B = new char[n + 2]{};

		cin >> B + 1;
		
		//��Ģ�� ���� �ݵ�� �����Ǵ� �ڸ� ó��
		for (int i = 1; i < t + 1 && i + t < n + 1; i++) {
			A[i + t] = B[i];
		}
		for (int i = n; i > n - t && i - t > 0; i--) {
			A[i - t] = B[i];
		}

		//0�� ������ �ִ� �� ���� ��� �ݵ�� 0�̹Ƿ� ��ó��
		for (int i = 1; i < n; i++) { 
			if (B[i] == '0') {
				if (i > t && i < n - t + 1) {
					A[i + t] = B[i];
					A[i - t] = B[i];
				}
			}
		}

		//ù Ž������ �ݵ�� 1�� �־���ϴ� �ڸ� ó��
		for (int i = 1 + t; i < n - t + 1; i++) {
			if (B[i] == '1') {

				if (A[i - t] == NULL && A[i + t] == '0') {
					A[i - t] = '1';
				}

				else if (A[i - t] == '0' && A[i + t] == NULL) {
					A[i + t] = '1';
				}
			}
		}

		//�ι�° �ڸ������� ���� ���� ���� �� �ֵ��� ó��
		for (int i = 1 + t; i < n - t + 1; i++) {
			if (B[i] == '1') {// B�� 1�� ��� => ������ �ִ� �� �ڸ��� �ϳ��� �ݵ�� 1�̴�.
				if (A[i - t] == NULL && A[i + t] == NULL) {// �Ѵ� �� �ڸ��̸� ū �ڸ��� 0 ���� �ڸ��� 1
					A[i - t] = '0';
					A[i + t] = '1';
				}
				else if (A[i - t] == NULL && A[i + t] == '1') {//1�� �̹� �ִ� ��� ������ �ڸ� 0
					A[i - t] = '0';
				}
				else if (A[i - t] == NULL && A[i + t] == '0') {//0�� �̹� �ִ� ��� ������ �ڸ� 1
					A[i - t] = '1';
				}
				else if (A[i - t] == '1' && A[i + t] == NULL) {//1�� �̹� �ִ� ��� ������ �ڸ� 0
					A[i + t] = '0';
				}
				else if (A[i - t] == '0' && A[i + t] == NULL) {//0�� �̹� �ִ� ��� ������ �ڸ� 1
					A[i + t] = '1';
				}
				
			}
		}

		//���� �߷��� �� ���� ��� 0�� �� ���� ����̹Ƿ� 0���� ó��
		for (int i = 1; i < n + 1; i++) {
			if (A[i] == NULL) {
				A[i] = '0';
			}
		}

		cout << "Case #" << test_case + 1 << endl;
	
		for (int i = 1; i < n + 1; i++) {
			cout << A[i];
		}
		cout << '\n';

		delete[] A;
		delete[] B;
	}

	return 0;//Your program should return 0 on normal termination.
}