#include <iostream>

using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << 2*(a*b+a*c+b*c) << endl;
	}

	return 0;
}