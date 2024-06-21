#include <iostream>

using namespace std;

template <class T>

void find(T a[], int n) {
	int maxc = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			if (a[j] == a[i]) cnt++;
		if (cnt > maxc) {
			maxc = cnt;
			ans = i;
		}
	}
	cout << a[ans] << " " << maxc << "\n";
}

int main()
{
	int t; cin >> t;
	while (t--) {
		char type; int n;
		cin >> type >> n;
		if (type == 'I') {
			int* a; a = new int[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			find(a, n);
		}
		if (type == 'D') {
			double* a; a = new double[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			find(a, n);
		}
		if (type == 'C') {
			char* a; a = new char[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			find(a, n);
		}
		if (type == 'S') {
			string* a; a = new string[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			find(a, n);
		}
	}

	return 0;
}