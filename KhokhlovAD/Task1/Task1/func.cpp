#include <iostream>
#include<math.h>
#include "Vector.h"

using namespace std;

TVector::TVector() {
	x = 0;
	y = 0;
	z = 0;
}

TVector::TVector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

TVector::TVector(const TVector& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}


float TVector::Lenght() {
	return sqrt(x * x + y* y + z * z);
}

float TVector::Cosin(TVector vec) {
	return (x * vec.x + y * vec.y + z * vec.z) / (Lenght() * vec.Lenght());
}


ostream& operator<<(std::ostream& out, const TVector& vec) {
	out << "x=" << vec.x << " " << "y=" << vec.y << " " << "z=" << vec.z<< endl;
	return out;
}

istream& operator>>(std::istream& in, TVector& vec) {
	in >> vec.x >> vec.y >> vec.z;
	return in;
}

float TVector::operator*(TVector vec) {
	return (Lenght()) * (vec.Lenght() * Cosin(vec));
}

TVector TVector::operator-(const TVector& vec) {
	return TVector(x - vec.x, y - vec.y, z - vec.z);
}

TVector TVector::operator+(const TVector& vec) {
	return TVector(x + vec.x, y + vec.y, z + vec.z);
}

const TVector& TVector::operator=(const TVector& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return  (*this);
}