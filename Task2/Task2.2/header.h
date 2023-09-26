#ifndef _HEAD_
#define _HEAD_
#include <iostream>

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
	friend std::istream& operator>>(std::istream& in, Vector<T> vec);
	friend std::ostream& operator<<(std::ostream& out,const Vector<T> vec);
};

template <class T>
Vector<T>::Vector(const Vector<T>& obj) {
	size = odj.size;
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

#endif
