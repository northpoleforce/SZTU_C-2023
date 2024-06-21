#include <bits/stdc++.h>

using namespace std;

class Point {
private:
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnOtherPoint(Point p);
};

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(double x_value, double y_value) {
	x = x_value;
	y = y_value;
}
void Point::setX(double x_value) {
	x = x_value;
}
void Point::setY(double y_value) {
	y = y_value;
}
double Point::getX() {
	return x;
}
double Point::getY() {
	return y;
}
double Point::distanceToAnOtherPoint(Point p) {
	double delx = p.getX()-x;
	double dely = p.getY()-y;
	return sqrt(delx*delx+dely*dely);
}

int main() {
	int t; scanf("%d", &t);
	double x1, y1, x2, y2;
	while (t--) {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		Point p1 = Point(x1, y1);
		Point p2 = Point(x2, y2);
		printf("Distance of Point(%.2lf,%.2lf) to Point(%.2lf,%.2lf) is %.2lf\n", x1, y1, x2, y2, p1.distanceToAnOtherPoint(p2));
	}

	return 0;
}