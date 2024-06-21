#include <bits/stdc++.h>

using namespace std;

class acc {
private:
	int account;
	char name[10];
	double balance = 0;
public:
	void check() {
		printf("%s's balance is %.lf\n", name, balance);
	}
	void init() {
		scanf("%d%s%lf", &account, name, &balance);
		check();
	}
	void deposit(float x) {
		balance += x;
		printf("saving ok!\n");
		check();
	}
	void withdraw(float x) {
		if (0 <= x && x <= balance) {
			balance -= x;
			printf("withdraw ok!\n");
		} else {
			printf("sorry! over limit!\n");
		}
		check();
	}
};

int main() {
	acc acc[2];
	double x;
	for (int i = 0; i < 2; ++i) {
		acc[i].init();
		scanf("%lf", &x);
		acc[i].deposit(x);
		scanf("%lf", &x);
		acc[i].withdraw(x);
	}

	return 0;
}