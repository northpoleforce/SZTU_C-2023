#include <bits/stdc++.h>

using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	Person() {}
	Person(string na, int ag): name(na), age(ag) {}
	void display() {
		cout << name << " " << age;
	}
};
class Rstudent: public Person {
protected:
	int us, es, fs;
public:
	Rstudent() {}
	Rstudent(string na, int ag, int u, int e):
		Person(na, ag), us(u), es(e) {}
	void display() {
		fs = 0.4*us+0.6*es;
		Person::display();
		cout << " ";
		if (fs >= 85) cout << "A";
		else if (fs >= 75) cout << "B";
		else if (fs >= 65) cout << "C";
		else if (fs >= 60) cout << "D";
		else cout << "F";
		cout << "\n";
	}
};
class Sstudent: public Person {
protected:
	int es, fs;
public:
	Sstudent() {}
	Sstudent(string na, int ag, int e): Person(na, ag), es(e) {}
	void display() {
		fs = es;
		Person::display();
		cout << " ";
		if (fs >= 85) cout << "A";
		else if (fs >= 75) cout << "B";
		else if (fs >= 65) cout << "C";
		else if (fs >= 60) cout << "D";
		else cout << "F";
		cout << "\n";
	}
};

int main() {
	int t; cin >> t;
	while (t--) {
		char type;
		cin >> type;
		string name;
		int age, us, es;
		if (type == 'S') {
			cin >> name >> age >> es;
			Sstudent s(name, age, es);
			s.display();
		} else {
			cin >> name >> age >> us >> es;
			Rstudent s(name, age, us, es);
			s.display();
		}
	}

	return 0;
}