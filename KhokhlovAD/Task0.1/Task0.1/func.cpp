#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header.h"

using namespace std;

float* masssiv(int n) {
	float* mas = new float[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() / (float)RAND_MAX * 20,5;
	}
	return mas;
}

float* raplace(float* a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > 10)
		{
			a[i] = sqrt(a[i]);
		}
	}
	return a;
}

void pechat(float* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}

int vvod() {
	int n;
	cout << "enter cout of number"<< endl;
	cin >> n;
	cout << endl;
	return n;
}
