#include <bits/stdc++.h>

using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate() {}
	CDate(int y, int m, int d): year(y), month(m), day(d) {}
	bool check() {
		int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeap(year)) days[2] = 29;
		if (year < 1 || year >= 10000) return 0;
		if (month < 1 || month > 12) return 0;
		if (day < 1 || day > days[month]) return 0;
		return 1;
	} //检验日期是否合法
	bool isLeap(int x) {
		if (x%400 == 0 || (x%100!=0 && x%4 == 0)) return 1;
		return 0;
	}
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	void print() {
		if (check())
			cout << year << "年" << month << "月" << day << "日";
	}
};

class COldId
{
protected:
	char* pId15, * pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldId(char* pIdVal, char* pNameVal, CDate& day) {
		pId15 = new char[strlen(pIdVal)];
		pName = new char[strlen(pNameVal)];
		strcpy(pId15, pIdVal);
		strcpy(pName, pNameVal);
		birthday = day;
	}
	bool check(){ return 1; } //验证15位身份证是否合法
	void print() {}
	~COldId() {
		delete[] pId15;
		delete[] pName;
	}
};
class CNewId: public COldId {
protected:
	string pId18;
	CDate issueDay;
	int validYear;
public:
	// friend class CDate;
	CNewId(char na[], CDate bd, char id15[], string id18, int ry, int rm, int rd, int vy):
		COldId(id15, na, bd), pId18(id18), issueDay(ry, rm, rd), validYear(vy) {}
	int get_num(string s, int st, int ed) {
		int res = 0;
		for (int i = st; i <= ed; ++i)
			res = res*10+s[i]-'0';
		return res;
	}
	bool is_valid( CDate &a, int y) {
		if (a.get_year()+y < 2021) return 0;
		else if (a.get_year()+y > 2021) return 1;
		if (a.get_month() > 11) return 1;
		else if (a.get_month() < 11) return 0;
		if (a.get_day() >= 9) return 1;
		else if (a.get_day() < 9) return 0;
		return 0;
	}
	bool is_same( CDate &a,  CDate &b) {
		if (a.get_year() != b.get_year()) return 0;
		if (a.get_month() != b.get_month()) return 0;
		if (a.get_day() != b.get_day()) return 0;
		return 1;
	}
	bool check() {
		// printf("1\n");
		if (pId18.size() != 18) return 0;
		if (!issueDay.check()) return 0;
		if (!birthday.check()) return 0;

		// printf("2\n");
		for (int i = 0; i < 17; ++i)
			if (pId18[i] < '0' || pId18[i] > '9') return 0;
		if (!(pId18[17] == 'X' || (pId18[17] >= '0' && pId18[17] <= '9'))) return 0;
		
		// printf("3\n");
		for (int i = 0; i < 6; ++i)
			if (pId18[i] != pId15[i]) return 0;
		if (pId18[6] != '1') return 0;
		if (pId18[7] != '9') return 0;
		for (int i = 0; i < 9; ++i)
			if (pId18[8+i] != pId15[6+i]) return 0;
		int tot = 0;
		int a[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
		for (int i = 0; i < 17; ++i) {
			tot += (pId18[i]-'0')*a[i];
		}
		char b[] = {'1','0','X','9','8','7','6','5','4','3','2'};
		// printf("%d %c\n", tot, b[tot%11]);
		if (b[tot%11] != pId18[17]) return 0;
		// printf("4\n");
		CDate c(get_num(pId18, 6, 9), get_num(pId18, 10, 11), get_num(pId18, 12, 13));
		// c.print();printf("\n");birthday.print();printf("===\n");
		if (!is_same(c, birthday)) return 0;
		// printf("5\n");
		if (!is_valid(issueDay, validYear)) return 0;
		// printf("6\n");

		return 1;
	}
	void print() {
		cout << pName << "\n";
		if (check()) {
			cout << pId18 << " ";
			issueDay.print();
			if (validYear == 100)
				cout << " 长期\n";
			else
				cout << " " << validYear << "年\n";
		} else
			cout << "illegal id\n";
	}
};


int main() {
	int t; cin >> t;
	char name[100], id15[100];
	string id18;
	int year, month, day, ryear, rmonth, rday, period;
	while (t--) {
		cin >> name >> year >> month >> day;
		cin >> id15 >> id18;
		cin >> ryear >> rmonth >> rday >> period;
		CDate bd(year, month, day);
		CNewId pid(name, bd,
			id15, id18, ryear, rmonth, rday, period);
		pid.print();
	}

	return 0;
}