#include <bits/stdc++.h>

#define ll long long

using namespace std;

class robot {
private:
	char name[30], ty;
	int hp, atk, dfd, lv;
public:
	robot(char _name[30], char _ty, int _lv) {
		strcpy(name, _name);
		ty = _ty;
		lv = _lv;
		hp = atk = dfd = 5*lv;
		if (ty == 'A') atk = 10*lv;
		else if (ty == 'D') dfd = 10*lv;
		else if (ty == 'H') hp = 50*lv;
	}
	char get_ty() {
		return ty;
	}
	void transform(char _ty) {
		ty = _ty;
		hp = atk = dfd = 5*lv;
		if (ty == 'A') atk = 10*lv;
		else if (ty == 'D') dfd = 10*lv;
		else if (ty == 'H') hp = 50*lv;
	}
	void show() {
		printf("%s--%c--%d--%d--%d--%d\n", name, ty, lv, hp, atk, dfd);
	}
};

bool transform(robot &rb, char ty) {
	if (ty == rb.get_ty()) return 0;
	rb.transform(ty);
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	char name[30], _type[5];
	int lv, cnt = 0;
	while (t--) {
		scanf("%s%s%d", name, _type, &lv);
		robot robot0(name, _type[0], lv);
		scanf("%s", _type);
		cnt += transform(robot0, _type[0]);
		robot0.show();
	}
	printf("The number of robot transform is %d\n", cnt);

	return 0;
}