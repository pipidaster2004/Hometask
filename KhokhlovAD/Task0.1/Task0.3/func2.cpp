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

void replace2(int*& a, int& z) {
	int n = z;
	int cnt = 0;
	for (int m = 0; m < n; m++) {
		for (int i = m + 1; i < n; i++) {
			if (a[m] == a[i]) {
				for (int k = i; k < n - 1; k++) {
					a[k] = a[k + 1];
				}
				n--;
				cnt++;


			}
		}
	}
	int* mas = new int[z - cnt];
	for (int i = 0; i < z - cnt; i++) {
		mas[i] = a[i];
	}
	z = z - cnt;
	delete[] a;
	a = new int[z];
	for (int i = 0; i < z; i++) {
		a[i] = mas[i];
	}
	delete[] mas;
}