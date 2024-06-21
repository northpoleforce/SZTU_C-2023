#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+5;

class Clock {
private:
    int h, m, s;
public:
    Clock(int hh = 0, int mm = 0, int ss = 0) {
        h = hh; m = mm; s = ss;
    }
    friend Clock operator ++ (Clock &a, int) {
        a.s++;
        if (a.s == 60) { a.m++; a.s = 0; }
        if (a.m == 60) { a.h++; a.m = 0; }
        if (a.h == 12) { a.h = 0; }
        return a;
    }
    friend Clock operator -- (Clock &a, int) {
        a.s--;
        if (a.s < 0) { a.m--; a.s = 59; }
        if (a.m < 0) { a.h--; a.m = 59; }
        if (a.h < 0) { a.h = 11; }
        return a;
    }
    void show() {
        cout << h << ":" << m << ":" << s << "\n";
    }
};

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    Clock c(h, m, s);
    int t, a; cin >> t;
    while (t--) {
        cin >> a;
        if (a >= 0)
            while (a--) {
                c++;
                // c.show();
            }
        else
            while (a++) {
                c--;
            }
        c.show();
    }

    return 0;
}