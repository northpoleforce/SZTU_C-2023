#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 1e5+5;

double d = 6.2619;
double e = 6.6744;
double y = 0.0516;
double h = 0.8065;

int main() {
	int t; cin >> t;
	char ch;
	double n;
	const double *p;
	while (t--) {
		cin >> ch >> n;
		if (ch == 'D')
			p = &d;
		if (ch == 'E')
			p = &e;
		if (ch == 'Y')
			p = &y;
		if (ch == 'H')
			p = &h;
		cout << fixed << setprecision(4) << n*(*p) << "\n";
	}

	return 0;
}