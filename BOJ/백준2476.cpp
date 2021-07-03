#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;

    char** dice;
    dice = new char* [num];

    for (int i = 0; i < num; i++)
        dice[i] = new char[3];

    for (int j = 0; j < num; j++) {
        for (int i = 0; i < 3; i ++) {
            cin >> dice[j][i];
        }
        sort(dice[j], dice[j] + 3);
    }

    int* money = new int[num];
    for (int i = 0; i < num; i++) {
        if (dice[i][1] == dice[i][0] && dice[i][1] == dice[i][2]) {
            money[i] = 10000 + 1000 * (dice[i][1] - 48);
        }
        else if (dice[i][1] == dice[i][0] || dice[i][1] == dice[i][2]) {
            money[i] = 1000 + 100 * (dice[i][1] - 48);
        }
        else
        {
            money[i] = 100 * (max(max(dice[i][0], dice[i][1]), dice[i][2]) - 48);
        }
        
    }
    sort(money, money + num);
    cout << money[num - 1] << endl;
}