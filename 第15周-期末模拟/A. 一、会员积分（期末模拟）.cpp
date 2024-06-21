#include <iostream>

using namespace std;


// 普通会员类
class Member
{
protected:
	string name;
	int id, score;
public:
	Member(int ii, string na, int ss):
		id(ii), name(na), score(ss) {}
	virtual void print() {
		printf("普通会员%d--", id);
		cout << name;
		printf("--%d\n", score);
	}
	virtual void add(int m) { score += m; }
	virtual int exchange(int m) {
		score -= m / 100 * 100;
		return m / 100;
	}
	// ....代码自行编写
};

// 贵宾会员类
class VIP : public Member
{
private:
	int add_rate, exchange_rate;
public:
	VIP(int ii, string na, int ss, int ar, int er):
		Member(ii, na, ss), add_rate(ar), exchange_rate(er) {}
	virtual void print() {
		printf("贵宾会员%d--", id);
		cout << name;
		printf("--%d\n", score);
	}
	virtual void add(int m) { score += add_rate*m; }
	virtual int exchange(int m) {
		score -= m / exchange_rate * exchange_rate;
		return m / exchange_rate;
	}
	// ....代码自行编写
};

int main()
{
	// 创建一个基类对象指针
	Member* pm;
	// ....其他变量自行编写

	// 输入数据，创建普通会员对象mm
	// 使用指针pm执行以下操作：
	// 1、pm指向普通会员对象mm
	// 2、输入数据，通过pm执行积分累加和积分兑换
	// 3、通过pm调用打印方法输出
	int id, score;
	string name;
	cin >> id >> name >> score;
	int m1, m2;
	cin >> m1 >> m2;
	Member mm(id, name, score);
	pm = &mm;
	pm->add(m1); pm->exchange(m2);
	pm->print();


	// 输入数据，创建贵宾会员对象vv
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
	// 2、输入数据，通过pm执行积分累加和积分兑换
	// 3、通过pm调用打印方法输出

	int add_rate, exchage_rate;
	cin >> id >> name >> score >> add_rate >> exchage_rate;
	cin >> m1 >> m2;
	VIP vv(id, name, score, add_rate, exchage_rate);
	pm = &vv;
	pm->add(m1); pm->exchange(m2);
	pm->print();

	return 0;
}