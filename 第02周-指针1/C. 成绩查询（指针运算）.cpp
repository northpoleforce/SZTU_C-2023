#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 1e5+5;

int a[1005];

int main() {
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		int q; cin >> q;
		int *p = &a[n/2];
		cout << *(p-1) << " " << *(p+1) << "\n";
		// for (int i = 0; i < (n/2-(q-1)); ++i) p--;
		cout << *(p-(n/2-(q-1))) << "\n";
	}

	return 0;
}