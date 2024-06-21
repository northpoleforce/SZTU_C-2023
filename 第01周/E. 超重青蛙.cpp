#include <iostream>

using namespace std;

int a[1000];

int main() {
	int t, n, ans;
	double s, av;
	cin >> t;
	while (t--) {
		cin >> n;
		s = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s += a[i];
		}
		av = s/n;
		ans = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] > av) ans++;
		cout << ans << endl;
	}

	return 0;
}