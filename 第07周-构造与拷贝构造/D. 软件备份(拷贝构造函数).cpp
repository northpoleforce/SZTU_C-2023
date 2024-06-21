#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

class CDate
{
    private:
        int year, month, day;
    public:
        CDate(int y, int m, int d);
        bool isLeapYear();
        int getYear();
        int getMonth();
        int getDay();
        int getDayofYear();
        int judge();
        int calc();
};
int CDate::judge() {
	if (getDayofYear() == 0) return 1;
	if (getYear() < 2015)
		return 2;
	if (getYear() == 2015)
		if (getMonth() < 4) return 2;
		else if (getMonth() == 4 && getMonth() <= 7) return 2;
	return 3;
}
int CDate::calc() {
	if (getYear() == 2015) {
		return getDayofYear()-31-28-31-7;
	} else {
		int sum = 23+31+30+31+31+30+31+30+31;
		for (int i = 2016; i < getYear(); ++i)
			if (i%400 == 0 || (i%100 != 0 && i%4 == 0))
				sum += 366;
			else
				sum += 365;
		sum += getDayofYear();
		return sum;
	}
}
CDate::CDate(int y, int m, int d)
{ 
    year = y, month = m,day = d;
}
bool CDate::isLeapYear()
{ 
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 
}
int CDate::getYear()
{ 
    return year;
}
int CDate::getMonth() 
{ 
    return month;
}
int CDate::getDay() 
{ 
    return day;
}
int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear())
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}

class Software {
private:
	char name[100];
	char type;
	CDate* date;
	char media;
public:
	Software(char name0[], char type0, char media0, int y, int m, int d) {
		strcpy(name, name0);
		type = type0;
		date = new CDate(y, m, d);
		media = media0;
	}
	Software(Software &t) {
		strcpy(name, t.name);
		type = 'B';
		media = 'H';
		date = t.date;
	}
	void print() {
		printf("name:%s\n", name);
		printf("type:");
		if (type == 'O') printf("original\n");
		if (type == 'B') printf("backup\n");
		if (type == 'T') printf("trial\n");
		printf("media:");
		if (media == 'D') printf("optical disk\n");
		if (media == 'H') printf("hard disk\n");
		if (media == 'U') printf("USB disk\n");
		if (date->judge() == 1) printf("this software has unlimited use\n");
		if (date->judge() == 2) printf("this software has expired\n");
		if (date->judge() == 3) printf("this software is going to be expired in %d days\n", date->calc());
		printf("\n");
	}
};

int main() {
	int t; scanf("%d", &t);
	char name[100], type, media;
	int y, m, d;
	while (t--) {
		scanf("%s", name);
		scanf("\n%c %c%d%d%d", &type, &media, &y, &m, &d);
		Software s0(name, type, media, y, m, d);
		s0.print();
		Software s1(s0);
		s1.print();
	}
	return 0;
}