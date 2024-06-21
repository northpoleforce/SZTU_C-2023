#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double xx, double yy) {
        x = xx;
        y = yy;
    }
    friend double Distance(Point &a, Point &b);
};

double sqr(double x) {
    return x*x;
}
double Distance(Point &a, Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main() {
    int t;
    cin >> t;
    double x1, y1, x2, y2;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        Point a(x1, y1);
        Point b(x2, y2);
        cout << (int)Distance(a, b) << "\n";
    }

    return 0;
}