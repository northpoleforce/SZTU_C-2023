#include <bits/stdc++.h>

#define ll long long

using namespace std;

class CVector {
private:
	int n, *a;
public:
	CVector(int nn, int *aa) {
		n = nn;
		a = new int[n];
		for (int i = 0; i < n; ++i)
			a[i] = aa[i];
	}
	void show() {
		for (int i = 0; i < n; ++i) {
			printf("%d ", a[i]);
		}
	}
	float Average() {
		float sum = 0;
		for (int i = 0; i < n; ++i)
			sum += a[i];
		return sum/n;
	}
};

class CStudent {
private:
	string name;
	CVector *score;
public:
	CStudent(string name1, int n1, int *a1) {
		name = name1;
		score = new CVector(n1, a1);
	}
	void show() {
		cout << name << " ";
		score->show();
		printf("%.2f\n", score->Average());
	}
};

int main() {
	string name;
	int n;
	while (cin >> name >> n) {
		int *a;
		a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		CStudent cs(name, n, a);
		cs.show();
	}

	return 0;
}