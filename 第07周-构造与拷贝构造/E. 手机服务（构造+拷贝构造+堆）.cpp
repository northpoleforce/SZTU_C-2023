#include <bits/stdc++.h>

using namespace std;

class DATE {
private:
	int y, m, d;
public:
	DATE() {
		y = m = d = 0;
	}
	DATE(int yy, int mm, int dd) {
		y = yy;
		m = mm;
		d = dd;
	}
	void print() {
		printf("%d.%d.%d", y, m, d);
	}
};

class SIM {
private:
	char type, *number;
	int status;
	DATE *date;
public:
	void print(int c) {
		printf("类型=");
		if (type == 'A') printf("机构");
		if (type == 'B') printf("企业");
		if (type == 'C') printf("个人");
		if (type == 'D') printf("备份");
		printf("||号码=%s", number);
		printf("||State=");
		if (status == 1) printf("在用");
		if (status == 2) printf("未用");
		if (status == 3) printf("停用");
		if (c == 3) {
			printf(" ||停机日期=");
			date->print();	
		}
		printf("\n");
	}
	SIM(char type0, char number0[], int status0, int y, int m, int d) {
		printf("Construct a new phone %s\n", number0);
		type = type0;
		number = new char[12];
		strcpy(number, number0);
		status = status0;
		date = new DATE(y, m, d);
		print(1);
	}
	~SIM() {
		delete[] number;
		delete date;
	}
	SIM(SIM &t) {
		printf("Construct a copy of phone %s\n", t.number);
		type = 'D';
		status = t.status;
		
		// DATE* tdate = t.date;
		date = new DATE(*t.date);

		number = new char[strlen(t.number)+1];
		strcpy(number, t.number);
		number[strlen(t.number)] = 'X';
		print(2);
	}
	void stop() {
		printf("Stop the phone %s\n", number);
		status = 3;
		print(3);
	}
};

int main() {
	int t; scanf("%d", &t);
	char type, number[12];
	int status, y, m, d;
	while (t--) {
		scanf("\n%c%s%d%d%d%d", &type, number, &status, &y, &m, &d);
		// printf("%c %s %d %d %d %d\n", type, number, status, y, m, d);
		SIM s0(type, number, status, y, m, d);
		SIM s1(s0);
		s0.stop();
		printf("----\n");
		// SIM s2(s0);
	}

	return 0;
}