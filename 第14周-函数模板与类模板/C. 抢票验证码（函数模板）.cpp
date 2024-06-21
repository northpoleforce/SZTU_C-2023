#include <iostream>

using namespace std;

template <class T>

bool check(T a[], int n) {
	for (int i = 1; i < n; ++i)
		if (a[i] < a[i - 1]) return 0;
	return 1;
}

int main()
{
	char type;
	int n = 6;
	while (cin >> type) {
		if (type == 'i') {
			int* a; a = new int[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			if (check(a, n)) cout << "Valid\n";
			else cout << "Invalid\n";
		}
		if (type == 'f') {
			double* a; a = new double[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			if (check(a, n)) cout << "Valid\n";
			else cout << "Invalid\n";
		}
		if (type == 'c') {
			char* a; a = new char[n];
			for (int i = 0; i < n; ++i) cin >> a[i];
			if (check(a, n)) cout << "Valid\n";
			else cout << "Invalid\n";
		}
	}

	return 0;
}