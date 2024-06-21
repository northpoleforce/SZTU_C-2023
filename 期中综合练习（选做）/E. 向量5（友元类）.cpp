#include <bits/stdc++.h>

#define ll long long

using namespace std;

class CMatrix;
class CVector {
private:
	int n, *a;
public:
	CVector(int nn, int *aa) {
		n = nn;
		a = new int[n];
		for (int i = 0; i < n; ++i)
			a[i] = aa[i];
	}
	void show() {
		printf("%d", a[0]);
		for (int i = 1; i < n; ++i) {
			printf(" %d", a[i]);
		}
	}
	friend class CMatrix;
};

class CMatrix {
private:
	int n;
	int **data;
public:
	CMatrix(int nn, int **a) {
		n = nn;
		data = new int*[n];
		for (int i = 0; i < n; ++i) {
			data[i] = new int[n];
			for (int j = 0; j < n; ++j)
				data[i][j] = a[i][j];
		}
	}
	bool check(const CVector &v1) { return v1.n == n; }
	CVector multi(const CVector &v1) {
		int *s;
		s = new int[v1.n];
		for (int i = 0; i < v1.n; ++i) {
			s[i] = 0;
			for (int j = 0; j < v1.n; ++j)
				s[i] += v1.a[j]*data[i][j];
		}
		CVector c(v1.n, s);
		return c;
	}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int **data;
		data = new int*[n];
		for (int i = 0; i < n; ++i) {
			data[i] = new int[n];
			for (int j = 0; j < n; ++j)
				scanf("%d", &data[i][j]);
		}
		CMatrix cm(n, data);
		int m; scanf("%d", &m);
		int *a;
		a = new int[m];
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		CVector c(m, a);
		if (cm.check(c))
			cm.multi(c).show();
		else
			printf("error\n");
	}

	return 0;
}