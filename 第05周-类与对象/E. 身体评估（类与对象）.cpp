#include <bits/stdc++.h>

using namespace std;

class person {
private:
	char name[20];
	double height, weight, waistline;
public:
	void init() {
		scanf("%s%lf%lf%lf", name, &height, &weight, &waistline);
	}
	double get_BMI() {
		return weight/height/height;
	}
	double get_bfp() {
		double a = waistline*0.74;
		double b = weight*0.082+34.89;
		return (a-b)/weight;
	}
	void output() {
		printf("%s的BMI指数为%.0lf--体脂率为%.2lf\n", name, get_BMI(), get_bfp());
	}
};


int main() {
	int t; scanf("%d", &t);
	person p;
	while (t--) {
		p.init();
		p.output();
	}

	return 0;
}