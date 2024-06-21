#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+5;

class CMoney {
private:
    int yuan, jiao, fen;
public:
    CMoney(int y = 0, int j = 0, int f = 0) {
        yuan = y; jiao = j; fen = f;
    }
    friend CMoney operator + (CMoney &a, CMoney &b) {
        CMoney tmp(a.yuan, a.jiao, a.fen);
        tmp.yuan += b.yuan;
        tmp.jiao += b.jiao;
        tmp.fen += b.fen;
        tmp.jiao += tmp.fen/10; tmp.fen %= 10;
        tmp.yuan += tmp.jiao/10; tmp.jiao %= 10;
        return tmp;
    }
    friend CMoney operator - (CMoney &a, CMoney &b) {
        CMoney tmp(a.yuan, a.jiao, a.fen);
        tmp.yuan -= b.yuan;
        tmp.jiao -= b.jiao;
        tmp.fen -= b.fen;
        if (tmp.fen < 0) {tmp.jiao--; tmp.fen += 10; }
        if (tmp.jiao < 0) {tmp.yuan--; tmp.jiao += 10; }
        return tmp;
    }
    void show() {
        cout << yuan << "元" << jiao << "角" << fen << "分" << "\n";
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int y, j, f;
        cin >> y >> j >> f;
        CMoney c(y, j, f);
        string cmd;
        while (cin >> cmd) {
            if (cmd == "stop") {
                c.show();
                break;
            }
            cin >> y >> j >> f;
            CMoney t(y, j, f);
            if (cmd == "add") {
                c = c+t;
            } else {
                c = c-t;
            }
        }
    }

    return 0;
}