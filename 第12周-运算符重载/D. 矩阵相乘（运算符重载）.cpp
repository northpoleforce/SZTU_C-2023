#include <bits/stdc++.h>

using namespace std;

class MyMatrix
{
private:
    int **matrix;
    int n;
public:
    MyMatrix() {
        matrix = NULL;
    }
    MyMatrix(int nn, int **p) {
        n = nn;
        matrix = new int*[n];
        for (int i = 0; i < n; ++i) matrix[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) matrix[i][j] = p[i][j];
    }
    ~MyMatrix() {
        if (matrix != NULL) delete[] matrix;
    }
    MyMatrix operator*(const MyMatrix& obj) {
        int **p;
        p = new int*[n];
        for (int i = 0; i < n; ++i) p[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                p[i][j] = 0;
                for (int k = 0; k < n; ++k) p[i][j] += matrix[i][k]*obj.matrix[k][j];
            }
        MyMatrix tmp(n, p);
        return tmp;
    }
    void operator=(const MyMatrix& obj) {
        n = obj.n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) matrix[i][j] = obj.matrix[i][j];
    }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << matrix[i][0];
            for (int j = 1; j < n; ++j) cout << " " << matrix[i][j];
            if (i < n-1) cout << "\n";
        }
    }
};

int main() {
    int t; cin >> t;
    int n; cin >> n;
    int** p = new int*[n];
    for (int i = 0; i < n; ++i) p[i] = new int[n];
    for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> p[i][j];
    MyMatrix f(n, p);
    // f.print();
    while (--t) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> p[i][j];
        MyMatrix t(n, p);
        // (f*t).print();
        f = f*t;
    }
    f.print();

    return 0;
}