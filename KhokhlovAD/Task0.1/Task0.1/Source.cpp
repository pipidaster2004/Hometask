#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "Header.h"

using namespace std;

int main() {
	int n = vvod();
	float* mas = new float[n];
	mas = masssiv(n);
	pechat(mas, n);
	raplace(mas, n);
	pechat(mas, n);
	delete[] mas;
	return 0;
}