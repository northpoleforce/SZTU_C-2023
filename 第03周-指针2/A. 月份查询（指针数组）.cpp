#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

int main() {
	char** str = new char*[20];
	str[1] = "January";
	str[2] = "February";
	str[3] = "March";
	str[4] = "April";
	str[5] = "May";
	str[6] = "June";
	str[7] = "July";
	str[8] = "Aguest";
	str[9] = "September";
	str[10] = "October";
	str[11] = "November";
	str[12] = "December";
	int t, x; cin >> t;
	while (t--) {
		cin >> x;
		if (1 <= x && x <= 12)
			cout << str[x] << "\n";
		else
			cout << "error\n";
	}

	return 0;
}