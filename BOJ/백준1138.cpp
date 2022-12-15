#include <iostream>
#define OUT 999

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num_of_people;
	int info_of_people[10];
	int table_of_people[10];
	cin >> num_of_people;

	for (int i = 0; i < num_of_people; i++) {
		cin >> info_of_people[i];
	}

	int checker = 0;
	int num = 0;
	for (int j = 0; j < num_of_people; j++) {
		for (int i = 0; i < num_of_people; i++) {
			if (info_of_people[i] == checker) {
				table_of_people[num++] = i + 1;
				info_of_people[i] = OUT;
				break;
			}
			else {
				info_of_people[i]--;
			}
		}
	}

	for (int i = 0; i < num_of_people; i++) {
		cout << table_of_people[i] << " ";        
	}

	return 0;


}