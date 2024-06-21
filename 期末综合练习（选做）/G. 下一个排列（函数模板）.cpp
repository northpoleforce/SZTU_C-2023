#include <iostream>

using namespace std;

template <class T>

void next(T a[], int n) {
	int k;
	for (k = n - 2; k >= 0; --k) {
		if (a[k] < a[k + 1]) break;
	}
	if (k == -1) {
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				if (a[i] > a[j]) swap(a[i], a[j]);
	}
	else {
		int w;
		for (int i = n-1; i > k; --i)
			if (a[i] > a[k]) {
				w = i; break;
			}
		swap(a[k], a[w]);
		for (int i = k+1; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (a[i] > a[j]) swap(a[i], a[j]);
	}
}

int main()
{
	int t; cin >> t;
	char type; int n;
	while (t--) {
		cin >> type;
		if (type == 'C') {
			cin >> n;
			char* a = new char[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			next(a, n);
			cout << a[0];
			for (int i = 1; i < n; ++i) cout << " " << a[i];
			cout << "\n";
		}
		if (type == 'I') {
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			next(a, n);
			cout << a[0];
			for (int i = 1; i < n; ++i) cout << " " << a[i];
			cout << "\n";
		}
		if (type == 'D') {
			cin >> n;
			double* a = new double[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			next(a, n);
			cout << a[0];
			for (int i = 1; i < n; ++i) cout << " " << a[i];
			cout << "\n";
		}
		if (type == 'S') {
			cin >> n;
			string* a = new string[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			next(a, n);
			cout << a[0];
			for (int i = 1; i < n; ++i) cout << " " << a[i];
			cout << "\n";
		}
	}

	return 0;
}