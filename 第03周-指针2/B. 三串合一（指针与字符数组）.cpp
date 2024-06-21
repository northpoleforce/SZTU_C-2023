#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

int main() {
	// int t; cin >> t;
	int t;
	scanf("%d", &t);
	char x[20], y[20], z[20];
	int a[4], b[4], n;
	while (t--) {
		for (int i = 1; i <= 3; ++i) {
			if (i == 1) scanf("%s", x);
			if (i == 2) scanf("%s", y);
			if (i == 3) scanf("%s", z);
			// if (i == 1) cin >> x;
			// if (i == 2) cin >> y;
			// if (i == 3) cin >> z;
		}
		n = 0;
		for (int i = 1; i <= 3; ++i) {
			// cin >> a[i] >> b[i];
			scanf("%d%d", &a[i], &b[i]);
			n += b[i]-a[i]+1;
		}
		char* ans = new char[n+1];
		// char* p = ans;
		int m = 0;
		for (int i = 1; i <= 3; ++i) {
			for (int j = a[i]-1; j < b[i]; ++j) {
				// *p = *(s);
				if (i == 1) *(ans+m) = *(x+j);
				if (i == 2) *(ans+m) = *(y+j);
				if (i == 3) *(ans+m) = *(z+j);
				m++;
			}
		}
		*(ans+n) = '\0';
		printf("%s\n", ans);
		// cout << strlen(ans) << " " << n << " " << m << "\n";
		// cout << ans << "\n";
		delete[] ans;
	}

	return 0;
}