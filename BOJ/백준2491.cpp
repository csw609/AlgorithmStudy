#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string numOfStu;
    cin >> numOfStu;
    int num = stoi(numOfStu);
    cin.ignore();

    char* input = new char[num * 2];
    int* seq = new int[num];

    cin.getline(input, num * 2);

    for (int i = 0; i < num * 2; i += 2) {
        seq[i / 2] = input[i] - 48;
    }

    int* lisSeq = new int[num];
    int* lisSeq2 = new int[num];

    for (int i = 0; i < num; i++) {
        lisSeq[i] = -1;
    }
    for (int i = 0; i < num; i++) {
        lisSeq2[i] = 10;
    }

    int j = 0;
    lisSeq[0] = seq[0];
    for (int i = 1; i < num; i++) {
        if (seq[i] >= lisSeq[j])
        {
            lisSeq[j+1] = seq[i];
            j++;
        }
        else {
            j = 0;
            lisSeq[0] = seq[i];
        }
    }

    lisSeq2[0] = seq[0];
    j = 0;
    for (int i = 1; i < num; i++) {
        if (seq[i] <= lisSeq2[j])
        {
            lisSeq2[j + 1] = seq[i];
            j++;
        }
        else {
            j = 0;
            lisSeq2[0] = seq[i];
        }
    }

    int x = 0;
    int y = 0;
    for (int i = 0; i < num; i++) {
        if (lisSeq[i] == -1)
            break;
        x++;
    }
    for (int i = 0; i < num; i++) {
        if (lisSeq2[i] == 10)
            break;
        y++;
    }
    if (x > y)
        cout << x;
    else
        cout << y;
}