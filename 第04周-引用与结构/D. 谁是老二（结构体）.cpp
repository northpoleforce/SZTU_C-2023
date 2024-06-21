#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

struct dat {
	int y, m, d;
} d[1000];

bool cmp(const dat& a, const dat &b) {
	if (a.y == b.y) {
		if (a.m == b.m)
			return a.d < b.d;
		return a.m < b.m;
	}
	return a.y < b.y;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i)
		cin >> d[i].y >> d[i].m >> d[i].d;
	sort(d, d+t, cmp);
	cout << d[1].y << "-" << d[1].m << "-" << d[1].d;


	return 0;
}