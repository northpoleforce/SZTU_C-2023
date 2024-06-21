#include <bits/stdc++.h>

using namespace std;

class Applicance {
protected:
	int id, power;
public:
	Applicance(int ii, int po):
		id(ii), power(po) {}
	void print() {
		printf("编号%d--功率%dW", id, power);
	}
};
class Fan: virtual public Applicance {
protected:
	int windway, windpower;
public:
	Fan(int ii, int po, int ww, int wp):
		Applicance(ii, po), windway(ww), windpower(wp) {}
	void switch_windway(int x) {
		windway = x;
	}
	void switch_windpower(int x) {
		windpower = x;
	}
};
class Weter: virtual public Applicance {
protected:
	float realv, maxv;
public:
	Weter(int ii, int po, int rv, int mv):
		Applicance(ii, po), realv(rv), maxv(mv) {}
	int warn() {
		if (realv < maxv*0.1) return 3;
		if (realv < maxv*0.5) return 2;
		return 1;
	}
};
class Wetfan: public Fan, public Weter {
private:
	int mode;
public:
	Wetfan(int ii, int po, int ww, int wp, float rv, float mv, int mo):
		Applicance(ii, po), Fan(ii, po, ww, wp), Weter(ii, po, rv, mv), mode(mo) {}
	void switch_mode(int x) {
		mode = x;
		if (x == 1) {
			switch_windway(0);
			switch_windpower(1);
		}
		if (x == 2) {
			switch_windway(1);
			switch_windpower(2);
		}
		if (x == 3) {
			switch_windway(1);
			switch_windpower(3);
		}
	}
	friend ostream& operator << (ostream& out, Wetfan &t) {
		cout << "加湿风扇--档位" << t.mode << "\n";
		printf("编号%d--功率%dW\n", t.id, t.power);
		if (t.windway == 0) cout << "定向吹风";
		else cout << "旋转吹风";
		cout << "--";
		printf("风力%d级\n", t.windpower);
		int info = t.warn();
		printf("实际水容量%.0f升--", t.realv);
		if (info == 1) printf("水量正常\n");
		if (info == 2) printf("水量偏低\n");
		if (info == 3) printf("水量不足\n");
		return cout;
	}
};


int main() {
	int t; cin >> t;
	int id, power;
	int windway, windpower;
	float realv, maxv;
	int mode, new_mode;
	while (t--) {
		cin >> id >> power >>  windway >> windpower >> realv >> maxv >> mode;
		cin >> new_mode;
		Wetfan wf(id, power, windway, windpower, realv, maxv, mode);
		wf.switch_mode(new_mode);
		cout << wf;
	}

	return 0;
}