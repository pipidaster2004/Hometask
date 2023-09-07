#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header1.h"

using namespace std;

float* masssiv(int n) {
	float* mas = new float[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() / (float)RAND_MAX * 20, 5;
	}
	return mas;
}


void pechat(float* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}

int vvod() {
	int n, flag = 0;
	cout << "enter cout of number" << endl;
	while (flag == 0) {
		cin >> n;
		if (n % 2 != 0)
		{
			cout << "wrong number" << endl;;
		}
		else
			flag++;
	}
	cout << endl;
	return n;
}

float* replace(float* a, int n) {
	if (n % 2 != 0)
		return NULL;
	float* b = new float[n / 2];
	for (int i = 0; i < (n / 2); i++) {
		b[i] = a[i];
	}
	for (int i = n; i >= (n / 2); i--) {
		a[n-i] = a[i];
	}
	for (int i = n / 2; i < n; i++) {
		a[i] = b[i - n/2 - 1];
	}
	return a;
}