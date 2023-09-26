#ifndef _HEAD_
#define _HEAD_
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;

struct FIO {
	string name;
	string surname;
	string patronimic;
};

struct BD {
	int day;
	int month;
	int year;
};

struct Student {
	FIO name;
	BD data;
	unsigned long phNumber;
	const Student& operator=(const Student& nSt);
};

class Group {
private:
	Student* gruppa;
	int count;
public:
	Group();
	Group(Student* nSt, int nCnt);
	Group(int nCnt);
	Group(const Group& nGrp);

	~Group();

	void AddStudent(Student nSt);
	void DelStudent(Student St);
	void DelStudent(int ind);

	int SearchStudent(FIO st);
	int SearchStudent(BD st);
	int SearchStudent(unsigned long phNumber);

	int GetCount()const { return count; };

	const Group& operator=(const Group& nGrp);
	friend std::istream& operator>>(std::istream& in, Group& nGrp);
	friend std::ostream& operator<<(std::ostream& out, const Group& nGrp);
};
#endif