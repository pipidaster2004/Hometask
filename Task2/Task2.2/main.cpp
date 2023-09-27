#include "header.h"

using namespace std;

int main() {
	Vector<int> A(3);
	Vector<int> B(3);
	cin >> A;
	cin >> B;
	cout << A * B << endl << A + B;
	return 0;
}