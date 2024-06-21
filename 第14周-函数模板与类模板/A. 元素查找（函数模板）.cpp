#include <iostream>

using namespace std;

template <class T>

int find(T a[], int n, T key) {
	for (int i = 0; i < n; ++i)
		if (a[i] == key) return i + 1;
	return 0;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		char type; int n;
		cin >> type >> n;
		if (type == 'I') {
			int* a; a = new int[n];
			int key;
			for (int i = 0; i < n; ++i) cin >> a[i];
			cin >> key;
			cout << find(a, n, key) << "\n";
		}
		if (type == 'D') {
			double* a; a = new double[n];
			double key;
			for (int i = 0; i < n; ++i) cin >> a[i];
			cin >> key;
			cout << find(a, n, key) << "\n";
		}
		if (type == 'C') {
			char* a; a = new char[n];
			char key;
			for (int i = 0; i < n; ++i) cin >> a[i];
			cin >> key;
			cout << find(a, n, key) << "\n";
		}
		if (type == 'S') {
			string* a; a = new string[n];
			string key;
			for (int i = 0; i < n; ++i) cin >> a[i];
			cin >> key;
			cout << find(a, n, key) << "\n";
		}
	}

	return 0;
}