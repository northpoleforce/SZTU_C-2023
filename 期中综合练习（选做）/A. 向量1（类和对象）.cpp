#include <bits/stdc++.h>

#define ll long long

using namespace std;

class CVector {
private:
	int n;
	int* data;
public:
	CVector() {
		n = 5;
		data = new int[5];
		for (int i = 0; i < n; ++i)
			data[i] = i;
		// data[] = (0, 1, 2, 3, 4);
	}
	CVector(int nn, int a[]) {
		n = nn;
		data = new int[n];
		for (int i = 0; i < n; ++i)
			data[i] = a[i];
	}
	~CVector() {
		delete[] data;
	}
	void show() {
		printf("%d", data[0]);
		for (int i = 1; i < n; ++i) printf(" %d", data[i]);
		printf("\n");
	}
};

int main() {
	int n; scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	// printf("==\n");
	CVector b; b.show();
	// printf("!!\n");
	CVector c(n, a); c.show();
	// printf("??\n");
	delete[] a;


	return 0;
}