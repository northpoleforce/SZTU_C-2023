#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;

struct dat {
	string name;
	int wt, s;
} d[5];

int main() {
	cout << "原始工资\n";
	cout << "姓名 年限 工资\n";
	for (int i = 0; i < 5; ++i) {
		cin >> d[i].name >> d[i].wt >> d[i].s;
		cout << d[i].name << " " << d[i].wt << " " << d[i].s << "\n";
		if (d[i].wt >= 30)
			d[i].s += 100;
	}
	cout << "加薪后工资\n";
	cout << "姓名 年限 工资\n";
	for (int i = 0; i < 5; ++i)
		cout << d[i].name << " " << d[i].wt << " " << d[i].s << "\n";


	return 0;
}