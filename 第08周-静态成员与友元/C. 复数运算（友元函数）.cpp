#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex();
	Complex(double r, double i);
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
};

Complex::Complex(double r, double i) {
    real = r; imag = i;
    // printf("%lf %lf", real, imag);
}
Complex addCom(const Complex& c1, const Complex& c2) {
	// cout << "???" << c1.real << " " << c1.imag << " " << c2.real << " " << c2.imag << "\n";
    Complex c(c1.real+c2.real, c1.imag+c2.imag);
    return c;
}
void outCom(const Complex& c) {
    // printf("(%.0lf,%.0lf)\n", c.real, c.imag);
    cout << "(" << c.real << "," << c.imag << ")\n";
}

int main() {
    // freopen("test.in", "r", stdin);
    int r, i; cin >> r >> i;
    Complex a(r, i);
    int n; cin >> n;
    char ch;
    while (n--) {
        // cin >> ch;
        cin >> ch >> r >> i;
        // cout << "\n==" << ch << r << i << "==\n";
        if (ch == '-') {
            r = -r;
            i = -i;
        }
        Complex b(r, i);
        a = addCom(a, b);
        outCom(a);
    }
    return 0;
}