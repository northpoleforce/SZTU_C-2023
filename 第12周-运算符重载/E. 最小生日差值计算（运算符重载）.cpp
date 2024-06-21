#include <bits/stdc++.h>

using namespace std;

bool judge(int ay, int am, int ad,  int by, int bm, int bd) {
    if (ay < by) return 1;
    if (ay > by) return 0;
    if (am < bm) return 1;
    if (am > bm) return 0;
    if (ad < bd) return 1;
    return 0;
}

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Student
{
private:
    string name;
    int y, m, d;
public:
    Student() {}
    Student(string na, int yy, int mm, int dd) {
        name = na;
        y = yy; m = mm; d = dd;
    }
    friend int operator-(const Student& a, const Student& b) {
        int miy, mim, mid, may, mam, mad;
        if (judge(a.y, a.m, a.d, b.y, b.m, b.d)) {
            miy = a.y; mim = a.m; mid = a.d;
            may = b.y; mam = b.m; mad = b.d;
        } else {
            miy = b.y; mim = b.m; mid = b.d;
            may = a.y; mam = a.m; mad = a.d;
        }
        int res = 0, sm, em, sd, ed;
        for (int y = miy; y <= may; ++y) {
            if (y%400 == 0 || (y%100!=0 && y%4 == 0)) days[2] = 29;
            if (y == miy) sm = mim;
            else sm = 1;
            if (y == may) em = mam;
            else em = 12;
            for (int m = sm; m <= em; ++m) {
                if (y == miy && m == mim) sd = mid;
                else sd = 1;
                if (y == may && m == mam) ed = mad;
                else ed = days[m];
                for (int d = sd; d <= ed; ++d) ++res;
            }
        }
        return res-1;
    }
    string get_name() { return name; }
    void set(string na, int yy, int mm, int dd) {
        name = na;
        y = yy; m = mm; d = dd;
    }
};

Student p[1000];

int main() {
    int n; cin >> n;
    // Student *p = new Student[n];
    string na; int y, m, d;
    for (int i = 0; i < n; ++i) {
        cin >> na >> y >> m >> d;
        p[i].set(na, y, m, d);
    }
    int f = -1, a1, a2;
    for (int i = 0; i < n; ++i)
        for (int j = i+1, t; j < n; ++j) {
            t = p[i]-p[j];
            if (f == -1 || t < f) {
                f = t;
                a1 = i; a2 = j;
            }
        }
    cout << p[a1].get_name() << "和" << p[a2].get_name() << "年龄相差最小，为";
    cout << f << "天。";

    return 0;
}