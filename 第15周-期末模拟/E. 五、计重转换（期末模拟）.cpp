#include <bits/stdc++.h>

using namespace std;

class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
private:
	int jin, liang, qian;
public:
	CN(int g, int ji, int li, int qi, char ki[]):
		Weight(ki, g), jin(ji), liang(li), qian(qi) {}
	void Convert(int g) {
		jin = g/500; g %= 500;
		liang = g/50; g %= 50;
		qian = g/5; g %= 5;
		gram = g;
	}
	void print(ostream& out) {
		printf("中国计重:%d斤%d两%d钱%d克\n", jin, liang, qian, gram);
	}
	CN& operator = (EN &t);
	// ....类定义自行编写
};

// 英国计重
class EN : public Weight
{
private:
	int pound, ounce, dram;
public:
	EN(int g, int po, int ou, int dr, char ki[]):
		Weight(ki, g), pound(po), ounce(ou), dram(dr) {}
	void Convert(int g) {
		pound = g/512; g %= 512;
		ounce = g/32; g %= 32;
		dram = g/2; g %=2;
		gram = g;
	}
	void print(ostream& out) {
		printf("英国计重:%d磅%d盎司%d打兰%d克\n", pound, ounce, dram, gram);
	}
	int get_pound() { return pound; }
	int get_ounce() { return ounce; }
	int get_dram() { return dram; }
	int get_gram() { return gram; }
	// ....类定义自行编写
};

CN& CN::operator = (EN &t) {
	int gg = t.get_pound()*512+t.get_ounce()*32+t.get_dram()*2+t.get_gram();
	// int gg = t.gram;
	this->Convert(gg);
	return *this;
	// cout << gg << "=gg\n";
	// int jin = gg/500; gg %= 500;
	// int liang = gg/50; gg %= 50;
	// int qian = gg/5; gg %= 5;
	// int gram = gg;
	// CN res(gram, jin, liang, qian, "中国计重");
	// return res;
}

ostream& operator << (ostream& out, Weight &t) {
	t.print(out);
	return cout;
}

// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}