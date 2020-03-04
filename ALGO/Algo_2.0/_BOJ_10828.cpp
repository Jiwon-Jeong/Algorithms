#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Stack {
	int data[10000];
	int size;

	Stack() {
		size = 0;
	}
	void push(int n) {
		data[size] = n;
		size += 1;
	}
	bool empty() {
		if (size == 0) return true;
		else return false;
	}

	int pop() {
		if (empty())
			return -1;
		else {
			size -= 1;
			return data[size];
		}
	}

	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return data[size - 1];
		}
	}

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	Stack s;

	while (n--) {
		string op;
		cin >> op;
		if (op == "push") {
			int a;
			cin >> a;
			s.push(a);
		}
		else if (op == "pop") {
			cout << (s.empty() ? -1 : s.pop()) << '\n';
		}
		else if (op == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}
		else if (op == "size") {
			cout << s.size << '\n';
		}
		else if (op == "empty") {
			cout << (s.empty() ? 1 : 0) << '\n';
		}
	}
	return 0;
}