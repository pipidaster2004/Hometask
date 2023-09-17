#ifndef _VECTOR_
#define _VECTOR_


class TVector {
private:
	float x;
	float y;
	float z;
public:
	TVector();
	TVector(float x, float y, float z);
	TVector(const TVector& vec);

	float Lenght();
	float Cosin(TVector vec);

	const TVector& operator=(const TVector& vec);
	TVector operator+(const TVector& vec);
	TVector operator-(const TVector& vec);
	float operator*(TVector vec);
	friend std::istream& operator>>(std::istream& in, TVector& vec);
	friend std::ostream& operator<<(std::ostream& out,const TVector& vec);
};

#endif