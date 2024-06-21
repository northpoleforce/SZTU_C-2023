#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

const int maxn = 2e5+5;
const int maxnum = 1e5;


void find(int *num,int n,int &minIndex,int &maxIndex){
	minIndex = maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (num[i] < num[minIndex]) {
			minIndex = i;
		}
		if (num[i] > num[maxIndex]) {
			maxIndex = i;
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int* num = new int[n];
		for (int i = 0; i < n; ++i) cin >> num[i];
		int minIndex, maxIndex;
		find(num, n, minIndex, maxIndex);
		cout << "min=" << num[minIndex] << " minindex=" << minIndex << "\n";
		cout << "max=" << num[maxIndex] << " maxindex=" << maxIndex << "\n\n";
	}

	return 0;
}