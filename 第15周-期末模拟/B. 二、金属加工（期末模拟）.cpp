#include <bits/stdc++.h>

using namespace std;

class Metal {
private:
    int rig, wei, vol;
public:
    Metal(int r, int w, int v):
        rig(r), wei(w), vol(v) {}
    friend Metal operator+(Metal &a, Metal &b) {
        Metal res(a.rig+b.rig, a.wei+b.wei, a.vol+b.vol);
        return res;
    }
    friend Metal operator*(Metal &a, int n) {
        Metal res(a.rig, a.wei, a.vol*n);
        return res;
    }
    Metal operator ++() {
        rig++;
        wei = wei*1.1;
        vol = vol*1.1;
        return *this;
    }
    Metal operator --(int t) {
        rig--;
        wei = wei*0.9;
        vol = vol*0.9;
        return *this;
    }
    void print() {
        printf("硬度%d--重量%d--体积%d\n", rig, wei, vol);
    }
};

int main() {
    int rig, wei, vol;
    cin >> rig >> wei >> vol;
    Metal m1(rig, wei, vol);
    cin >> rig >> wei >> vol;
    Metal m2(rig, wei, vol);
    int n; cin >> n;
    (m1+m2).print();
    (m1*n).print();
    (++m1).print();
    (m2--).print();

    return 0;
}