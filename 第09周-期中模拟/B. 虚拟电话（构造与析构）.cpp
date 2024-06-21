#include <bits/stdc++.h>

#define ll long long

using namespace std;

class phone_number {
private:
	string number;
	char type;
public:
	phone_number(string num, char ty) {
		number = num;
		type = ty;
	}
	// void _set(string _num, char ty) {
	// 	number = _num;
	// 	type = ty;
	// }
	string get_number() { return number; }
	char get_type() { return type; }
};

class phone {
private:
	phone_number* pn;
	bool status;
	string name;
public:
	phone(string num, char ty, bool st, string na) {
		name = na;
		// pn = new phone_number();
		// phone_number pn(num, ty);
		pn = new phone_number(num, ty);
		status = st;
		cout << pn->get_number() << " constructed.\n";
	}
	~phone() {
		cout << pn->get_number() << " destructed.\n";
		delete pn;
	}
	string get_num() { return pn->get_number(); }
	char get_ty() { return pn->get_type(); }
	bool get_st() { return status; }
	string get_na() { return name; }
};

int main() {
	char num[30], type[5], na[30];
	bool st;
	phone** ph = new phone*[3];
	for (int i = 0; i < 3; ++i) {
		cin >> num >> type >> st >> na;
		ph[i] = new phone(num, type[0], st, na);
	}
	int t; scanf("%d", &t);
	bool ok;
	while (t--) {
		scanf("%s", num);
		ok = 0;
		for (int i = 0; i < 3; ++i)
			if (ph[i]->get_num() == num) {
				ok = 1;
				cout << "Phone=" << num;
				printf("--Type=%c", ph[i]->get_ty());
				if (ph[i]->get_st())
					printf("--State=use");
				else
					printf("--State=unuse");
				cout << "--Owner=" << ph[i]->get_na() << "\n";
				break;
			}
		if (!ok) cout << "wrong number.\n";
	}
	// delete[] ph;
	for (int i = 2; i >= 0; --i)
		delete ph[i];
	return 0;
}