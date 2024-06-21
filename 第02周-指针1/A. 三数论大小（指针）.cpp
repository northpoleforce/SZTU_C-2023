#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 1e5+5;


int main() {
	int t; cin >> t;
	int a, b, c;
	while (t--) {
		cin >> a >> b >> c;
		int *x, *y, *z;
		x = &a;
		y = &b;
		z = &c;
		if (*x < *y) swap(x, y);
		if (*x < *z) swap(x, z);
		if (*y < *z) swap(y, z);
		cout << *x << " " << *y << " " << *z << "\n";
	}

	return 0;
}