#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, maxa, mina;
		cin >> n >> m;
		int** a = new int*[n];
		for (int i = 0; i < n; ++i) {
			a[i] = new int[m];
			int* p = a[i];
			for (int j = 0; j < m; ++j) {
				cin >> *(p+j);
				if (i == 0 && j == 0) {
					maxa = *(p+j);
					mina = *(p+j);
				} else {
					maxa = max(maxa, *(p+j));
					mina = min(mina, *(p+j));
				}
			}
		}
		cout << mina << " " << maxa << "\n";
	}

	return 0;
}