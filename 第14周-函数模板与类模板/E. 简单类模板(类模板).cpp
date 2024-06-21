#include <iostream>

using namespace std;

template <typename T>

class List {
private:
	int n;
	T a[100];
public:
	List(T* aa, int nn) :n(nn) {
		for (int i = 0; i < n; ++i) a[i] = aa[i];
	}
	void add(int p, T x) {
		n++;
		for (int i = n-1; i > p; --i) a[i] = a[i - 1];
		a[p] = x;
	}
	void del(int p) {
		n--;
		for (int i = p; i < n; ++i) a[i] = a[i + 1];
	}
	void print() {
		cout << a[0];
		for (int i = 1; i < n; ++i) cout << " " << a[i];
		cout << "\n";
	}
};

int a[100];
double b[100];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	List <int> l1(a, n);
	int p, x;
	cin >> p >> x;
	l1.add(p, x);
	cin >> p;
	l1.del(p);
	l1.print();

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> b[i];
	List <double> l2(b, n);
	double xx;
	cin >> p >> xx;
	l2.add(p, xx);
	cin >> p;
	l2.del(p);
	l2.print();

	return 0;
}