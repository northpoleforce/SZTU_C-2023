#include <iostream>

using namespace std;

class CSet {
private:
	int n;
	int* data;
public:
	CSet() {
		n = 0;
		data = NULL;
	}
	CSet(int nn, int* a) {
		n = nn;
		data = new int[n];
		for (int i = 0; i < n; ++i) data[i] = a[i];
	}
	~CSet() {
		delete data;
	}
	void show() {
		cout << data[0];
		for (int i = 1; i < n; ++i) cout << " " << data[i];
		cout << "\n";
	}
	friend CSet operator+(const CSet &a, const CSet &b) {
		int* t = new int[a.n+b.n];
		for (int i = 0; i < a.n; ++i) t[i] = a.data[i];
		int nn = a.n;
		for (int i = 0; i < b.n; ++i) {
			bool ok = 1;
			for (int j = 0; j < a.n; ++j)
				if (a.data[j] == b.data[i]) {
					ok = 0; break;
				}
			if (ok) t[nn++] = b.data[i];
		}
		CSet res(nn, t);
		delete t;
		return res;
	}
	friend CSet operator*(const CSet& a, const CSet& b) {
		int* t = new int[a.n];
		int nn = 0;
		for (int i = 0; i < a.n; ++i)
			for (int j = 0; j < b.n; ++j)
				if (a.data[i] == b.data[j]) {
					t[nn++] = a.data[i];
					break;
				}
		CSet res(nn, t);
		delete t;
		return res;
	}
	friend CSet operator-(const CSet& a, const CSet& b) {
		int* t = new int[a.n + b.n];
		int nn = 0;
		for (int i = 0; i < a.n; ++i) {
			bool ok = 1;
			for (int j = 0; j < b.n; ++j)
				if (a.data[i] == b.data[j]) {
					ok = 0; break;
				}
			if (ok) t[nn++] = a.data[i];
		}
		for (int i = 0; i < b.n; ++i) {
			bool ok = 1;
			for (int j = 0; j < a.n; ++j)
				if (b.data[i] == a.data[j]) {
					ok = 0; break;
				}
			if (ok) t[nn++] = b.data[i];
		}
		CSet res(nn, t);
		delete t;
		return res;
	}
};

int main() {
	int t; cin >> t;
	int n;
	while (t--) {
		cin >> n;
		int* data = new int[n];
		for (int i = 0; i < n; ++i) cin >> data[i];
		CSet A(n, data); 
		cout << "A:"; A.show();
		delete data;
		cin >> n;
		data = new int[n];
		for (int i = 0; i < n; ++i) cin >> data[i];
		CSet B(n, data); 
		cout << "B:";  B.show();
		delete data;
		cout << "A+B:"; (A + B).show();
		cout << "A*B:"; (A * B).show();
		cout << "(A-B)+(B-A):"; (A - B).show();
		if (t) cout << "\n";
	}

	return 0;
}