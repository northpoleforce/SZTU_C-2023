#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

struct dat {
	int id;
	char str[3][103];
} d[1000];

int check(dat* a, dat* b) {
	for (int i = 0; i < 3; ++i) {
		int alen = strlen((*a).str[i]);
		int blen = strlen((*b).str[i]);
		int len = min(alen, blen);
		double cnt = 0;
		for (int j = 0; j < len; ++j) {
			if ((*a).str[i][j] == (*b).str[i][j]) cnt++;
			if (cnt >= 0.9*len)
				return i+1;
		}
	}
	return 0;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> d[i].id;
		// cout << d[i].id << "=id\n";
		cin >> d[i].str[0] >> d[i].str[1] >> d[i].str[2];
		// cout << d[i].str[0] << " " << d[i].str[1] << " " << d[i].str[2] << "\n";
	}
	for (int i = 0; i < t; ++i)
		for (int j = i+1; j < t; ++j) {
			int cp = check(&d[i], &d[j]);
			if (cp) {
				cout << d[i].id << " " << d[j].id << " " << cp << "\n";
			}
		}


	return 0;
}