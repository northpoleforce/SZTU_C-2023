#include <iostream>

using namespace std;

template <class T>

void _sort(T c[], int n, int a, int b) {
	a = max(a, 0);
	b = min(b, n);
	for (int i = a; i < b; ++i)
		for (int j = i + 1; j < b; ++j)
			if (c[i] > c[j]) swap(c[i], c[j]);
}

int conv(string st, int a, int b) {
	int res = 0;
	for (int i = a; i <= b; ++i)
		res = res * 10 + st[i] - '0';
	return res;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		string type;
		cin >> type;
		if (type == "int") {
			int n, a = 0, b = 0;
			cin >> n;
			string range;
			cin >> range;
			a = conv(range, range.find('[')+1, range.find(',')-1);
			b = conv(range, range.find(',') + 1, range.find(')') - 1);
			//cout << n << " " << a << " " << b << "=nab\n";
			int* c = new int[n];
			string rest; cin >> rest;
			for (int i = 0; i < n; ++i) cin >> c[i];
			//for (int i = 0; i < n; ++i) cout << c[i] << " ";
			//cout << "\n";
			_sort(c, n, a, b);
			cout << "[" << c[0];
			for (int i = 1; i < n; ++i) cout << ", " << c[i];
			cout << "]\n";
		}
		if (type == "string") {
			int n, a, b;
			cin >> n;
			string range;
			cin >> range;
			a = conv(range, range.find('[') + 1, range.find(',') - 1);
			b = conv(range, range.find(',') + 1, range.find(')') - 1);
			string* c = new string[n];
			string rest; cin >> rest;
			for (int i = 0; i < n; ++i) cin >> c[i];
			_sort(c, n, a, b);
			cout << "[" << c[0];
			for (int i = 1; i < n; ++i) cout << ", " << c[i];
			cout << "]\n";
		}
		if (type == "float") {
			int n, a, b;
			cin >> n;
			string range;
			cin >> range;
			a = conv(range, range.find('[') + 1, range.find(',') - 1);
			b = conv(range, range.find(',') + 1, range.find(')') - 1);
			float* c = new float[n];
			string rest; cin >> rest;
			for (int i = 0; i < n; ++i) cin >> c[i];
			_sort(c, n, a, b);
			cout << "[" << c[0];
			for (int i = 1; i < n; ++i) cout << ", " << c[i];
			cout << "]\n";
		}
	}

	return 0;
}