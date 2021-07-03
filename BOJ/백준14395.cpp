//백준 14395 4연산 - https://www.acmicpc.net/problem/14395
#include <iostream>
#include<string>
#include<vector>
using namespace std;

char* result = new char[35];

int find(unsigned long int x, char op, vector<char> res, int& g_t, int& m, int size) {
	res.push_back(op);
	if (x > g_t || size >= m) {
		return -1;
	}
	else if (x == g_t && size < m) {
		m = size;
		for (int i = 0; i < size; i++) {
			result[i] = res[i];
		}
		return -1;
	}
	else if (size > 31) {
		return -1;
	}
	else {
		find(x * x, '*', res, g_t, m, size + 1);
		find(x + x, '+', res, g_t, m, size + 1);
	}
	return -1;
}

int main() {
	unsigned long int s;
	unsigned long int t;
	int tmp = 0;
	int size = 0;
	cin >> s;
	cin >> t;
	int g_t = t;
	int m = 99;

	vector<char> res;
	if (s == t) {
		cout << 0;
	}
	else  if (t == 0) {
		cout << "-";
	}
	else if (t == 1) {
		cout << "/";
	}
	else {
		find(s * s, '*', res, g_t, m, size+1);
		find(s + s, '+', res, g_t, m, size+1);
		find(1, '/', res, g_t, m, size+1);
		if (m != 99) {
			for (int i = 0; i < m; i++) {
				cout << result[i];
			}
		}
		else {
			cout << "-1";
		}
	}
	delete[] result;
}