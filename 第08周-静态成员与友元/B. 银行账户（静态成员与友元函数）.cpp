#include <iostream>
#include <cmath>

using namespace std;

class Account
{
private:
    static float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account(string ac, string na, float ba);
    void setAccount(string ac, string na, float ba);
    ~Account();
    void deposit(float amount); // 存款
    void withdraw(float amount); // 取款
    float getBalance(); // 获取账户余额
    void show(); // 显示账户所有基本信息
    static float getCount(); // 获取账户总余额
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate(); // 获取利率
    friend void update(Account& a);
};
float Account::count = 0;
float Account::interestRate = 0;

Account::Account(string ac, string na, float ba) {
    accno = ac;
    accname = na;
    balance = ba;
}
void Account::setInterestRate(float rate) {
    interestRate = rate;
}
void Account::setAccount(string ac, string na, float ba) {
    accno = ac;
    accname = na;
    balance = ba;
}
float Account::getBalance() {
    return balance;
}
float Account::getInterestRate() {
    return interestRate;
}
void Account::show() {
    cout << accno << " " << accname << " ";
}
void update(Account &a) {
    a.balance += a.getBalance()*a.getInterestRate();
    Account::count += a.balance;
    // a.show();
}
void Account::deposit(float amount) {
    balance += amount;
    // show();
}
void Account::withdraw(float amount) {
    balance -= amount;
    Account::count -= amount;
    // show();
}
float Account::getCount() {
    return count;
}


int main() {
    //freopen("test.in", "r", stdin);
    float rate; cin >> rate;
    Account::setInterestRate(rate);
    int n; cin >> n;
    Account** acc = new Account*[n];
    string accno, accname;
    float a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> accno >> accname;
        cin >> a >> b >> c;
        acc[i] = new Account(accno, accname, a);
        // acc[i]->setAccount(accno, accname, 0);
        acc[i]->show();
        acc[i]->deposit(b);
        cout << acc[i]->getBalance() << " ";
        update(*acc[i]);
        cout << acc[i]->getBalance() << " ";
        acc[i]->withdraw(c);
        cout << acc[i]->getBalance() << "\n";
    }
    cout << Account::getCount();
    delete[] acc;
    return 0;
}