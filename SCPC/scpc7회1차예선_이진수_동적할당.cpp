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
		
		//규칙에 의해 반드시 고정되는 자리 처리
		for (int i = 1; i < t + 1 && i + t < n + 1; i++) {
			A[i + t] = B[i];
		}
		for (int i = n; i > n - t && i - t > 0; i--) {
			A[i - t] = B[i];
		}

		//0은 영향을 주는 두 변수 모두 반드시 0이므로 선처리
		for (int i = 1; i < n; i++) { 
			if (B[i] == '0') {
				if (i > t && i < n - t + 1) {
					A[i + t] = B[i];
					A[i - t] = B[i];
				}
			}
		}

		//첫 탐색에서 반드시 1이 있어야하는 자리 처리
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

		//두번째 자리에서는 수가 가장 작을 수 있도록 처리
		for (int i = 1 + t; i < n - t + 1; i++) {
			if (B[i] == '1') {// B가 1인 경우 => 영향을 주는 두 자리중 하나는 반드시 1이다.
				if (A[i - t] == NULL && A[i + t] == NULL) {// 둘다 빈 자리이면 큰 자리에 0 작은 자리에 1
					A[i - t] = '0';
					A[i + t] = '1';
				}
				else if (A[i - t] == NULL && A[i + t] == '1') {//1이 이미 있는 경우 나머지 자리 0
					A[i - t] = '0';
				}
				else if (A[i - t] == NULL && A[i + t] == '0') {//0이 이미 있는 경우 나머지 자리 1
					A[i - t] = '1';
				}
				else if (A[i - t] == '1' && A[i + t] == NULL) {//1이 이미 있는 경우 나머지 자리 0
					A[i + t] = '0';
				}
				else if (A[i - t] == '0' && A[i + t] == NULL) {//0이 이미 있는 경우 나머지 자리 1
					A[i + t] = '1';
				}
				
			}
		}

		//값을 추론할 수 없을 경우 0이 더 작은 경우이므로 0으로 처리
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