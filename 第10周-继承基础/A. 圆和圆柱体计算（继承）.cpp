#include <bits/stdc++.h>

using namespace std;

class CPoint {
protected:
	int x, y;
public:
	CPoint(int x0, int y0): x(x0), y(y0) {}
};
class CCircle: public CPoint {
protected:
	int r;
public:
	CCircle(int x0, int y0, int r0): CPoint(x0, y0), r(r0) {}
	double cal_S() { return 3.14*r*r; }
	void print() {
		printf("Circle:(%d,%d),%d\n", x, y, r);
		printf("Area:%.2lf\n", cal_S());
	}
};
class CCylinder: public CCircle {
protected:
	int h;
public:
	CCylinder(int x0, int y0, int r0, int h0): CCircle(x0, y0, r0), h(h0) {}
	double cal_V() { return cal_S()*h; }
	void print() {
		printf("Cylinder:(%d,%d),%d,%d\n", x, y, r, h);
		printf("Volume:%.2lf\n", cal_V());
	}
};


int main() {
	int x, y, r, h;
	scanf("%d%d%d", &x, &y, &r);
	CCircle c0(x, y, r);
	c0.print();
	scanf("%d%d%d%d", &x, &y, &r, &h);
	CCylinder y0(x, y, r, h);
	y0.print();

	return 0;
}