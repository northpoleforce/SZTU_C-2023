#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 1e5+5;

int main() {
	int t; cin >> t;
	while (t--) {
		char ch; cin >> ch;
		int n; cin >> n;
		if (ch == 'C') {
			char* arr = new char[n];
			for (int i = 0; i < n; ++i)
				cin >> *(arr+i);
			char* ans = arr;
			for (int i = 0; i < n; ++i)
				if (*(arr+i) > *ans) ans = arr+i;
			// cout << "\n";
			cout << *ans << "\n";
			delete[] arr;
		}
		if (ch == 'F') {
			double* arr = new double[n];
			for (int i = 0; i < n; ++i)
				cin >> *(arr+i);
			double* ans = arr;
			for (int i = 0; i < n; ++i)
				if (*(arr+i) < *ans) ans = arr+i;
			// cout << *ans << "???\n";
			printf("%.1lf\n", *ans);
			delete[] arr;
		}
		if (ch == 'I') {
			int* arr = new int[n];
			for (int i = 0; i < n; ++i)
				cin >> *(arr+i);
			double sum = 0;
			for (int i = 0; i < n; ++i)
				sum += *(arr+i);
			// cout << fixed << setprecision(0) << sum/n << "\n";
			printf("%.0lf\n", sum/n);
			delete[] arr;
		}
	}

	return 0;
}