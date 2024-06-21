#include <bits/stdc++.h>

#define ll long long

using namespace std;

class CVector {
private:
	int n, *a;
	static int sum;
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
		printf("\n");
	}
	static void add(const CVector &c) {
		for (int i = 0; i < c.n; ++i)
			sum += c.a[i];
	}
	static void set_sum(int s) {
		sum = s;
	}
	static void print_sum() {
		printf("%d\n", sum);
	}
};

int CVector::sum = 0;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d", &m);
		CVector::set_sum(0);
		while (m--) {
			scanf("%d", &n);
			int *a; a = new int[n];
			for (int i = 0; i < n; ++i)
				scanf("%d", &a[i]);
			CVector c(n, a);
			c.show();
			CVector::add(c);
		}
		CVector::print_sum();
	}
	
	return 0;
}