#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int row, col;

	cin >> row; 
	cin >> col;

	int arr[300][300];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}

	int rep = 0;
	cin >> rep;

	
	for (int i = 0; i < rep; i++) {
		int row1, col1, row2, col2;

		cin >> row1;
		cin >> col1;
		cin >> row2; 
		cin >> col2;

		int sum = 0;
		row1--;
		col1--;
		row2;
		col2;
		for (int i = row1; i < row2; i++) {
			for (int j = col1; j < col2; j++) {
				sum += arr[i][j];
			}
		}

		cout << sum << "\n";
	}

	return 0;
}