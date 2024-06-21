#include <iostream>

using namespace std;

class Music {
private:
	string name;
	int type, fee, status;
public:
	Music(int ty, string na, int fe, int st): type(ty), name(na), fee(fe), status(st) {}
	void print() {
		if (type == 1) cout << "黑胶片";
		if (type == 2) cout << "CD";
		if (type == 3) cout << "VCD";
		if (type == 4) cout << "DVD";
		cout << "[" << name << "]";
		if (status) cout << "已出租\n";
		else cout << "未出租\n";
	}
	void calc(int days) {
		if (status) cout << "当前租金为" << days * fee << "\n";
		else cout << "未产生租金" << "\n";
	}
};

int main()
{
	int n; cin >> n;
	int type, fee, status;
	string name;
	int cmd;
	while (n--) {
		cin >> type >> name >> fee >> status;
		cin >> cmd;
		Music m(type, name, fee, status);
		m.print();
		if (cmd) m.calc(cmd);
	}
}