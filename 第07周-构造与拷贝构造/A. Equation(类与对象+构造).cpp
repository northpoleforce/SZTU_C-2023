#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

class Equation {
private:
	double a, b, c;
public:
	Equation() {
		a = b = 1.0;
		c = 0;
	}
	Equation(double aa, double bb, double cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	void set(double aa, double bb, double cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	void getRoot() {
		double d = b*b-4*a*c;
		if (d > 0) {
			printf("x1=%.2lf x2=%.2lf\n", (-b+sqrt(d))/a/2, (-b-sqrt(d))/a/2);
		}
		if (d == 0) {
			printf("x1=x2=%.2lf\n", (-b+sqrt(d))/a/2);
		}
		if (d < 0) {
			printf("x1=%.2lf+%.2lfi x2=%.2lf-%.2lfi\n", -b/a/2, sqrt(-d)/a/2, -b/a/2, sqrt(-d)/a/2);
		}
	}
};


int main() {
	int t; scanf("%d", &t);
	double a, b, c;
	while (t--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		Equation x = Equation(a, b, c);
		x.getRoot();
	}

	return 0;
}