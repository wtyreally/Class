#include<iostream>
#include<stack>
using namespace std;

long fibr(int n,stack<int*>&S) {
	long result=0;
	S.push(new int(n));
	while (S.empty() == false) {
		int* top = S.top();
		S.pop();
		if (*top <= 1) {
			result += 1;
		}
		else {
			S.push(new int(*top- 1));
			S.push(new int(*top-2));
		}
		delete top;
	}
	return result;
}

int main() {
	stack<int*>st;
	cout << " 第8个斐波拉契数是：" << fibr(7,st);
}
