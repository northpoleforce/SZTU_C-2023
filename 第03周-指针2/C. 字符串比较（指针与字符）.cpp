#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

int judge(char* a, char* b) {
	if (strlen(a) > strlen(b)) return 1;
	if (strlen(b) > strlen(a)) return -1;
	int len = strlen(a), res = 0;
	for (int i = 0; i < len; ++i) {
		if (*(a+i) > *(b+i))
			res++;
		if (*(a+i) < *(b+i))
			res--;
	}
	if (res > 0) return 1;
	if (res == 0) return 0;
	return -1;
}

int main() {
	int t; cin >> t;
	char a[30], b[30];
	while (t--) {
		cin >> a >> b;
		cout << judge(a, b) << "\n";
	}

	return 0;
}