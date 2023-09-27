#ifndef _HEAD_
#define _HEAD_
#include <iostream>
#include <stdlib.h>

using namespace std;


template <typename T>
class Vector {
private:
    int size;      
    T* vec;   

public:
    Vector(int n = 0) {
        size = n;
        vec = new T[size];
    }

    Vector(const Vector<T>& other) {
        size = other.size;
        vec = new T[size];
        for (int i = 0; i < size; i++) {
            vec[i] = other.vec[i];
        }
    }
   
    ~Vector() {
        delete[] vec;
    }

	double Lenght()const {
		double res = 0;
		for (int i = 0; i < size; i++) {
			res += vec[i] * vec[i];
		}
		res = sqrt(res);
		return res;
	}

    Vector<T> operator+(const Vector<T>& other) const {
        if (size != other.size) {
            throw  "Error: Cannot add vectors with different sizes";
        }

        Vector<T> result(size);
        for (int i = 0; i < size; i++) {
            result.vec[i] = vec[i] + other.vec[i];
        }
        return result;
    }

    Vector<T>operator-(const Vector<T>& other) const {
        if (size != other.size) {
            throw  "Error: Cannot add vectors with different sizes";
        }
        Vector<T> result(size);
        for (int i = 0; i < size; i++) {
            result.vec[i] = vec[i] - other.vec[i];
        }
        return result;
    }

	double operator*(const Vector<T>& obj)const {
		double res = 0;
		if (size != obj.size)
			throw;
		for (int i = 0; i < size; i++) {
			res += vec[i] * obj.vec[i];
		}
		return res;
	}


	bool operator==(const Vector<T>& obj)const {
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

	bool operator!=(const Vector<T>& obj)const {
		return !(this == obj);
	}

	Vector<T>& operator=(const Vector<T>& obj) {
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

    int getSize() const {
        return size;
    }

    T getElement(int index) const {
        return vec[index];
    }

    void setElement(int index, const T& value) {
        vec[index] = value;
    }


    template <typename U>
    friend ostream& operator<<(ostream& os, const Vector<U>& vec);

    template <typename U>
    friend istream& operator>>(istream& is, Vector<U>& vec);
};


template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& vec) {
    for (int i = 0; i < vec.getSize(); i++) {
        os << vec.getElement(i) << " ";
    }
    return os;
}


template <typename T>
istream& operator>>(istream& is, Vector<T>& vec) {
    cout << "Input vector ";
    for (int i = 0; i < vec.getSize(); i++) {
        is >> vec.vec[i];
    }
    return is;
}
#endif