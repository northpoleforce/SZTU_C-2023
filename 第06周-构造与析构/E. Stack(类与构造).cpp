#include <bits/stdc++.h>

using namespace std;

class CStack {
private:
	int *a;
	int size;
	int top;
public:
	CStack();
	~CStack();
	CStack(int s);
	int get(int index);
	void push(int n);
	int isEmpty();
	int isFull();
	int pop();
};
CStack::CStack() {
	size = 10;
	top = 0;
	a = new int[size];
	printf("Constructor.\n");
}
CStack::CStack(int s) {
	size = s;
	top = 0;
	a = new int[s];
	printf("Constructor.\n");
}
CStack::~CStack() {
	delete[] a;
	printf("Destructor.\n");
}
int CStack::get(int index) {
	return a[top-index];
}
void CStack::push(int n) {
	a[top++] = n;
}
int CStack::isEmpty() {
	return top==0;
}
int CStack::isFull() {
	return top == size;
}
int CStack::pop() {
	return a[--top];
}

int main() {
	int t; scanf("%d", &t);
	int n, x;
	while (t--) {
		scanf("%d", &n);
		CStack sta = CStack(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			sta.push(x);
		}
		printf("%d", sta.pop());
		for (int i = 1; i < n; ++i)
			printf(" %d", sta.pop());
		printf("\n");
	}

	return 0;
}