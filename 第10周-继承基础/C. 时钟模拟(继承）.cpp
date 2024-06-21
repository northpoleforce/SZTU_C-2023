#include <bits/stdc++.h>

using namespace std;

class Count {
protected:
	int value;
public:
	Count() {}
	Count(int v0): value(v0) {}
	void increment() { ++value; }
};

class ForCount: public Count {
protected:
	int minValue, maxValue;
public:
	// ForCount(): Count(0), minValue(0), maxValue(0) {}
	ForCount() {};
	ForCount(int v0, int minx, int maxx): Count(v0), minValue(minx), maxValue(maxx) {}
	int increment(int s) {
		int res = 0;
		for (int i = 1; i <= s; ++i) {
			Count::increment();
			if (value > maxValue) {
				value = minValue;
				++res;
			}
		}
		// printf("res=%d\n", res);
		return res;
	}
	void print() {
		printf("%d", value);
	}
};

class Clock: public ForCount {
private:
	ForCount hour, minute, second;
public:
	Clock(int h, int m, int s):
		hour(h, 0, 23), minute(m, 0, 59), second(s, 0, 59) {}
	void _time(int s) {
		int m = second.increment(s);
		int h = minute.increment(m);
		hour.increment(h);
	}
	void print() {
		hour.print();
		printf(":");
		minute.print();
		printf(":");
		second.print();
		printf("\n");
	}
};

int main() {
	int t; scanf("%d", &t);
	int h, m, s, ss;
	while (t--) {
		scanf("%d%d%d", &h, &m, &s);
		Clock c(h, m, s);
		scanf("%d", &ss);
		c._time(ss);
		c.print();
	}

	return 0;
}