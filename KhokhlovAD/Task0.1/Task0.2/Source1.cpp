#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "Header1.h"

using namespace std;

int main() {
	int n = vvod();
	float* mas = new float[n];
	mas = masssiv(n);
	pechat(mas, n);
	replace(mas, n);
	pechat(mas, n);
	delete[] mas;
	return 0;
}