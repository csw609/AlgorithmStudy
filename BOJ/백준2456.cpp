#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string numOfStu;
    cin >> numOfStu;
    int num = stoi(numOfStu);
    cin.ignore();

    char input[6];
    int** score;

    score = new int* [3];
    for (int i = 0; i < 3; i++)
        score[i] = new int[num];



    for (int j = 0; j < num; j++) {
        cin.getline(input, 6);
        for (int i = 0; i < 6; i += 2) {
            score[i / 2][j] = input[i] - 48;
        }
    }

    int point[3][3] = { 0 };
    int pointSum[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < num; j++) {
            if (score[i][j] == 1)
                point[i][0]++;
            else if (score[i][j] == 2)
                point[i][1]++;
            else if (score[i][j] == 3)
                point[i][2]++;

            pointSum[i] += score[i][j];
        }
    }

    int largest =  max(pointSum[0], max(pointSum[1], pointSum[2]));
    vector<int> find;

    //점수 최대값 찾기
    for (int i = 0; i < 3; i++) {
        if (pointSum[i] == largest)
        {
            find.push_back(i);
        }
    }
    //최대값이 1명이면 값 출력
    if (find.size() == 1) {
        cout << find.back() + 1 << " " << pointSum[find.back()];
    }

    else {
        largest = point[find[0]][2];
        vector<int> find2;
        //동점자 중 3의 개수 최대값 추출
        for(int i =0; i < 3; i++) {
            if (point[find[i]][2] > largest) {
                largest = point[find[i]][2];
            }
            if (find[i] == find.back())
                break;
        }

        //3점 개수 같은 사람 추출
        for (int i = 0; i < 3; i++) {
            if (point[find[i]][2] == largest)
            {
                find2.push_back(find[i]);
            }
            if (find[i] == find.back())
                break;
        }
        if (find2.size() == 1) {
            cout << find2.back() + 1 << " " << pointSum[find2.back()];
        } 
        //3점 개수 동점자 발생 할 경우

        else {
            largest = point[find2[0]][1];
            vector<int> find3;
            //2점 개수 최대값 추출
            for (int i = 0; i < 3; i++) {
                if (point[find2[i]][1] > largest) {
                    largest = point[find2[i]][1];
                }
                if (find2[i] == find2.back())
                    break;
            }
            //2점 개수 같은 사람 추출
            for (int i = 0; i < 3; i++) {
                if (point[find2[i]][1] == largest)
                {
                    find3.push_back(find2[i]);
                }
                if (find2[i] == find2.back())
                    break;
            }
            if (find3.size() == 1) {
                cout << find3.back() + 1 << " " << pointSum[find3.back()];
            }
            //2점 개수 까지 같은 경우
            else {
                cout << "0" << " " << pointSum[find[0]];
            }
        }
    }
}