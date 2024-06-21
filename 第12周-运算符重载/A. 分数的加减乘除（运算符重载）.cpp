#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+5;

// 定义Fraction类
class Fraction
{
private:
    int fz, fm;
    int commonDivisor(); // 计算最大公约数
    void contracted(); // 分数化简
public:
    Fraction(int a= 0, int b= 1) {
        fz = a;
        fm = b;
    }
    Fraction(Fraction& t) {
        fz = t.fz;
        fm = t.fm;
    }
    Fraction operator+(Fraction t) {
        Fraction tmp;
        tmp.fz = fz*t.fm+t.fz*fm;
        tmp.fm = fm*t.fm;
        return tmp;
    }
    Fraction operator-(Fraction t) {
        Fraction tmp;
        tmp.fz = fz*t.fm-t.fz*fm;
        tmp.fm = fm*t.fm;
        return tmp;
    }
    Fraction operator*(Fraction t) {
        Fraction tmp;
        tmp.fz = fz*t.fz;
        tmp.fm = fm*t.fm;
        return tmp;
    }
    Fraction operator/(Fraction t) {
        Fraction tmp;
        tmp.fz = fz*t.fm;
        tmp.fm = fm*t.fz;
        return tmp;
    }
    void set(int a= 0, int b= 1) {}
    void disply() {
        cout << "fraction=";
        // if (fz*fm < 0) cout << "-";
        cout << fz << "/" << fm << "\n";
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Fraction f1(a, b);
    cin >> a >> b;
    Fraction f2(a, b);
    Fraction f3;
    f3 = f1+f2; f3.disply();
    f3 = f1-f2; f3.disply();
    f3 = f1*f2; f3.disply();
    f3 = f1/f2; f3.disply();

    return 0;
}