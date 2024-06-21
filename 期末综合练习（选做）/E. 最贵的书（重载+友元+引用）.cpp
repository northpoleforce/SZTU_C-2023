#include <bits/stdc++.h>

using namespace std;

class CBook {
private:
	string name, author, pub;
	double price;
public:
	CBook() {}
	CBook(string na, string au, double pr, string pu):
		name(na), author(au), price(pr), pub(pu) {}
	friend void find(CBook* book, int n, int& max1index, int& max2index) {
		for (int i = 0; i < n; ++i)
			if (book[i].price > book[max1index].price) max1index = i;
		if (max1index + 1 < n) max2index = max1index + 1;
		if (max2index - 1 >= 0) max2index = max1index - 1;
		for (int i = 0; i < n; ++i)
			if (i != max1index && book[i].price > book[max2index].price) max2index = i;
	}
	// void show() {
	// 	cout << name << "\n" << author << "\n";
	// 	printf("%.2lf\n", price);
	// 	cout << pub;
	// }
	friend istream& operator >> (istream &cin, CBook &b) {
		char ch;
		getline(cin, b.name, '\n');
		getline(cin, b.name, ',');
		getline(cin, b.author, ',');
		cin >> b.price;
		cin >> ch; cin >> b.pub;
		return cin;
	}
	friend ostream& operator << (ostream &cout, CBook &b) {
		cout << b.name << "\n" << b.author << "\n";
		printf("%.2lf\n", b.price);
		cout << b.pub;
		return cout;
	}
};

int main() {
	int t; cin >> t;
	string name, author, pub;
	double price = 0;
	int n; char ch;
	while (t--) {
		cin >> n;
		//scanf_s("%d", &n);
		CBook* b = new CBook[n];
		for (int i = 0; i < n; ++i) {
			cin >> b[i];

			// getline(cin, name, '\n');
			// getline(cin, name, ',');
			// getline(cin, author, ',');
			// cin >> price;
			// cin >> ch; cin >> pub;
			// b[i] = CBook(name, author, price, pub);
		}
		int idx1 = 0, idx2 = 0;
		find(b, n, idx1, idx2);
		cout << b[idx1]; cout << "\n\n"; cout << b[idx2];
		// b[idx1].show(); cout << "\n\n"; b[idx2].show();
		delete[] b;
		if (t) cout << "\n\n";
	}

	return 0;
}