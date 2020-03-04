#include <iostream>
#include <vector>
#include <string>

#define MAX_SIZE 1000000

using namespace std;
int size;


/* 쿼드 트리 뒤집기 문제를 해결하는 분할 정복 알고리즘 */
string reserve(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reserve(it);
	string upperRight = reserve(it);
	string lowerLeft = reserve(it);
	string lowerRight = reserve(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	// 입력
	int C;
	cin >> C;
	while (C-- > 0) {
		string input;
		cin >> input;
		string::iterator it = input.begin();
		cout << reserve(it) << endl;
	}
	return 0;
}