#include <iostream>

using namespace std;

class Date {
protected:
	int year, month, day;
public:
	Date() {}
	Date(int y, int m, int d): year(y), month(m), day(d) {}
};

class Time {
protected:
	int hour, minute, second;
public:
	Time() {}
	Time(int hh, int mm, int ss) : hour(hh), minute(mm), second(ss) {}
};

class Work: public Date, public Time {
private:
	int id;
public:
	Work() {}
	Work (int i, int y, int m, int d, int hh, int mm, int ss):
		Date(y, m, d), Time(hh, mm, ss), id(i) {}
	void set(const Work& w) {
		year = w.year; month = w.month; day = w.day;
		hour = w.hour; minute = w.minute; second = w.second;
		id = w.id;
	}
	friend bool before(const Work& w1, const Work& w2) {
		if (w1.year < w2.year) return 1;
		else if (w1.year > w2.year) return 0;
		if (w1.month < w2.month) return 1;
		else if (w1.month > w2.month) return 0;
		if (w1.day < w2.day) return 1;
		else if (w1.day > w2.day) return 0;
		if (w1.hour < w2.hour) return 1;
		else if (w1.hour > w2.hour) return 0;
		if (w1.minute < w2.minute) return 1;
		else if (w1.minute > w2.minute) return 0;
		if (w1.second < w2.second) return 1;
		else if (w1.second > w2.second) return 0;
		return 0;
	}
	void print() {
		cout << "No." << id << ": ";
		printf("%02d/%02d/%02d ", year, month, day);
		printf("%02d:%02d:%02d", hour, minute, second);
	}
};

int main()
{
	int id, year, month, day, hh, mm, ss;
	bool first = 1;
	Work answ;
	while (cin >> id) {
		if (id == 0) break;
		cin >> year >> month >> day >> hh >> mm >> ss;
		Work w(id, year, month, day, hh, mm, ss);
		if (first) {
			first = 0;
			answ.set(w);
		}
		else
			if (before(w, answ)) answ.set(w);
	}
	cout << "The urgent Work is ";
	answ.print();
}