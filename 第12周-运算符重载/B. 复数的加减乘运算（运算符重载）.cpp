#include <bits/stdc++.h>

using namespace std;

class Complex
{
private:
    float real, image;
public:
    Complex(float x = 0, float y = 0) {
        real = x;
        image = y;
    }
    friend Complex operator+(Complex& a, Complex& b) {
        Complex tmp;
        tmp.real = a.real+b.real;
        tmp.image = a.image+b.image;
        return tmp;
    }
    friend Complex operator-(Complex& a, Complex& b) {
        Complex tmp;
        tmp.real = a.real-b.real;
        tmp.image = a.image-b.image;
        return tmp;
    }
    friend Complex operator*(Complex& a, Complex& b) {
        Complex tmp;
        tmp.real = a.real*b.real-a.image*b.image;
        tmp.image = a.image*b.real+a.real*b.image;
        return tmp;
    }
    void show() {
        printf("Real=%.0f Image=%.0f\n", real, image);
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Complex c1(a, b);
    cin >> a >> b;
    Complex c2(a, b);
    (c1+c2).show();
    (c1-c2).show();
    (c1*c2).show();

    return 0;
}