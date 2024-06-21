#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+5;

class Point {
private:
    int x, y, z;
public:
    Point(int X = 0, int Y = 0, int Z = 0) { x = X; y = Y; z = Z; }
    friend Point operator ++(Point &a) {
        // cout << "=\n";
        a.x++; a.y++; a.z++;
        return a;
    }
    friend Point operator ++(Point & a, int) {
        // cout << "==\n";
        Point tmp(a.x, a.y, a.z);
        a.x++; a.y++; a.z++;
        return tmp;
    }
    friend Point operator --(Point &a) {
        a.x--; a.y--; a.z--;
        return a;
    }
    friend Point operator --(Point & a, int) {
        Point tmp(a.x, a.y, a.z);
        a.x--; a.y--; a.z--;
        return tmp;
    }
    void show() {
        cout << "x="<<x<<" "<<"y="<<y<<" "<<"z="<<z<<"\n";
    }
};

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Point p1(x, y, z);
    Point p2, old;
    old = p1;

    p2 = p1++;
    p1.show(); p2.show();
    
    p1 = old; p2 = ++p1;
    p1.show(); p2.show();

    p1 = old; p2 = p1--;
    p1.show(); p2.show();

    p1 = old; p2 = --p1;
    p1.show(); p2.show();

    return 0;
}