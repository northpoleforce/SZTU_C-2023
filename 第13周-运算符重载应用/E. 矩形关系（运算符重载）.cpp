#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+5;

class CPoint {
private:
    int x, y;
public:
    CPoint (int xx = 0, int yy = 0) { x = xx; y = yy; }
    int getX() { return x; }
    int getY() { return y; }
};

class CRectangle {
private:
    CPoint leftPoint, rightPoint;
public:
    CRectangle (int x1, int y1, int x2, int y2) {
        CPoint tmp1(x1, y1);
        leftPoint = tmp1;
        CPoint tmp2(x2, y2);
        rightPoint = tmp2;
    }
    friend bool operator > (CPoint &p, CRectangle &a) {
        if (a.leftPoint.getX() > p.getX() || a.rightPoint.getX() < p.getX()) return 0;
        if (a.leftPoint.getY() < p.getY() || a.rightPoint.getY() > p.getY()) return 0;
        return 1;
    }
    friend bool operator > (CRectangle &a, CRectangle &b) {
        if (!(b.leftPoint > a)) return 0;
        if (!(b.rightPoint > a)) return 0;
        return 1;
    }
    friend bool operator == (CRectangle &a, CRectangle &b) {
        // int axlen = a.rightPoint.getX()-a.leftPoint.getX();
        // int aylen = a.rightPoint.getY()-a.leftPoint.getY();
        // int bxlen = b.rightPoint.getX()-b.leftPoint.getX();
        // int bylen = b.rightPoint.getY()-b.leftPoint.getY();
        // return ((axlen == bxlen) && (aylen == bylen));
        return ((a.leftPoint.getX() == b.leftPoint.getX() && a.leftPoint.getY() == b.leftPoint.getY())
        && (a.rightPoint.getX() == b.rightPoint.getX() && a.rightPoint.getY() == b.rightPoint.getY()));
    }
    friend bool operator * (CRectangle &a, CRectangle &b) {
        int axlen = a.rightPoint.getX()-a.leftPoint.getX();
        int aylen = a.leftPoint.getY()-a.rightPoint.getY();
        int bxlen = b.rightPoint.getX()-b.leftPoint.getX();
        int bylen = b.leftPoint.getY()-b.rightPoint.getY();
        int acx = (a.leftPoint.getX()+a.rightPoint.getX())/2;
        int acy = (a.leftPoint.getY()+a.rightPoint.getY())/2;
        int bcx = (b.leftPoint.getX()+b.rightPoint.getX())/2;
        int bcy = (b.leftPoint.getY()+b.rightPoint.getY())/2;
        if (abs(acx-bcx)*2 > (axlen+bxlen)) return 0;
        if (abs(acy-bcy)*2 > (aylen+bylen)) return 0;
        return 1;
    }
    operator int() {
        return (rightPoint.getX()-leftPoint.getX())*(leftPoint.getY()-rightPoint.getY());
    }
    void show() {
        cout << leftPoint.getX() << " " << leftPoint.getY() << " ";
        cout << rightPoint.getX() << " " << rightPoint.getY();
    }
};

ostream& operator << (ostream &os, CRectangle &p) {
    p.show();
    return os;
}

int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}