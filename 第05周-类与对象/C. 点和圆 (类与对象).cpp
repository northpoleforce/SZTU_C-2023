#include <bits/stdc++.h>

using namespace std;

class Point {
private:
	double x, y;
public:
	void setPoint() {
		scanf("%lf%lf", &x, &y);
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
};
class Circle {
private:
	double x, y, r;
public:
	void setCenter() {
		scanf("%lf%lf", &x, &y);
	}
	void setRadius() {
		scanf("%lf", &r);
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	double getR() {
		return r;
	}
	double getArea() {
		return 3.14*r*r;
	}
	double getLength() {
		return 2*3.14*r;
	}
};

void contain(Point p, Circle c) {
	double dx = p.getX()-c.getX();
	double dy = p.getY()-c.getY();
	double r = c.getR();
	if (dx*dx+dy*dy <= r*r)
		printf("yes");
	else
		printf("no");
}

int main() {
	Point p;
	Circle c;
	c.setCenter();
	c.setRadius();
	p.setPoint();
	printf("%.2lf %.2lf\n", c.getArea(), c.getLength());
	contain(p, c);

	return 0;
}