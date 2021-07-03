#include <iostream>
#include<algorithm>
//#include <string>
#include <vector>
//#include <stack>
//#include<list>

using namespace std;

int func(vector<int> vec, int lev) {
    int* en = new int[lev-2];
    if (lev > 3) {
        for (int i = 1; i < lev - 1; i++)
        {
            vector<int> tmp(vec);
            vector<int>::iterator it;

            en[i-1] = tmp[i - 1] * tmp[i + 1];

            it = tmp.begin();
            for (int j = 0; j < i; j++)
                it++;
            tmp.erase(it);

            en[i-1] += func(tmp, lev-1);
        }
        int max = *max_element(en, en + lev - 2);
        return max;
    }
    else {
        return vec[0] * vec[2];
    }
}

int main() {
    int num;
    cin >> num;
    vector<int> vec;
    int tmp;
    
    for (int i = 0; i < num; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    cout << func(vec, num);

}