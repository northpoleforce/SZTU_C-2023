#include <iostream>

using namespace std;

template <typename T>

class Matrix {
private:
	int n, m;
	T** a;
public:
	Matrix(T** aa, int nn, int mm) : n(nn), m(mm) {
		a = new T * [n];
		for (int i = 0; i < n; ++i) a[i] = new T[m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) a[i][j] = aa[i][j];
	}
	void transport() {
		int tn = n, tm = m;
		n = tm; m = tn;
		T** b;
		b = new T * [n];
		for (int i = 0; i < n; ++i) b[i] = new T[m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				b[i][j] = a[j][i];
		delete[] a;
		a = new T * [n];
		for (int i = 0; i < n; ++i) a[i] = new T[m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) a[i][j] = b[i][j];
		}
	}
	void print() {
		for (int i = 0; i < n; ++i) {
			cout << a[i][0];
			for (int j = 1; j < m; ++j) cout << " " << a[i][j];
			cout << "\n";
		}
	}
};

int main()
{
	int t; cin >> t;
	while (t--) {
		char type; int n, m;
		cin >> type >> n >> m;
		if (type == 'I') {
			int** a; a = new int* [n];
			for (int i = 0; i < n; ++i) a[i] = new int[m];
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) cin >> a[i][j];
			Matrix<int>ma(a, n, m);
			ma.transport();
			ma.print();
		}
		if (type == 'D') {
			double** a; a = new double* [n];
			for (int i = 0; i < n; ++i) a[i] = new double[m];
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) cin >> a[i][j];
			Matrix<double>ma(a, n, m);
			ma.transport();
			ma.print();
		}
		if (type == 'C') {
			char** a; a = new char* [n];
			for (int i = 0; i < n; ++i) a[i] = new char[m];
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) cin >> a[i][j];
			Matrix<char>ma(a, n, m);
			ma.transport();
			ma.print();
		}
	}

	return 0;
}