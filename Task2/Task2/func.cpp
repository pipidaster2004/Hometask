#include "header.h"


using namespace std;

Group::Group() {
	gruppa = nullptr;
	count = 0;
}

Group::Group(int nCnt) {
	gruppa = new Student[nCnt];
	count = nCnt;
}

Group::Group(Student* nSt, int nCnt) {
	gruppa = new Student[nCnt];
	count = nCnt;
	for (int i = 0; i < nCnt; i++) {
		gruppa[i] = nSt[i];
	}
}

Group::Group(const Group& nGrp) {
	gruppa = new Student[nGrp.count];
	count = nGrp.count;
	gruppa = nGrp.gruppa;
}

Group::~Group() {
	delete[] gruppa;
}


const Group& Group::operator=(const Group& nGrp) {
	if (count != nGrp.count)
		throw "different number of students";
	delete[] gruppa;
	count = nGrp.GetCount();
	gruppa = new Student [count];
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

int Group::SearchStudent(const FIO& st) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].name.name == st.name) && (gruppa[i].name.name == st.surname) && (gruppa[i].name.patronimic == st.patronimic))
			return i;
	cout << "student not found";
	return -1;
}

int Group::SearchStudent(const BD& st) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].data.day == st.day) && (gruppa[i].data.month == st.month) && (gruppa[i].data.year == st.year))
			return i;
	cout << "student not found";
	return -1;
}

int Group::SearchStudent(const unsigned long phNumber) {
	for (int i = 0; i < count; i++)
		if ((gruppa[i].phNumber == phNumber))
			return i;
	cout << "student not found";
	return -1;
}

void Group::AddStudent(const Student& nSt) {
	count++;
	Student* newGroup = new Student[count];
	for (int i = 0; i < count - 1; i++) {
		newGroup[i] = gruppa[i];
	}
	newGroup[count - 1] = nSt;
	delete[] gruppa;
	gruppa = new Student[count];
	for (int i = 0; i < count; i++) {
		gruppa[i] = newGroup[i];
	}
	delete[] newGroup;
}

void Group::DelStudent(const Student& St) {
	count--;
	int ind = SearchStudent(St.name);
	if (ind == -1)
		throw "invalid stuident";
	gruppa[ind] = gruppa[count];
	Student* newGroup = new Student [count];  
	for (int i = 0; i < count; i++) {
		newGroup[i] = gruppa[i];
	}
	delete[] gruppa;
	gruppa = new Student[count];
	for (int i = 0; i < count; i++) {
		gruppa[i] = newGroup[i];
	}
	delete[] newGroup;
}

void Group::DelStudent(int ind) {
	if (ind >= count)
		throw "invalid index";
	count--;
	gruppa[ind] = gruppa[count];
	Student* newGroup = new Student[count];
	for (int i = 0; i < count; i++) {
		newGroup[i] = gruppa[i];
	}
	delete[] gruppa;
	gruppa = new Student[count];
	for (int i = 0; i < count; i++) {
		gruppa[i] = newGroup[i];
	}
	delete[] newGroup;
}

istream& operator>>(std::istream& in, Group& nGrp) {
	cout << "enter cout of student -> ";
	int cnt;
	in >> cnt;
	if (nGrp.count != 0)
		delete[] nGrp.gruppa;
	nGrp.gruppa = new Student[cnt];
	nGrp.count = cnt;
	for (int i = 0; i < nGrp.count; i++) {
		in >> nGrp.gruppa[i];
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

istream& operator>>(istream& in, BD& data) {
	cout << "enter day of birth: day month year -> ";
	in >> data.day >> data.month >> data.year;
	if (data.day > 31 || data.month > 12)
		throw "invalid data";
	return in;
}

istream& operator>>(istream& in, Student& nSt) {
	in >> nSt.name >> nSt.data;
	cout << "enter phone number -> ";
	in >> nSt.phNumber;
	return in;
}

istream& operator>>(istream& in, FIO& fio)
{
	cout << "enter FIO: name surname patronimic -> ";
	in >> fio.name;
	in >> fio.surname;
	in >> fio.patronimic;
	return in;
};