#include <bits/stdc++.h>

#define ll long long

using namespace std;

class account {
private:
	int sum;
	double rate;
	int id;
	char type;
public:
	account(int _id, char ty, int s) {
		id  = _id;
		rate = 0.005;
		type = ty;
		sum = s;
	}
	account(account & a) {
		id = 50000000+a.id;
		rate = 0.015;
		type = a.type;
		sum = a.sum;
	}
	void add() {
		// Account=12345678--sum=10050
		sum += (double)sum*rate;
		cout << "Account=" << id << "--sum=" << sum << "\n";
	}
	void show() {
		// Account=62345678--Person--sum=10000--rate=0.015
		cout << "Account=" << id;
		if (type == 'P') printf("--Person");
		else printf("--Enterprise");
		printf("--sum=%d--rate=%.3lf\n", sum, rate);
	}
};

int main() {
	int t; scanf("%d", &t);
	string type;
	int sum, id;
	while (t--) {
		cin >> id >> type >> sum;
		// scanf("%s%s%d", id, type, sum);
		account ac0(id, type[0], sum);
		account ac1(ac0);
		cin >> type;
		if (type[0] == 'C') {
			ac0.add();
		} else {
			ac0.show();
		}
		cin >> type;
		if (type[0] == 'C') {
			ac1.add();
		} else {
			ac1.show();
		}
	}

	return 0;
}