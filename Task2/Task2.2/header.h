#ifndef _HEAD_
#define _HEAD_
#include <iostream>
#include <math.h>

template <class T>
class Vector {
private:
	T* vec;
	int size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector<T>& obj);
	
	double Lenght()const;

	Vector <T> operator+(const Vector<T>& obj);
	Vector <T> operator-(const Vector<T>& obj);
	double operator*(const Vector<T>& obj)const;
	bool operator==(const Vector<T>& obj)const;
	bool operator!=(const Vector<T>& obj)const;
	Vector<T>& operator=(const Vector<T>& obj);
	friend std::istream& operator>>(std::istream& in, Vector<T>& vec);
	friend std::ostream& operator<<(std::ostream& out,const Vector<T> vec);
};

template <class T>
Vector<T>::Vector(const Vector<T>& obj) {
	size = obj.size;
	vec = new T[size];
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
}

template <class T>
Vector<T>::Vector(int size) {
	this->size = size;
	vec = new T[size];
}

template <class T>
Vector<T>::Vector() {
	size = 0;
}

template <class T>
double Vector<T>::Lenght()const {
	double res = 0;
	for (int i = 0; i < size; i++) {
		res += vec[i] * vec[i];
	}
	res = sqrt(res);
	return res;
}

template <class T>
Vector <T> Vector<T>::operator+(const Vector<T>& obj) {
	if (size != obj.size) {
		throw;
	}
	for (int i = 0; i < size; i++) {
		vec[i] += obj.vec[i];
		}
	return *this;
}

template <class T>
Vector <T> Vector<T>::operator-(const Vector<T>& obj) {
	if (size != obj.size) {
		throw;
	}
	for (int i = 0; i < size; i++) {
		vec[i] -= obj.vec[i];
	}
	return *this;
}

template <class T>
double Vector<T>::operator*(const Vector<T>& obj)const {
	double res = 0;
	if (size != obj.size)
		throw;
	for (int i = 0; i < size; i++) {
		res += vec[i] * obj.vec[i];
	}
	return res;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& obj)const {
	int flag = 0;
	if (size != obj.size)
		throw;
	for (int i = 0; i < size; i++) {
		if (vec[i] != obj.vec[i]) {
			flag++;
			break;
		}
	}
	if (flag == 0)
		return true;
	return false;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& obj)const {
	return !(this == obj);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {
	if (this == obj)
		return this;
	if (size != obj.size) {
		delete[] vec;
		size = obj.size;
		vec = new T[size];
	}
	for (int i = 0; 0 < size; i++) {
		vec[i] = obj.vec[i];
	}
	return (*this);
}


template <class T>
std::istream& operator>>(std::istream& in, Vector<T>& vec) {
	//std::cout << "size = ";
	in >> vec.size;
	//std::cout << std::endl;
	vec.vec = new T[vec.size];
	for (int i = 0; i < vec.size; i++) {
		//std::cout << "vec[" << i << "] = ";
		in >> vec.vec[i];
		//std::cout << std::endl;
	}
	return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T> vec) {
	out << "size = " << vec.size << std::endl;
	for (int i = 0; i < vec.size; i++) {
		out << "vec[" << i << "] = " << vec.vec[i] << std::endl;
	}
	return out;
}
#endif
