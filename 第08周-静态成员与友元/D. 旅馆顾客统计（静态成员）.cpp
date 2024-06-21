#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Hotel
{
private:
    static int totalCustNum; // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent; // 每个顾客的房租
    char *customerName; // 顾客姓名
    int customerId; // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(char* customer);
    ~Hotel(); //记得delete customerName
    void Display(); //相应输出顾客姓名、顾客编号、总人数、总收入
    static void setrent(float r);
};

int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;
float Hotel::rent = 0;

void Hotel::setrent(float r) {
	rent = r;
}
Hotel::Hotel(char* customer) {
	++totalCustNum;
	customerId = 20150000+totalCustNum;
	customerName = new char[100];
	strcpy(customerName, customer);
	totalEarning += rent;
}
Hotel::~Hotel() {
	delete customerName;
}
void Hotel::Display() {
	printf("%s %d %d %.0f\n", customerName, customerId, totalCustNum, totalEarning);
}

int main() {
	float rent; cin >> rent;
	Hotel::setrent(rent);
	// float Hotel::rent = rent;
	char na[100];
	while (cin >> na) {
		if (na[0] ==  '0') break;
		Hotel a(na);
		a.Display();
	}

    return 0;
}