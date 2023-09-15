#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header1.h"

using namespace std;

float* masssiv1(int n) {
	float* mas = new float[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() / (float)RAND_MAX * 20, 5;
	}
	return mas;
}


void pechat1(float* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}

int vvod1() {
	int n, flag = 0;
	cout << "enter cout of number(0.2)" << endl;
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

float* replace1(float* a, int n) {
	if (n % 2 != 0)
		return NULL;
	float tmp;
	for (int i = 0; i < n / 2; i++) {
		tmp = a[i];
		a[i] = a[i + n / 2];
		a[i + n / 2] = tmp;
	}
	return a;
}