#include <time.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header2.h"

using namespace std;

int main() {
	int newMasLen = 0;
	int masLen = vvod2();
	int* mas = new int[masLen];
	int* newMas;
	mas = masssiv2(masLen);
	pechat2(mas, masLen);
	replace2(mas, newMas, masLen, newMasLen);
	pechat2(newMas, newMasLen);
	delete[] mas;
	delete[] newMas;
	return 0;
}