#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Date;
class Time;
class Date {
private:
	int y, m, d;
public:
	Date(int yy, int mm, int dd);
	friend void display(const Date &d, const Time &t);
};
Date::Date(int yy, int mm, int dd) {
	y = yy; m = mm; d = dd;
}
class Time {
private:
	int h, m, s;
public:
	Time(int hh, int mm, int ss);
	friend void display(const Date &d, const Time &t);
};
Time::Time(int hh, int mm, int ss) {
	h = hh; m = mm; s = ss;
}

void display(const Date &d, const Time &t) {
	// printf("2017-03-03 19:05:18")
	printf("%d-%02d-%02d %02d:%02d:%02d\n", d.y, d.m, d.d, t.h, t.m, t.s);
}

int main() {
	int t; scanf("%d", &t);
	int h, m, d, hh, mm, ss;
	while (t--) {
		cin >> h >> m >> d >> hh >> mm >> ss;
		Date date(h, m, d);
		Time tim(hh, mm, ss);
		display(date, tim);
	}

    return 0;
}