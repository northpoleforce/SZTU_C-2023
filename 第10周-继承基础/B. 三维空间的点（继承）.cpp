#include <bits/stdc++.h>

using namespace std;

class C2D {
protected:
	int x, y;
public:
	C2D(int x0, int y0): x(x0), y(y0) {}
	double getDistance() { return sqrt(x*x+y*y); }
	void print() {
		// printf("%d %d\n", x, y);
		cout << getDistance() << "\n";
		// if (getDistance()*getDistance() == x*x+y*y)
		// 	printf("%.0lf\n", getDistance());
		// else
		// 	printf("%.4lf\n", getDistance());
	}
};
class C3D: public C2D {
protected:
	int z;
public:
	C3D(int x0, int y0, int z0): C2D(x0, y0), z(z0) {}
	double getDistance() { return sqrt(x*x+y*y+z*z); }
	void print() {
		// printf("%d %d %d\n", x, y, z);
		cout << getDistance() << "\n";
		// if (getDistance()*getDistance() == x*x+y*y+z*z)
		// 	printf("%.0lf\n", getDistance());
		// else
		// 	printf("%.4lf\n", getDistance());
	}
};

int main() {
	int x, y, z;
	scanf("%d%d", &x, &y);
	C2D p1(x, y);
	p1.print();
	scanf("%d%d%d", &x, &y, &z);
	C3D p2(x, y, z);
	p2.print();
	scanf("%d%d%d", &x, &y, &z);
	C3D p3(x, y, z);
	p3.print();
	p1 = p3;
	p1.print();

	return 0;
}