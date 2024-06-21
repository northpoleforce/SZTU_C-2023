#include <bits/stdc++.h>

using namespace std;

class cat {
private:
	char name[100];
	int w;
public:
	void init() {
		scanf("%s%d", name, &w);
	}
	int getw() {
		return w;
	}
	void output() {
		printf("%s ", name);
	}
};


int main() {
	int n;
	scanf("%d", &n);
	cat* c = new cat[n];
	for (int i = 0; i < n; ++i)
		c[i].init();
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (c[i].getw() > c[j].getw())
				swap(c[i], c[j]);
	for (int i = 0; i < n; ++i)
		c[i].output();

	return 0;
}