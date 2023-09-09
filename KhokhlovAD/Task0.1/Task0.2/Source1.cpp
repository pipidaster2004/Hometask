#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "Header1.h"

using namespace std;

int main() {
	int n = vvod1();
	float* mas = new float[n];
	mas = masssiv1(n);
	pechat1(mas, n);
	replace1(mas, n);
	pechat1(mas, n);
	delete[] mas;
	return 0;
}