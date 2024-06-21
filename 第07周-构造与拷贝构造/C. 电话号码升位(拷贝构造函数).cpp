#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

class number {
private:
	char* s;
public:
	number(char ss[]) {
		s = new char[8];
		strcpy(s, ss);
	}
	~number() {
		delete[] s;
	}
	number(number &ss) {
		s = new char[9];
		strcpy(s+1, ss.s);
		if ('2' <= ss.s[0] && ss.s[0] <= '4')
			s[0] = '8';
		else
			s[0] = '2';
	}
	void print() {
		printf("%s\n", s);
	}
};

bool check(char s[]) {
	int len = strlen(s);
	if (len != 7) return 0;
	if (s[0] == '0' || s[0] == '1' || s[0] == '9') return 0;
	for (int i = 0; i < len; ++i)
		if (s[i] < '0' || s[i] > '9') return 0;
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	char s[100];
	while (t--) {
		scanf("%s", s);
		if (check(s)) {
			number num0(s);
			number num(num0);
			num.print();
		} else {
			printf("Illegal phone number\n");
		}
	}

	return 0;
}