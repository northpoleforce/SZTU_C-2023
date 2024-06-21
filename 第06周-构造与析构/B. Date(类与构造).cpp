#include <bits/stdc++.h>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
private:
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};

Date::Date() {
	year = 1900;
	month = 1;
	day = 1;
}
Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
void Date::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
void Date::print() {
	printf("%d/%02d/%02d\n", year, month, day);
}
void Date::addOneDay() {
	days[2] = 28;
	if (year%400 == 0 || (year%100 != 0 && year%4 == 0))
		days[2] = 29;
	day++;
	if (day > days[month]) {
		month++;
		day = 1;
	}
	if (month > 12) {
		year++;
		month = 1;
	}
}

int main() {
	int t; scanf("%d", &t);
	int y, m, d;
	for (int i = 1; i <= t; ++i) {
		scanf("%d%d%d", &y, &m, &d);
		Date da;
		if (i%2) {
			da = Date(y, m, d);
		} else {
			da.setDate(y, m, d);
		}
		printf("Today is "); da.print();
		da.addOneDay();
		printf("Tomorrow is "); da.print();
	}

	return 0;
}