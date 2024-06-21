#include <bits/stdc++.h>

using namespace std;

class vip_card {
protected:
	int vip_id, vip_score;
public:
	vip_card(int id, int sc): vip_id(id), vip_score(sc) {}
	void print() {
		cout << vip_id << " " << vip_score << "\n";
	}
};
class credit_card {
protected:
	int credit_id;
	float limit, credit_score;
	string name;
	float bill;
public:
	credit_card(int id, string na, int li, int sc, float bi):
		credit_id(id), name(na), limit(li), credit_score(sc), bill(bi) {}
	void print() {
		cout << credit_id << " " << name << " ";
		printf("%.1f", bill);
		printf(" %.0f", credit_score);
	}
};
class vip_credit: public vip_card, public credit_card {
public:
	vip_credit(int vid, int cid, string na, int li):
		vip_card(vid, 0), credit_card(cid, na, li, 0, 0) {}
	void add_score(float m) {
		if (m > limit) return;
		bill += m; limit -= m;
		credit_score += m;
		vip_score += m;
	}
	void comsume(float m) {
		if (m > limit) return;
		bill += m; limit -= m;
		credit_score += m;
	}
	void back(float m) {
		credit_score -= m;
		bill -= m;
	}
	void exchange(float m) {
		credit_score -= m;
		vip_score += m/2;
	}
	void print() {
		vip_card::print();
		credit_card::print();
	}
};

int main() {
	int vip_id, credit_id, limit;
	string name;
	cin >> vip_id >> credit_id >> name >> limit;
	vip_credit vc(vip_id, credit_id, name, limit);
	int n; cin >> n;
	char cmd; float m;
	while (n--) {
		cin >> cmd >> m;
		if (cmd == 'o') {
			vc.add_score(m);
		}
		if (cmd == 'c') {
			vc.comsume(m);
		}
		if (cmd == 'q') {
			vc.back(m);
		}
		if (cmd == 't') {
			vc.exchange(m);
		}
	}
	vc.print();

	return 0;
}