#include <bits/stdc++.h>

#define ll long long

using namespace std;

class CVector {
private:
	int n;
	int* data;
public:
	CVector(int nn, int a[]) {
		n = nn;
		data = new int[n];
		for (int i = 0; i < n; ++i)
			data[i] = a[i];
	}
	~CVector() {
		// delete[] data;
	}
	void print() {
		printf("%d", data[0]);
		for (int i = 1; i < n; ++i) printf(" %d", data[i]);
		printf("\n");
	}
	friend CVector add(const CVector, const CVector);
};

CVector add(const CVector v1, const CVector v2) {
	int* a = new int[v1.n];
	for (int i = 0; i < v1.n; ++i)
		a[i] = v1.data[i]+v2.data[i];
	CVector sum(v1.n, a);
	delete[] a;
	return sum;
}

int main() {
	int t, n; scanf("%d", &t);
	//printf("%d\n", t);
	while (t--) {
		// printf("!!!\n");
		scanf("%d", &n);
		// printf("???\n");
		int* a = new int[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		CVector v1(n, a); v1.print();
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		CVector v2(n, a); v2.print();
		add(v1, v2).print();
		delete[] a;
		// printf("===\n");
	}


	return 0;
}