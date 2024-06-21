#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+5;

class CXGraph {
private:
    int n;
public:
    CXGraph (int nn = 0) { n = nn; }
    friend CXGraph operator ++ (CXGraph &a) {
        a.n = min(21, a.n+2);
        return a;
    }
    friend CXGraph operator ++ (CXGraph &a, int) {
        CXGraph tmp(a.n);
        a.n = min(21, a.n+2);
        return tmp;
    }
    friend CXGraph operator -- (CXGraph &a) {
        a.n = max(1, a.n-2);
        return a;
    }
    friend CXGraph operator -- (CXGraph &a, int) {
        CXGraph tmp(a.n);
        a.n = max(1, a.n-2);
        return tmp;
    }
    void show () {
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < i; ++j) cout << " ";
            for (int j = 0; j < n-2*i; ++j) cout << "X";
            cout << "\n";
        }
        for (int i = 0; i < n/2; ++i) cout << " ";
        cout << "X\n";
        for (int i = n/2-1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) cout << " ";
            for (int j = 0; j < n-2*i; ++j) cout << "X";
            cout << "\n";
        }
    }
};

ostream& operator << (ostream& out, CXGraph x) {
    x.show();
    return out;
}

int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}