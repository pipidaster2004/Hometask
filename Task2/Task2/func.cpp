#include "header.h"


using namespace std;

Group::Group() {
	gruppa = (Student*)malloc(sizeof(Student));
	count = 1;
}

Group::Group(int nCnt) {
	gruppa = (Student*)malloc(sizeof(Student)*nCnt);
	count = nCnt;
}

Group::Group(Student* nSt, int nCnt) {
	gruppa = (Student*)malloc(sizeof(Student) * nCnt);
	count = nCnt;
	for (int i = 0; i < nCnt; i++) {
		gruppa[i] = nSt[i];
	}
}

Group::Group(const Group& nGrp) {
	gruppa = (Student*)malloc(sizeof(Student) * nGrp.count);
	count = nGrp.count;
	gruppa = nGrp.gruppa;
}

Group::~Group() {
	free(gruppa);
}


const Group& Group::operator=(const Group& nGrp) {
	if (count != nGrp.count)
		throw "different number of students";
	free(gruppa);
	count = nGrp.GetCount();
	gruppa = (Student*)malloc(sizeof(Student) * count);
	for (int i = 0; i < count; i++) {
		gruppa[i] = nGrp.gruppa[i];
	}
	return  (*this);
}

const Student& Student::operator=(const Student& nSt) {
	phNumber = nSt.phNumber;
	data.day = nSt.data.day;
	data.month = nSt.data.month;
	data.year = nSt.data.year;
	name.name = nSt.name.name;
	name.surname = nSt.name.surname;
	name.patronimic = nSt.name.patronimic;
	return  (*this);
}

int Group::SearchStudent(FIO st) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].name.name == st.name) && (gruppa[i].name.name == st.surname) && (gruppa[i].name.patronimic == st.patronimic))
			return i;
	cout << "student not found";
	return -1;
}

int Group::SearchStudent(BD st) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].data.day == st.day) && (gruppa[i].data.month == st.month) && (gruppa[i].data.year == st.year))
			return i;
	cout << "student not found";
	return -1;
}

int Group::SearchStudent(unsigned long phNumber) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].phNumber == phNumber))
			return i;
	cout << "student not found";
	return -1;
}

void Group::AddStudent(Student nSt) {
	count++;
	Student* newGroup = (Student*)realloc(gruppa, sizeof(Student) * count);
	gruppa = newGroup;
	gruppa[count-1] = nSt;
}

void Group::DelStudent(Student St) {
	count--;
	int ind = SearchStudent(St.name);
	gruppa[ind] = gruppa[count];
	Student* newGroup = (Student*)realloc(gruppa, sizeof(Student) * count);
	gruppa = newGroup;
}

void Group::DelStudent(int ind) {
	gruppa[ind] = gruppa[count];
	Student* newGroup = (Student*)realloc(gruppa, sizeof(Student) * count);
	gruppa = newGroup;
}

istream& operator>>(std::istream& in, Group& nGrp) {
	cout << "enter cout of student -> ";
	int cnt;
	in >> cnt;
	free(nGrp.gruppa);
	nGrp.gruppa = (Student*)malloc(sizeof(Student)*cnt);
	nGrp.count = cnt;
	for (int i = 0; i < nGrp.count; i++) {
		cout << "enter day of birth: day month year -> ";
		in >> nGrp.gruppa[i].data.day;
		in >> nGrp.gruppa[i].data.month;
		in >> nGrp.gruppa[i].data.year;
		if (nGrp.gruppa[i].data.day > 31 || nGrp.gruppa[i].data.month > 12)
			throw "invalid data";
		cout << "enter FIO: name surname patronimic -> ";
		in >> nGrp.gruppa[i].name.name;
		in >> nGrp.gruppa[i].name.surname;
		in >> nGrp.gruppa[i].name.patronimic;
		cout << "enter phone number -> ";
		in >> nGrp.gruppa[i].phNumber;
	}
	return in;
}

ostream& operator<<(ostream& out, const Group& nGrp) {
	out << "count = " << nGrp.count << endl << endl;
	for (int i = 0; i < nGrp.count; i++) {
		out << "FIO: " << nGrp.gruppa[i].name.name << " " << nGrp.gruppa[i].name.surname << " " << nGrp.gruppa[i].name.patronimic << endl <<
			"BD: " << nGrp.gruppa[i].data.day << " " << nGrp.gruppa[i].data.month << " " << nGrp.gruppa[i].data.year << endl <<
			"Phone number: " << nGrp.gruppa[i].phNumber << endl << endl;
	}
	return out;
}