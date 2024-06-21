#include <bits/stdc++.h>

using namespace std;

// class Count {
// public:
// 	virtual void deposit(int) {}
// 	virtual void withdraw(int) {}
// 	virtual void display() {}
// };

class BaseAccount {
protected:
	string name, account;
	int balance;
public:
	BaseAccount(string na, string id, int ba): name(na), account(id), balance(ba) {}
	virtual void deposit(int m) {
		balance += m;
	}
	virtual void withdraw(int m) {
		if (m > balance) printf("insufficient\n");
		else balance -= m;
	}
	virtual void display() {
		cout << name << " ";
		cout << account << " ";
		printf("Balance:%d\n", balance);
	}
};

class BasePlus: public BaseAccount {
private:
	int Maxlimit, limitSum;
public:
	BasePlus(string na, string id, int ba):
		BaseAccount(na, id, ba), Maxlimit(5000), limitSum(0) {}
	virtual void deposit(int m) {
		// cout << "!!!\n";
		balance += m;
	}
	virtual void withdraw(int m) {
		if (m > Maxlimit+balance) printf("insufficient\n");
		else balance -= min(m, balance+Maxlimit);
		// if (balance+Maxlimit > 0) balance -= min(m, balance+Maxlimit);
	}
	virtual void display() {
		// cout << "???\n";s
		cout << name << " ";
		cout << account << " ";
		limitSum = Maxlimit;
		if (balance < 0) {
			limitSum += balance;
			balance = 0;
		}
		printf("Balance:%d ", balance);
		printf("limit:%d\n", limitSum);
	}
};

int main() {
	int t; cin >> t;
	string name, id;
	int balance;
	BaseAccount* p;
	while (t--) {
		cin >> name >> id >> balance;
		if (id[1] == 'A') {
			BaseAccount ba(name, id, balance);
			p = &ba;
			for (int i = 0, a; i < 2; ++i) {
				cin >> a; p->deposit(a);
				cin >> a; p->withdraw(a);
			}
			p->display();
		} else {
			BasePlus bp(name, id, balance);
			p = &bp;
			for (int i = 0, a; i < 2; ++i) {
				cin >> a; p->deposit(a);
				cin >> a; p->withdraw(a);
			}
			p->display();
		}
	}

	return 0;
}