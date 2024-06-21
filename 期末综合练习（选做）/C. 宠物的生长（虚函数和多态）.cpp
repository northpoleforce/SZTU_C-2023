#include <iostream>

using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d) :
		year(y), month(m), day(d) {}
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
};

class Pet
{
protected:
	string name;//姓名
	float length;//身长
	float weight;//体重
	CDate current;//开始记录时间
	//（日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）
public:
	Pet(string na, int len, int wei, int y, int m, int d) :
		name(na), length(len), weight(wei), current(y, m, d) {}
	virtual void display(CDate day) = 0;//输出目标日期时宠物的身长和体重
};

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int calc(CDate st_date, CDate ed_date) {
	//cout << st_date.get_year() << " " << ed_date.get_year() << "yy\n";
	if (ed_date.get_year() < st_date.get_year()) return -1;
	if (ed_date.get_year() == st_date.get_year() &&
		ed_date.get_month() < st_date.get_month()) return -1;
	if (ed_date.get_year() == st_date.get_year() &&
		ed_date.get_month() == st_date.get_month() &&
		ed_date.get_day() < st_date.get_day()) return -1;
	int cnt = 0; int st_m, ed_m, st_d, ed_d;

	for (int y = st_date.get_year(); y <= ed_date.get_year(); ++y) {
		//cout << y << "\n";
		if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) days[2] = 29;
		else days[2] = 28;
		if (st_date.get_year() == y) st_m = st_date.get_month();
		else st_m = 1;
		if (ed_date.get_year() == y) ed_m = ed_date.get_month();
		else ed_m = 12;
		for (int m = st_m; m <= ed_m; ++m) {
			//cout << m << " " << cnt << "\n";
			if (st_date.get_year() == y && st_date.get_month() == m) st_d = st_date.get_day();
			else st_d = 1;
			if (ed_date.get_year() == y && ed_date.get_month() == m) ed_d = ed_date.get_day();
			else ed_d = days[m];
			for (int d = st_d; d <= ed_d; ++d) ++cnt;
			//cout << m << " " << cnt << "\n";
		}
	}
	return cnt - 1;
}

class Cat :public Pet
{
public:
	Cat(string na, int len, int wei, int y, int m, int d) :
		Pet(na, len, wei, y, m, d) {}
	void display(CDate last) {
		int day = calc(last, current);
		if (day == -1) { cout << "error\n"; return; }
		double len = length + 0.1 * day;
		double wei = weight + 0.2 * day;
		cout << name;
		printf(" after %d day: length=%.2lf,weight=%.2lf\n", day, len, wei);
	}
};
class Dog :public Pet
{
public:
	Dog(string na, int len, int wei, int y, int m, int d) :
		Pet(na, len, wei, y, m, d) {}
	void display(CDate last) {
		int day = calc(last, current);
		if (day == -1) { cout << "error\n"; return; }
		double len = length + 0.2 * day;
		double wei = weight + 0.1 * day;
		cout << name;
		printf(" after %d day: length=%.2lf,weight=%.2lf\n", day, len, wei);
	}
};

int main() {
	int t; cin >> t;
	int y, m, d, yy, mm, dd;
	cin >> y >> m >> d;
	CDate last(y, m, d);
	int ty, len, wei;
	string name;
	Pet* pt;
	while (t--) {
		cin >> ty >> name >> len >> wei >> yy >> mm >> dd;
		if (ty == 1) {
			//Cat cat(name, len, wei, yy, mm, dd);
			//pt &= cat;
			pt = new Cat(name, len, wei, yy, mm, dd);
			pt->display(last);
		}
		else {
			//Dog dog(name, len, wei, yy, mm, dd);
			//pt &= dog;
			pt = new Dog(name, len, wei, yy, mm, dd);
			pt->display(last);
		}
	}

	return 0;
}