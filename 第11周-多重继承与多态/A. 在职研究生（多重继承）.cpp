#include <bits/stdc++.h>

using namespace std;

class CPeople {
protected:
	string name;
	char sex;
	int age;
public:
	CPeople(string na, char s, int a): name(na), sex(s), age(a) {}
	void print() {
		cout << "Name: " << name << "\n";
		cout << "Sex: " << sex << "\n";
		cout << "Age: " << age << "\n";
	}
};
class CStudent: public CPeople {
protected:
	string no;
	double score;
public:
	CStudent(string na, char se, int a, string n, double sc):
		CPeople(na, se, a), no(n), score(sc) {}
	void print() {
		CPeople::print();
		cout << "No.: " << no << "\n";
		printf("Score: %.1lf\n", score);
	}
};
class CTeacher: public CPeople {
protected:
	string position, department;
public:
	CTeacher(string na, char se, int ag, string po, string de):
		CPeople(na, se, ag), position(po), department(de) {}
	void print() {
		CPeople::print();
		cout << "Position: " << position << "\n";
		cout << "Department: " << department << "\n";
	}
};
class CGradOnWork: public CStudent, public CTeacher {
protected:
	string direction, tutor;
public:
	CGradOnWork(string na, char se, int ag, 
		string n, double sc, string po, string de, string di, string tu): 
		CStudent(na, se, ag, n, sc),
		CTeacher(na, se, ag, po, de),
		direction(di), tutor(tu) {}
	void print() {
		CStudent::print();
		cout << "Position: " << position << "\n";
		cout << "Department: " << department << "\n";
		cout << "Direction: " << direction << "\n";
		cout << "Tutor: " << tutor << "\n";
	}
};

int main() {
	string name;
	char sex;
	int age;
	cin >> name >> sex >> age;
	CPeople cp(name, sex, age);
	cout << "People:\n"; cp.print(); cout << "\n";
	string no;
	double score;
	cin >> no >> score;
	CStudent cs(name, sex, age, no, score);
	cout << "Student:\n"; cs.print(); cout << "\n";
	string position, department;
	cin >> position >> department;
	CTeacher ct(name, sex, age, position, department);
	cout << "Teacher:\n"; ct.print(); cout << "\n";
	string direction, tutor;
	cin >> direction >> tutor;
	CGradOnWork cg(name, sex, age, no, score, position, department, direction, tutor);
	cout << "GradOnWork:\n"; cg.print();

	return 0;
}