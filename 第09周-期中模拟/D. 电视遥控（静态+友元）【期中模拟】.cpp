#include <bits/stdc++.h>

#define ll long long

using namespace std;

class tv {
private:
	int id, chn, vol, mode;
	static int tvn, dvdn;
public:
	tv() {}
	tv(int c, int v, int m) {
		id = c;
		chn = c;
		vol = v;
		mode = m;
		tvn++;
	}
	void show() {
		printf("第%d号电视机--%s模式--频道%d--音量%d\n", id, mode == 1?"TV":"DVD", chn, vol);
	}
	friend void swit(tv &t, int m, int v, int c);
	friend int get_tv();
	friend int get_dvd();
};

int tv::tvn = 0;
int tv::dvdn = 0;

void swit(tv &t, int m, int v, int c) {
	if (t.mode == 1 && m == 2) {
		t.tvn--;
		t.dvdn++;
	}
	if (t.mode == 2 && m == 1) {
		t.dvdn--;
		t.tvn++;
	}
	t.chn = c;
	t.mode = m;
	if (t.mode == 2) t.chn = 99;
	t.vol += v; t.vol = max(0, t.vol); t.vol = min(t.vol, 100);
	t.show();
}
int get_tv() { return tv::tvn; }
int get_dvd() { return tv::dvdn; }

int main() {
	int n; scanf("%d", &n);
	tv* telev = new tv[n+1];
	for (int i = 1; i <= n; ++i) {
		telev[i] = tv(i, 50, 1);
	}
	int t; scanf("%d", &t);
	int i, k, x, v;
	while (t--) {
		scanf("%d%d%d%d", &i, &k, &x, &v);
		swit(telev[i], k, v, x);
	}
	printf("播放电视的电视机数量为%d\n", get_tv());
	printf("播放DVD的电视机数量为%d", get_dvd());

	return 0;
}