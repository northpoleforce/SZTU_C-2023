#include <bits/stdc++.h>

using namespace std;

class Shape {
public:
	virtual double area() {}
};
class Circle: public Shape {
private:
	double r;
public:
	Circle(double r0): r(r0) {}
	virtual double area() {
		return 3.14*r*r;
	}
};
class Square: public Shape {
private:
	double a;
public:
	Square(double a0): a(a0) {}
	virtual double area() {
		return a*a;
	}
};
class Rectangle: public Shape {
private:
	double b, c;
public:
	Rectangle(double b0, double c0): b(b0), c(c0) {}
	virtual double area() {
		return b*c;
	}
};

void print(Shape *p) {
	printf("%.2lf\n", p->area());
}

int main() {
	int t; cin >> t;
	double r, a, b, c;
	Shape *p;
	while (t--) {
		cin >> r;
		Circle cir(r);
		p = &cir;
		print(p);
		cin >> a;
		Square s(a);
		p = &s;
		print(p);
		cin >> b >> c;
		Rectangle rec(b, c);
		p = &rec;
		print(p);
	}

	return 0;
}