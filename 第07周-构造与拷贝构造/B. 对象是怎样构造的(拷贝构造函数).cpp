#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

class cla {
private:
	int x;
public:
	cla() {
		printf("Constructed by default, value = 0\n");
	}
	cla(int n) {
		x = n;
		printf("Constructed using one argument constructor, value = %d\n", x);
	}
	cla(cla &c) {
		x = c.x;
		printf("Constructed using copy constructor, value = %d\n", x);
	}
};

int main() {
	int t; scanf("%d", &t);
	int c, x;
	while (t--) {
		scanf("%d", &c);
		if (c == 0) {
			cla cc;
		}
		if (c == 1) {
			scanf("%d", &x);
			cla cc(x);
		}
		if (c == 2) {
			scanf("%d", &x);
			cla c0(x);
			cla c1(c0);
		}
	}

	return 0;
}