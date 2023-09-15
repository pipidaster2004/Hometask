#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header2.h"

using namespace std;

int* masssiv2(int n) {
	int* mas = new int[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = rand()%10;
	}
	return mas;
}

int vvod2() {
	int n;
	cout << "enter cout of number(0.3)" << endl;
	cin >> n;
	cout << endl;
	return n;
}

void pechat2(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}

void replace2(int* a, int*& b, int z, int& k) {
	int cnt = 0;
	for (int m = 0; m < z; m++) {
		for (int i = m - 1; i >=0; i--) {
			if (a[m] == a[i]) {
				cnt++;
				break;
			}
			
		}
	}
	k =z - cnt;
	cout << k <<  endl << endl;
	b = new int[k];
	cnt = 0;
	b[cnt++] = a[cnt];
	for (int i = 1; i < z; i++) {
		int flag = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] == b[j]) {
				flag++;
				break;
			}
		}
		if (flag == 0)
			b[cnt++] = a[i];
	}
}