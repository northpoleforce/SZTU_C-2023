#include <iostream>

using namespace std;

const int hmax = 26;
class Info { //联系人，用一个链表结点表示
	string name; //姓名
	int phoneNo; //电话
public:
	Info* next;  //指向下一个结点
	Info(string tn = "no name", int pno = 0)
	{
		name = tn;
		phoneNo = pno;
		next = NULL;
	}
	void Print()
	{
		cout << name << "--" << phoneNo << endl;
	}
	int get_pno() { return phoneNo; }
	string get_name() { return name; }
	void set(string tn, int pno) {
		name = tn;
		phoneNo = pno;
	}
	//属性的get和set方法....自行定义
};

class PhoneBook {//组链表方式实现通讯录
	//....自行增加一些操作
	//提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
public:
	Info Table[hmax]; //链表头结点数组，对应26个大写字母
	//以下定义五个操作：输入Input、打印Print、插入、合并、查找
	//具体操作看前面说明
	void Insert(string name, int num) {
		int idx = name[0] - 'A';
		Info* tp = &Table[idx];
		if (tp->get_pno() == 0) tp->set(name, num);
		else {
			Info* p = new Info(Table[idx].get_name(), Table[idx].get_pno());
			p->next = Table[idx].next;
			Table[idx].set(name, num);
			Table[idx].next = p;
		}
		
	}
	void Input() {
		int n; cin >> n;
		string name; int num;
		for (int i = 0; i < n; ++i) {
			cin >> name >> num;
			Insert(name, num);
		}
	}
	void Print() {
		for (int i = 0; i < hmax; ++i)
			if (Table[i].get_pno() != 0) {
				cout << (char)(i + 'A') << "--";
				Info* p = &Table[i];
				cout << p->get_name() << "." << p->get_pno() << "--";
				while (p->next != NULL) {
					p = p->next;
					cout << p->get_name() << "." << p->get_pno() << "--";
				}
				cout << "\n";
			}
	}
	Info* operator () (const string na) {
		Info* p = &Table[na[0] - 'A'];
		while (1) {
			if (p->get_name() == na) return p;
			if (p->next == NULL) return NULL;
			p = p->next;
		}
	}
	Info* find(const string na) {
		Info* p = &Table[na[0] - 'A'];
		while (1) {
			if (p->get_name() == na) return p;
			if (p->next == NULL) return NULL;
			p = p->next;
		}
	}
	void operator += (Info& t) {
		Info* tp = find(t.get_name());
		if (tp == NULL) Insert(t.get_name(), t.get_pno());
		else tp->set(t.get_name(), t.get_pno());
	}
	PhoneBook operator + (PhoneBook& b) {
		for (int i = 0; i < hmax; ++i) {
			Info* p = &b.Table[i];
			Info* tp;
			while (1) {
				if (p->get_pno() == 0) break;
				tp = find(p->get_name());
				if (tp == NULL) Insert(p->get_name(), p->get_pno());
				else tp->set(p->get_name(), p->get_pno());
				if (p->next == NULL) break;
				p = p->next;
			}
		}
		return *this;
	}
};
//...PhoneBook类成员函数，类外实现，自行编写


//----主函数----
int main()
{
	string tname;
	int i, tno;
	Info* p;

	PhoneBook pb;
	pb.Input(); //接收输入数据，初始化第一个通讯录
	//pb.Print();
	//两次姓名查找
	for (i = 0; i < 2; i++)
	{
		cin >> tname;
		p = pb(tname); //调用()运算符，实现查找
		if (p) p->Print(); //查找成功，输出联系人信息
		else cout << "查找失败" << endl; //查找失败，输出提示信息
	}
	//一次插入
	cin >> tname >> tno;
	Info temp(tname, tno);
	pb += temp; //调用+=运算符，实现插入新联系人
	//pb.Print();

	//通讯录合并
	PhoneBook pc;
	pc.Input(); //初始化第二个通讯录
	pb = pb + pc; //调用+运算符，实现合并

	pb.Print(); //输出所有操作后的通讯录

	return 0;
}