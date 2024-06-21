#include <bits/stdc++.h>

using namespace std;

class Vehicle
{ 
protected:
     string no; //编号
public:
	Vehicle(string id): no(id) {}
    virtual void display()=0; //应收费用
};

class Car: public Vehicle {
private:
	int passager, weight;
public:
	Car(string id, int pa, int we): Vehicle(id), passager(pa), weight(we) {}
	virtual void display() {
		cout << no << " ";
		cout << passager*8+weight*2 << "\n";
	}
};
class Truck: public Vehicle {
private:
	int weight;
public:
	Truck(string id, int we): Vehicle(id), weight(we) {}
	virtual void display() {
		cout << no << " ";
		cout << weight*5 << "\n";
	}
};
class Bus: public Vehicle {
private:
	int passager;
public:
	Bus(string id, int pa): Vehicle(id), passager(pa) {}
	virtual void display() {
		cout << no << " ";
		cout << passager*30 << "\n";
	}
};
void print(Vehicle *p) {
	p->display();
}

int main() {
	int t; cin >> t;
	string id;
	int type, weight, passager;
	Vehicle *p;
	while (t--) {
		cin >> type >> id;
		if (type == 1) {
			cin >> passager >> weight;
			Car car(id, passager, weight);
			p = &car;
			p->display();
		}
		if (type == 2) {
			cin >> weight;
			Truck truck(id, weight);
			p = &truck;
			p->display();
		}
		if (type == 3) {
			cin >> passager;
			Bus bus(id, passager);
			p = &bus;
			p->display();
		}
	}

	return 0;
}