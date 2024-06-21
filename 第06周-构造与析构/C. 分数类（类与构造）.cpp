#include <bits/stdc++.h>

using namespace std;

class CFraction {
private:
	int fz, fm;
public:
	CFraction();
	CFraction(int fz_val, int fm_val);
	void add(const CFraction &r);
	void sub(const CFraction &r);
	void mul(const CFraction &r);
	void div(const CFraction &r);
	int getGCD();
	void print();
};

CFraction::CFraction() {
	fz = 0;
	fm = 0;
}
CFraction::CFraction(int fz_val, int fm_val) {
	fz = fz_val;
	fm = fm_val;
}
void CFraction::add(const CFraction &r) {
	fz = fz*r.fm+r.fz*fm;
	fm = fm*r.fm;
	int gcd = getGCD();
	fz /= gcd;
	fm /= gcd;
}
void CFraction::sub(const CFraction &r) {
	fz = fz*r.fm-r.fz*fm;
	fm = fm*r.fm;
	int gcd = getGCD();
	fz /= gcd;
	fm /= gcd;
}
void CFraction::mul(const CFraction &r) {
	fz *= r.fz;
	fm *= r.fm;
	int gcd = getGCD();
	fz /= gcd;
	fm /= gcd;
}
void CFraction::div(const CFraction &r) {
	fz *= r.fm;
	fm *= r.fz;
	int gcd = getGCD();
	fz /= gcd;
	fm /= gcd;
}
int _gcd(int a, int b) {
	return a%b == 0 ? b:_gcd(b, a%b);
}
int CFraction::getGCD() {
	return _gcd(fz, fm);
}
void CFraction::print() {
	int gcd = getGCD();
	double fy = fz/(double)fm;
	
	// printf("%d/%d=1\n", fz, fm);
	if (fy < 0) printf("-");
	printf("%d/%d\n", abs(fz/gcd), abs(fm/gcd));
}

int main() {
	int t; scanf("%d", &t);
	int fz, fm;
	while (t--) {
		scanf("%d/%d", &fz, &fm);
		CFraction cf1 = CFraction(fz, fm);
		scanf("%d/%d", &fz, &fm);
		CFraction cf2 = CFraction(fz, fm);
		cf1.add(cf2);
		cf1.print();
		cf1.sub(cf2);

		cf1.sub(cf2);
		cf1.print();
		cf1.add(cf2);

		cf1.mul(cf2);
		cf1.print();
		cf1.div(cf2);

		cf1.div(cf2);
		cf1.print();
		cf1.mul(cf2);
		printf("\n");
		// cf3 = CFraction(cf1.fz, cf1.fm);
		// cf3.add(cf2);
		// cf3.print();
		// cf3 = CFraction(cf1.fz, cf1.fm);
		// cf3.sub(cf2);
		// cf3.print();
		// cf3 = CFraction(cf1.fz, cf1.fm);
		// cf3.mul(cf2);
		// cf3.print();
		// cf3 = CFraction(cf1.fz, cf1.fm);
		// cf3.div(cf2);
		// cf3.print();
	}

	return 0;
}