#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;


void _sort(int &a, int &b, int &c) {
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
}

int main() {
	int t; cin >> t;
	int a, b, c;
	while (t--) {
		cin >> a >> b >> c;
		_sort(a, b, c);
		cout << a << " " << b << " " << c << "\n";
	}

	return 0;
}