#include <iostream>

using namespace std;

int main() {
	int s = 1, n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		s *= i;
	cout << s << endl;

	return 0;
}