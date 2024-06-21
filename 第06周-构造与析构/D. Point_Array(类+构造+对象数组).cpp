#include <bits/stdc++.h>

using namespace std;

class Point {
private:
	double x, y;
public:
	Point();
	~Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setXY(double x1, double y1) {x=x1;y=y1;}
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point &p);
};

Point::Point() {
	x = 0;
	y = 0;
	printf("Constructor.\n");
}
Point::~Point() {
	printf("Distructor.\n");
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
double Point::getDisTo(Point &p) {
	double delx = p.x-x;
	double dely = p.y-y;
	return sqrt(delx*delx+dely*dely);
}

int main() {
	int t; scanf("%d", &t);
	double x, y, res;
	int n;
	while (t--) {
		scanf("%d", &n);
		Point po[n];
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x, &y);
			po[i].setXY(x, y);
			// printf("%lf %lf==\n", po[i].getX(), po[i].getY());
		}
		double maxdis = 0;
		int ansi = 0, ansj = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j) {
				res = po[i].getDisTo(po[j]);
				// printf("%d %d %lf\n", i, j, res);
				if (res > maxdis) {
					maxdis = res;
					ansi = i;
					ansj = j;
				}
				else if (res == maxdis) {
					if (i < ansi) {
						ansi = i;
						ansj = j;
					}
					else if (i == ansi) {
						if (j < ansj) {
							ansi = i;
							ansj = j;
						}
					}
				}
			}
		printf("The longeset distance is %.2lf,between p[%d] and p[%d].\n", maxdis, ansi, ansj);
	}

	return 0;
}