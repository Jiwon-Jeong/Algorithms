#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string p) {
	stack<char> s;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')
			s.push(p[i]);
		else {
			if (s.empty()) return false;
			s.pop();
		}
	}
	return true;
}

string go(string p) {
	if (p == "") return "";
	// �������� ���ڿ��� �и�
	string answer = "", u = "", v = "";
	int l = 0, r = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') l++;
		else r++;
		if (l == r) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
	// u�� �ùٸ� ��ȣ ���ڿ��̸�
	if (check(u)) {
		answer += u + go(v);
	}
	// u�� �ùٸ� ��ȣ ���ڿ��� �ƴϸ�
	else {
		answer += "(" + go(v) + ")";
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(') answer += ')';
			else answer += '(';
		}
	}
	return answer;
}

string solution(string p) {
	if (check(p)) return p;
	return go(p);
}