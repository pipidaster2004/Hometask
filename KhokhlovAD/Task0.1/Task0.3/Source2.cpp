#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header2.h"

using namespace std;

int main() {
	int n = vvod2();
	int* mas = new int[n];
	mas = masssiv2(n);
	pechat2(mas, n);
	replace2(mas, n);
	pechat2(mas, n);
	delete[] mas;
	return 0;
}