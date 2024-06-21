#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

int main() {
	int t; cin >> t;
	// int* a = new int* [2];
	int a[2][3], b[3][2];
	int *p = b[0];
	int *q = a[0];
	while (t--) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 3; ++j) cin >> a[i][j];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				// int* q = a+(j*3+3-i-1);
				// int* p = b+(i*2+j);
				*(p+i*2+j) = *(q+j*3+3-i-1);
				// (b+i*2+j) = (a+j*3+3-i-1);
				// *p = *q;
				// cout << *()
				// cout << *(p+j*3+3-i-1) << " ";
				cout << *(p+i*2+j) << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}