#include <bits/stdc++.h>

using namespace std;

class Vector
{
private:
    int vec[5];
public:
    Vector(int v[]) {
        for (int i = 0; i < 5; ++i) vec[i] = v[i];
    }
    Vector() {
        for (int i = 0; i < 5; ++i) vec[i] = 0;
    }
    Vector(const Vector& obj) {}
    Vector operator +(const Vector& obj) {
        Vector tmp;
        for (int i = 0; i < 5; ++i)
            tmp.vec[i] = vec[i]+obj.vec[i];
        return tmp;
    }
    Vector operator -(const Vector& obj) {
        Vector tmp;
        for (int i = 0; i < 5; ++i)
            tmp.vec[i] = vec[i]-obj.vec[i];
        return tmp;
    }
    void print() {
        for (int i = 0; i < 5; ++i) cout << vec[i] << " ";
    }
};

int main() {
    int a[5];
    for (int i = 0; i < 5; ++i) cin >> a[i];
    Vector v1(a);
    for (int i = 0; i < 5; ++i) cin >> a[i];
    Vector v2(a);
    (v1+v2).print(); cout << "\n";
    (v1-v2).print();

    return 0;
}